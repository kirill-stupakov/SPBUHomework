#include <iostream>

using namespace std;

int makeIthBitZero(int x, unsigned int i) {
    const int mask = -1 ^ 1 << i;
    return x & mask;
}

int main() {
    int x;
    unsigned int i;
    
    cout << "x = ";
    cin >> x;
    
    cout << "i = ";
    cin >> i;

    cout << "Result: " << makeIthBitZero(x, i) << "\n";

    return 0;
}
