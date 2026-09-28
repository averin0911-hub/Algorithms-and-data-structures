#include <iostream>

using namespace std;

__int128 F(long long A, long long K, long long d) {
    long long relax = d / K;
    long long work = d - relax;
    return (__int128)A * work;
}

long long DayCount(long long A,long long K,long long B,long long M,long long X) {
    long long l = 0;
    long long r = 9000000000000000000LL;
    long long m;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (F(A, K, m) + F(B, M, m) >= X) {
            r = m;
        }
        else {
            l = m;
        }
    }

    return r;
}

int main() {
    long long A, K, B, M, X;
    cin >> A >> K >> B >> M >> X;

    cout << DayCount(A, K, B, M, X);

    return 0;
}