#include <iostream>

using namespace std;

int unordersCount(int *array, int length) {
  int count = 0;

  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (array[i] > array[j]) {
        count++;
      }
    }
  }

  return count;
}

int main() {
  int length; cin >> length;
  int *array = new int[length];

  for(int i = 0; i < length; i++) {
    cin >> array[i];
  }

  cout << unordersCount(array, length) << "\n";

  return 0;
}