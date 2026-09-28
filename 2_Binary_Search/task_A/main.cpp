#include <iostream>
#include <vector>

using namespace std;

void BinarySearch(vector<int>& A, vector<int>& B) {
    for (int i = 0; i < B.size(); i++) {
        int l = 0;
        int r = A.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (A[m] == B[i]) {
                cout << "YES" << endl;
                break;
            }
            else if (A[m] < B[i]) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        if (l > r) {
            cout << "NO" << endl;
        }
    }
}

void InputArr(vector<int>& arr, int n) {
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> B(K);

    InputArr(A, N);
    InputArr(B, K);

    BinarySearch(A, B);

    return 0;
}