#include <iostream>

using namespace std;

int makeIthBitOne(int x, unsigned int i) {
    return x | 1 << i;
}

int main() {
    int x;
    unsigned int i;
    
    cout << "x = ";
    cin >> x;
    
    cout << "i = ";
    cin >> i;

    cout << "Result: " << makeIthBitOne(x, i) << "\n";

    return 0;
}