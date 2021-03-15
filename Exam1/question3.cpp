#include <iostream>

using namespace std;

void PrintReverse(const char word[], const int& size);

int main() {
  const int size = 5;
  char example[] = "hello";

  PrintReverse(example, size);

  return 0;
}

void PrintReverse(const char word[], const int& size) {
  for (int i = size - 1; i >= 0; i--) {
    cout << word[i] << endl;
  }
}