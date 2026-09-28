#include <iostream>

using namespace std;

bool Good(long long N, int slow, int fast, long long m) {
    return m / slow + m / fast >= N;
}

long long BinarySearch(long long N, int x, int y) {
    int slow, fast;
    slow = x;
    fast = y;

    if (slow < fast) {
        fast = x;
        slow = y;
    }

    long long l = 0;
    long long r = (N - 1) * fast;
    long long m;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (Good(N - 1, slow, fast, m)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    return (r + fast);
}


int main() {
    long long N;
    int x, y;

    cin >> N >> x >> y;

    cout << BinarySearch(N, x, y);

}