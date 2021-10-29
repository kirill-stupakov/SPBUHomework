#include <iostream>

using namespace std;

int findUniqueNumber(int endMarker) {
  int currentNumber;
  cin >> currentNumber;

  int xorSum = 0;

  while (currentNumber != endMarker) {
    xorSum ^= currentNumber;
    cin >> currentNumber;
  }

  return xorSum;
}

int main() {
  cout << findUniqueNumber(0) << "\n";

  return 0;
}