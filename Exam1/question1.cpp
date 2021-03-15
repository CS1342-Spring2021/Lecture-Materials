#include <iostream>
using namespace std;

int main() {
  int highwayNumber;
  cout << "Enter a highway number between 1-99";
  cin >> highwayNumber;

  if (highwayNumber < 1 || highwayNumber > 99) cout << "Out of range";

  switch (highwayNumber % 2) {
    case 0:
      cout << "east/west";
      break;
    case 1:
      cout << "north/south";
  }
  return 0;
}