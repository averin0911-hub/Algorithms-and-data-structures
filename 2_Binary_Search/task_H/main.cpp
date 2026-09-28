#include <algorithm>
#include <iostream>

using namespace std;

bool Good(long long m, long long w, long long h, long long n) {
    return (m / w) * (m / h) >= n;
}

long long BinarySearch(long long w, long long h, long long n) {
    long long l = 0;
    long long r = max(w, h) * n;
    long long m;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (Good(m, w, h, n)) {
            r = m;
        }
        else {
            l = m;
        }
    }

    return r;

}

int main() {
    long long w, h, n;
    cin >> w >> h >> n;
    cout << BinarySearch(w, h, n);

    return 0;
}