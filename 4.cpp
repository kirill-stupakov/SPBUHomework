#include <iostream>

using namespace std;

bool isEven(int n) {
    return ~n & 1;
}

void swap(int& a, int& b) {
    int c = b;
    b = a;
    a = c;
}

int multiplyByEight(int a) {
    return a << 3;
}

int main() {
    int a, b;

    cout << "Type two numbers: ";
    cin >> a >> b;

    cout << a << " is " << (isEven(a) ? "even" : "odd") << "\n";
    cout << b << " is " << (isEven(b) ? "even" : "odd") << "\n";

    swap(a, b);
    cout << "Now a = " << a << " and b = " << b << "\n";

    cout << a << " * 8 = " << multiplyByEight(a) << "\n";
    cout << b << " * 8 = " << multiplyByEight(b) << "\n";
}