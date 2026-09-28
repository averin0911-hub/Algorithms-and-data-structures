#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double F(double x, vector<int> k) {
    return k[0] * x*x*x + k[1] * x*x + k[2] * x + k[3];
}

double BinarySearch(vector<int> k) {
    double l = -1e10;
    double r = 1e10;
    double x;

    double EPS = 1e-6;

    while ((abs(r - l)) >= EPS) {
        x = (l + r) / 2;
        if ((F(x, k) > 0 && k[0] > 0) || (F(x, k) < 0 && k[0] < 0)) {
            r = x;
        }
        else {
            l = x;
        }
    }

    return x;
}

int main() {
    vector<int> k(4);

    int temp;
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        k[i] = temp;
    }

    double x = BinarySearch(k);
    cout << x;



    return 0;
}
