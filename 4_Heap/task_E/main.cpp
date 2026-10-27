#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

double roundTo(double x, int n) {
    return round(x * pow(10, n)) / pow(10, n);
}

int main() {
    int N;
    cin >> N;
    priority_queue<double, vector<double>, greater<>> heapMin;

    double x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        heapMin.push(x * 0.05);
    }

    double res = 0.0;
    while (heapMin.size() > 1) {
        double summ = 0.0;
        summ += heapMin.top(); heapMin.pop();
        summ += heapMin.top(); heapMin.pop();
        heapMin.push(summ);

        res += summ;
    }

    cout << res;

    return 0;
}