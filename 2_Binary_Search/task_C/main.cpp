#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double F(double x) {
    return sqrt(x) + x * x;
}

double RootSearch(double y) {
    double l = 0;
    double r = y;
    double x = 0.0;

    double EPS = 1e-7;
    while (abs(r - l) > EPS) {
        x = (l + r) / 2;
        if (F(x) <= y) {
            l = x;
        }
        else {
            r = x;
        }
    }
    return x;
}

int main() {
    double C;
    cin >> C;

    double x = RootSearch(C);
    cout << fixed << setprecision(10) << x;

    return 0;
}