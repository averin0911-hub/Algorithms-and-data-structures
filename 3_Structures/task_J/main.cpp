#include <iostream>
#include <vector>

using namespace std;

int isPossible(vector<float>& test, int N) {
    vector<vector<float>> lenta;
    vector<vector<float>> sklad;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            lenta.push_back({test.back(), test.back()});
            test.pop_back();
            continue;
        }
        lenta.push_back({test.back(), min(test.back(), lenta.back()[1])});
        test.pop_back();
    }

    while (true) {
        if ((!sklad.empty() && !lenta.empty() && sklad.back()[1] <= lenta.back()[1] && sklad.back()[0] == sklad.back()[1])
            || (!sklad.empty() && lenta.empty() && sklad.back()[0] == sklad.back()[1])) {
            sklad.pop_back();
            continue;
        }
        else if ((!sklad.empty() && lenta.empty() && sklad.back()[0] != sklad.back()[1])
            || (sklad.empty() && lenta.empty())) {
            break;
        }

        while (true) {
            if (lenta.back()[0] == lenta.back()[1]) {
                lenta.pop_back();
                break;
            }
            if (sklad.empty()) {
                sklad.push_back({lenta.back()[0], lenta.back()[0]});
            }
            else {
                sklad.push_back({lenta.back()[0], min(lenta.back()[0], sklad.back()[1])});
            }
            lenta.pop_back();
            if (lenta.empty()) {
                break;
            }

        }
    }

    return sklad.empty();
}

int main() {
    int N;
    cin >> N;

    vector<vector<float>> tests(N);

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        tests[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> tests[i][j];
        }
    }

    for (vector<float>& test : tests) {
        cout << isPossible(test, (int)test.size()) << endl;
    }

    return 0;
}