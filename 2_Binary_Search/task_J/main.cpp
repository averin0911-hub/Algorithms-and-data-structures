#include <iostream>

using namespace std;

bool Good(long long m, long long n, long long box_width, long long box_height, long long w, long long h) {
    return (w / (m * 2 + box_width)) * (h / (m * 2 + box_height)) >= n;
}

long long BinarySearch(long long n, long long box_width, long long box_height, long long w, long long h) {
    long long l = 0;
    long long r = max(w, h);
    long long m;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (Good(m, n, box_width, box_height, w, h)) {
            l = m;
        }
        else {
            r = m;
        }
    }

    return l;
}

long long ProtectionThickness(long long n, long long a, long long b, long long w, long long h) { // Толщина защиты (перевод)
    long long res1 = BinarySearch(n, a, b, w, h);
    long long res2 = BinarySearch(n, b, a, w, h);

    return max(res1, res2);
}
int main() {
    long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;

    cout << ProtectionThickness(n, a, b, w, h);
}