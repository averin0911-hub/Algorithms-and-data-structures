#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> stack;
    int size_stack = 0;
    int last = 0;
    int res = 0;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            stack.push_back(A[i]);
            size_stack++;
            last = A[i];
            continue;
        }

        if (A[i] != last || i == N - 1) {
            int j = size_stack - 1;
            int summ = 0;
            while (j >= 0 && stack[j] == last) {
                summ++;
                j--;
            }
            if (A[i] == last) {
                summ++;
            }
            if (summ >= 3) {
                res += summ;
                while (size_stack > 0 && stack.back() == last) {
                    stack.pop_back();
                    size_stack--;
                }
            }
        }
        stack.push_back(A[i]);
        last = A[i];
        size_stack++;

        if (i == A.size() - 1 && size_stack >= 3 && stack[size_stack - 2] == last) {
            int j = size_stack - 3;
            int summ = 2;
            while (j >= 0 && stack[j] == last) {
                summ++;
                j--;
            }
            if (summ >= 3) {
                res += summ;
            }
        }
    }

    cout << res;
    return 0;
}