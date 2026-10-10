#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Count(vector<long long>& arr, long long x) {
    int l = -1;
    int r = static_cast<int>(arr.size());
    int m;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (arr[m] < x) {
            l = m;
        }
        else {
            r = m;
        }
    }

    int start;
    if (r != arr.size() || arr[r] == x) {
        start = r;
    }
    else {
        return 0;
    }


    l = -1;
    r = static_cast<int>(arr.size());

    while (r - l > 1) {
        m = (l + r) / 2;
        if (arr[m] <= x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    int end = l;
    return end - start + 1;
}





void InputArr(vector<long long>& arr, int n) {
    long long temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr[i] = temp;
    }
}






int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    InputArr(A, N);
    sort(A.begin(), A.end());

    int M;
    cin >> M;
    vector<long long> B(M);
    InputArr(B, M);

    for (int i = 0; i < M; i++) {
        cout << Count(A, B[i]) << " ";
    }
    
    return 0;
}