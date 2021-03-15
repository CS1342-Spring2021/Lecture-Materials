#include <iostream>

using namespace std;

void PrintReverse(char word[], const int& size);

int main() {
  const int size = 5;
  char example[] = "hello";

  PrintReverse(example, size);

  return 0;
}

void PrintReverse(char word[], const int& size) {
  if (size < 1) return;

  cout << word[size - 1] << endl;
  PrintReverse(word, size - 1);
}

void PrintReverse(char word[], const int& size) {
  if (size < 1) return;

  cout << word[size - 1] << endl;
  PrintReverse(word, size - 1);
}