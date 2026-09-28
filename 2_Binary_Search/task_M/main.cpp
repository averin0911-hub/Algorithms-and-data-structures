#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Good(int m, vector<int>& L, int N, int K) {
    int summ = 0;

    for (int i = 0; i < N; i++) {
        summ += L[i] / m;
    }

    return summ >= K;
}

int WireLen(vector<int>& L, int N, int K) {
    int l = 0;
    int r = *std::max_element(L.begin(), L.end()) + 1;
    int m;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (Good(m, L, N, K)) {
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

    vector<int> L(N);
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        L[i] = temp;
    }

    cout << WireLen(L, N, K);

    return 0;
}