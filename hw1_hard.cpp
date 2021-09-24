
#include <stdexcept>
#include <cmath>
#include <iostream>

using namespace std;

int add(int x, int y) {
    return x + y;
}

int multiply(int x, int y) {
    return x * y;
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
