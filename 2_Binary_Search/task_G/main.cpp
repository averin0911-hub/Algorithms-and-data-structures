#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Good(long long m, int N, int K, const vector<long long>& A) {
    int summ = 0;
    for (int i = 0; i < N; i++) {
        summ += static_cast<int>(A[i] / m);
        if (summ >= K) {
            return true;
        }
    }

    return false;
}

long long BinarySearch(int N, int K, const vector<long long>& A) {
    long long l = -1;
    long long r = *max_element(A.begin(), A.end()) + 1;
    // begin — закладка на первый элемент.(Возвращает указатель)
    // end — забор (стоп-сигнал) сразу после последнего элемента. (Возвращает Указатель)
    // min_element — ищет от begin до end и возвращает закладку на самый маленький элемент. (Вщзвращает указатель)
    long long m;

    while (r - l > 1) {
        m = (r + l) / 2;
        if (m == 0) {
            l = m;
            continue;
        }
        if (Good(m, N, K, A)) {
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

    cout << BinarySearch(N, K, A);

    return 0;
}