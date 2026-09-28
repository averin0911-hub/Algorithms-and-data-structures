#include <iostream>
#include <vector>

using namespace std;

bool Good(long long m, int K, vector<long long>& A) {
    long long box = A[0];
    int cows_count = 1;

    for (int i = 1; i < A.size(); i++) {
        if (A[i] - box >= m) {
            cows_count++;
            box = A[i];
        }
    }

    return cows_count >= K;
}

long long BinarySearch(int N, int K, vector<long long>& A) {
    long long l = 0;
    long long r = A[A.size() - 1] - A[0] + 1;
    long long m;

    while (r - l > 1) {
        m = (r + l) / 2;
        if (Good(m, K, A)) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l;

}

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> A(N);

    long long temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        A[i] = temp;
    }

    long long d = BinarySearch(N, K, A);
    cout << d;

    return 0;
}