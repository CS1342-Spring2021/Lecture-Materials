#include <cstring>
#include <iostream>

using namespace std;

bool palindrome_iterative(char word[], int lowerBound, int upperBound) {
  return false;
}

bool palindrome_recursive(char word[], int lowerBound, int upperBound) {
  return false;
}

int main() {
  char example[] = "racecar";
  char example2[] = "palindrome";

  const bool isPalindrome1 =
      palindrome_iterative(example, 0, strlen(example) - 1);
  if (isPalindrome1) {
    cout << example << " is a palindrome" << endl;
  } else {
    cout << example << " is a not palindrome" << endl;
  }

  const bool isPalindrome2 =
      palindrome_iterative(example2, 0, strlen(example2) - 1);
  if (isPalindrome2) {
    cout << example2 << " is a palindrome" << endl;
  } else {
    cout << example2 << " is not a palindrome" << endl;
  }

  return 0;
}