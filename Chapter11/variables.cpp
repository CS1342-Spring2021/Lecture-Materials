#include <iostream>

using namespace std;

void functionA() {
  int x = 10;
  int y = 10;
}

int main() {
  functionA();

  int value = 10;
  int *ptr = &value;

  int *ptr = nullptr;

  if (!ptr) {
    cout << "Error";
  } else {
    cout << *ptr;
  }

  int *ptr;

  cout << *ptr << endl;  // segmentation fault

  cout << &value << endl;  // 0x1234
  cout << ptr << endl;     // 0x1234

  cout << *ptr << endl;   // 10
  cout << value << endl;  // 10

  cout << &ptr << endl;  // 0x5432

  return 0;
}