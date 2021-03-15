#include <ctype.h>

#include <iostream>
#include <string>

using namespace std;

bool CheckPassword(string password);

int main() {
  string password;

  do {
    cout << "Enter a password: ";
    getline(cin, password);

  } while (!CheckPassword(password));

  cout << "Correct!" << endl;

  return 0;
}

bool CheckPassword(string password) {
  if (password.length() < 8) return false;

  bool hasAlpha = false;
  bool hasDigit = false;

  // password
  for (int i = 0; i < password.length(); i++) {
    if (isalpha(password.at(i))) {
      hasAlpha = true;
    }
    if (isdigit(password.at(i))) {
      hasDigit = true;
    }
  }

  return hasAlpha && hasDigit;
}