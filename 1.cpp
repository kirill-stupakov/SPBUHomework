#include <iostream>

using namespace std;

void nthDerivativeOfSin(unsigned int n) {
    cout << n << "'th derivative of sin(x) is ";

    switch (n % 4) {
        case 0:
            cout << "sin(x)\n";
            break;

        case 1:
            cout << "cos(x)\n";
            break;

        case 2:
            cout << "-sin(x)\n";
            break;

        case 3: 
            cout << "-cos(x)\n";
            break;
    }
}

int main() {
    unsigned int n;
    cout << "n = ";
    cin >> n;
    nthDerivativeOfSin(n);

    return 0;
}