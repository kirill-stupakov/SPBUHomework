#include <iostream>

using namespace std;

unsigned long long constantTime(int n, int a, int b, int c) {
  if (n < 2*a + b + c) {
    return 0;
  }

  unsigned long long U = (n - b - c) / 2;

  return (U - a + 1) - (U + a)*(U - a + 1)/2 + U*(U - a + 1);
}

int main() {
  int n; cin >> n;
  int a, b, c; cin >> a >> b >> c;

  cout << constantTime(n, a, b, c);

  return 0;
}