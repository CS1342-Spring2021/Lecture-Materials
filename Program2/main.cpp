#include <cctype>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/**
 * Utility Functions
 */
string formatString(const string&, bool isPasscode = false);
void displayMenu();
void handleEncryption();
void handleDecryption();

/**
 * Functions for Encryption / Decryption
 */
int convert(char);
char encryptToken(char, char);
char decryptToken(char, char);
string encrypt(const string&, const string&);
string decrypt(const string&, const string&);

// State of program
enum Options { ENCRYPT = 1, DECRYPT, QUIT };

int main() {
  Options state{ENCRYPT};

  do {
    int selection;
    displayMenu();
    cin >> selection;

    // Clear out trailing \n character after input selection
    cin.ignore();
    cin.clear();

    if (selection < 1 || selection > 3)
      cout << "\nIncorrect Option, Please try again...\n" << endl;
    else {
      state = static_cast<Options>(selection);

      switch (state) {
        case ENCRYPT:
          handleEncryption();
          break;
        case DECRYPT:
          handleDecryption();
          break;
        default:
          cout << "\nGoodbye!" << endl;
      }
    }
  } while (state != QUIT);

  return 0;
}

/**
 * Display Menu with options
 */
void displayMenu() {
  cout << "Please select an option:\n"
          "\t1. Encrypt Message\n"
          "\t2. Decrypt Message\n"
          "\t3. Quit\n"
          "Enter: ";
}

/**
 * Encryption
 * Gathers input, formats strings, performs encryption
 */
void handleEncryption() {
  string passcode, message, ciphertext;

  cout << "\nEnter your passcode: ";
  getline(cin, passcode);
  passcode = formatString(passcode, true);

  cout << "Enter your message: ";
  getline(cin, message);
  message = formatString(message);

  cout << "\nEncrypting your message...\n" << endl;
  ciphertext = encrypt(message, passcode);

  cout << "Passcode: " << passcode << endl;
  cout << "Plaintext: " << message << endl;
  cout << "Ciphertext: " << ciphertext << endl << endl;
}

/**
 * Decryption
 * Gathers input, formats strings, performs decryption
 */
void handleDecryption() {
  string passcode, message, ciphertext;

  cout << "\nEnter your ciphertext: ";
  getline(cin, ciphertext);
  ciphertext = formatString(ciphertext);

  cout << "Enter your passcode: ";
  getline(cin, passcode);
  passcode = formatString(passcode, true);

  cout << "\nDecrypting your message...\n" << endl;
  message = decrypt(ciphertext, passcode);

  cout << "Passcode: " << passcode << endl;
  cout << "Ciphertext: " << ciphertext << endl;
  cout << "Plaintext: " << message << endl << endl;
}

/**
 * Convert string to all caps
 * - Also handle case where string is passcode
 * @param message
 */
string formatString(const string& message, bool isPasscode) {
  string formattedString;
  for (char token : message) {
    // if password, remove non-alpha characters
    if (!isPasscode || isalpha(token))
      formattedString += static_cast<char>(toupper(token));
  }
  return formattedString;
}

/**
 * Converts character to integer (0 - 25)
 * @param token
 * @return
 */
int convert(const char token) { return static_cast<int>(token - 65); }

/**
 * Encrypts character given a code (rotation)
 * @param token
 * @param code
 * @return encrypted character
 */
char encryptToken(const char token, const char code) {
  int tokenNum = convert(token);
  int shift = convert(code);
  // get correct new index of character (0 - 25) using modulo
  int rotation = (tokenNum + shift) % 26;
  return 65 + rotation;  // 65 is 'A'.
}

/**
 * Decrypts character given a code (rotation)
 * @param token
 * @param code
 * @return decrypted character
 */
char decryptToken(const char token, const char code) {
  int tokenNum = convert(token);
  int shift = convert(code);
  // get correct new index of character (0 - 25) using modulo
  int rotation = (26 + tokenNum - shift) %
                 26;     // starting at 26 so modulo is performed correctly
  return 65 + rotation;  // 65 is 'A'.
}

/**
 * Encrypt an uppercase string
 * @param message
 * @param passcode
 * @return
 */
string encrypt(const string& message, const string& passcode) {
  string cipherText{message};
  unsigned int count{0};
  for (char& token : cipherText) {
    if (isalpha(token)) {
      // only increment count if alpha character
      unsigned int codeIndex = count++ % passcode.length();
      token = encryptToken(token, passcode.at(codeIndex));
    }
  }
  return cipherText;
}

/**
 * Decrypt an uppercase string
 * @param cipherText
 * @param passcode
 * @return
 */
string decrypt(const string& cipherText, const string& passcode) {
  string message{cipherText};
  unsigned int count{0};
  for (char& token : message) {
    if (isalpha(token)) {
      // only increment count if alpha character
      unsigned int codeIndex = count++ % passcode.length();
      token = decryptToken(token, passcode.at(codeIndex));
    }
  }
  return message;
}