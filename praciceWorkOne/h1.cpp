#include <iostream>

using namespace std;

unsigned long long quadraticTime(int n, int a, int b, int c) {
  unsigned long long ans = 0;

  for (int sumA = 2 * a; sumA <= n; sumA += 2) {
    for (int sumB = b; sumB <= n; sumB += 2) {
      if (c >= n - sumA - sumB) {
        ans++;
      }
    }
  }

  return ans;
}

// Simplify the inner loop
unsigned long long linearTime(int n, int a, int b, int c) {
  unsigned long long ans = 0;

  for (int sumA = 2 * a; sumA <= n - b - c; sumA += 2) {
    ans += (n - sumA - b - c) / 2 + 1;
  }

  return ans;
}

// Simplify one more time
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