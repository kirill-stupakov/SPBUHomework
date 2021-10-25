#include <iostream>
#include <ctime>

using namespace std;

int** create(int rows, int cols) {
  srand(time(0));

  int **arr = new int* [rows];
  for (int i = 0; i < rows; i++) {
    arr[i] = new int [cols];

    for (int j = 0; j < cols; j++) {
      arr[i][j] = rand() % 40 + 10; 
    }
  }

  return arr;
}

void print(int** arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << arr[i][j] << "  "; 
    }
    cout << "\n";
  }
}

int main() {
  int rows, columns;
  cin >> rows >> columns;

  int** arr = create(rows, columns);
  print(arr, rows, columns);


  return 0;
}