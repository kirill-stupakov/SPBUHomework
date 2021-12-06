#include <iostream>

using namespace std;

double calculatePath(double v, double t) {
    double s1 = v * t;
    double s2 = s1 / 2; 

    return s1 + s2;
}

int main() {
    double v, t;
    
    cout << "Initial velocity: ";
    cin >> v;

    cout << "Time: ";
    cin >> t;

    cout << "S = " << calculatePath(v, t) << "\n";

    return 0;
}