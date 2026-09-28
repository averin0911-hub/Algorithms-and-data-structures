#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;

    int dist() const {
        return x * x + y * y;
    }

    void show() const {
        cout << x << " " << y << endl;
    }
};

void PointsSort(vector<Point>& A) {
    for (int i = 0; i < A.size(); i++) {
        int min_i = i;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j].dist() < A[min_i].dist()) {
                min_i = j;
            }
        }
        Point temp = A[i];
        A[i] = A[min_i];
        A[min_i] = temp;
    }
}

int main() {
    vector<Point> A;
    int size;
    cin >> size;

    int x, y;
    for (int i = 0; i < size; i++) {
        cin >> x >> y;
        Point p;
        p.x = x;
        p.y = y;

        A.push_back(p);
    }

    PointsSort(A);
    for (int i = 0; i < size; i++) {
        A[i].show();
    }

    return 0;
}