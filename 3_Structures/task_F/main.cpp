#include <iostream>
#include <vector>
#include <deque>

using namespace std;



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (K == 1) {
        for (int el : A) {
            cout << el << '\n';
        }
    }
    else {
        deque<int> indexes;
        for (int i = 0; i < K - 1; i++) {
            if (i == 0) {
                indexes.push_back(i);
                continue;
            }
            while (indexes.size() > 0 && A[i] < A[indexes.back()]) {
                indexes.pop_back();
            }
                indexes.push_back(i);
        }


        vector<int> res;
        for (int i = K - 1; i < A.size(); i++) {
            while (indexes.size() > 0 && A[i] < A[indexes.back()]) {
                indexes.pop_back();
            }
            indexes.push_back(i);

            res.push_back(A[indexes.front()]);
            if (indexes.front() == i - K + 1) {
                indexes.pop_front();
            }
        }

        for (int el : res) {
            cout << el << '\n';
        }
    }


    return 0;
}
