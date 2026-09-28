#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void BinarySearch(const vector<long long>& A, const vector<long long>& B) {
    for (int i = 0; i < B.size(); i++) {
        int l = 0;
        int r = A.size() - 1;

        while (r - l > 1) {
            int m = (l + r) / 2;
            if (A[m] <= B[i]) {
                l = m;
            }
            else {
                r = m;
            }
        }
        if (abs(A[l] - B[i]) < abs(A[r] - B[i]) || abs(A[l] - B[i]) == abs(A[r] - B[i])) {
            cout << A[l] << endl;
        }
        else {
            cout << A[r] << endl;
        }

    }
}

void InputArr(vector<long long>& arr, int n) {
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> A(N);
    vector<long long> B(K);

    InputArr(A, N);
    InputArr(B, K);

    BinarySearch(A, B);

    return 0;
}