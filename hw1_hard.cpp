
#include <stdexcept>
#include <cmath>
#include <iostream>

using namespace std;

int add(unsigned int x, unsigned int y) {
    while (y != 0) {
        unsigned carry = x & y;
        
        x = x ^ y;
        y = carry << 1;
    }

    return x;
}

int multiply(int x, int y) {
    bool needSignFlip = (x < 0) ^ (y < 0);

    x = abs(x);
    y = abs(y);

    unsigned int res = 0;

    while (y != 0) {
        if (y & 1) {
            res = add(res, x);
        }

        x <<= 1;
        y >>= 1;
    }

    if (needSignFlip) {
        res = add(~res, 1);
    }

    return res;
}

double evaluate(int x, int y, char op) {
    switch (op) {
        case '+':
            return x + y;
            
        case '-':
            return x - y;
            
        case '*':
            return multiply(x, y);
            
        case '/':
            if (y == 0) {
                throw invalid_argument("Can't divide by zero!");
            }
            
            return (double)x / y;

        case '%':
            if (y == 0) {
                throw invalid_argument("Can't divide by zero!");
            }

            return x % y;
        
        case '^':
            if (x == 2 && y >= 0) {
                return 1 << y;
            }

            return pow(x, y);
        
        default:
            throw invalid_argument("Invalid operator!");
    }
}

int main() {
    int x, y;
    char c;

    cout << "Operand 1: ";
    cin >> x;

    cout << "Operand 2: ";
    cin >> y;

    cout << "Operator: ";
    cin >> c;

    cout << x << " " << c << " " << y << " = " << evaluate(x, y, c) << "\n";

    return 0;
}
