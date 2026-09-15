#include <iostream>
#include <vector>

using namespace std;

void CountSort(vector<int>& A) {
    int min = A[0], max = A[0];
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }

    vector<int> count(max - min + 1);

    for (int i = 0; i < A.size(); i++) {
        count[A[i] - min]++;
    }

    A.clear();
    for (int i = 0; i < count.size(); i++) {
        for (int j = 0; j < count[i]; j++) {
            A.push_back(i + min);
        }
    }
}

int main() {
    vector<int> A;
    int temp;

    while (cin >> temp) {
        A.push_back(temp);
    }

    CountSort(A);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }

    return 0;
}