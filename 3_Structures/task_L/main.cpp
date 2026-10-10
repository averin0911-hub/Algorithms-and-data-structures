#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> histograms(N);
    for (int i = 0; i < N; i++) {
        cin >> histograms[i];
    }
    histograms.push_back(0);


    long long max_square = 0;
    vector<vector<long long>> stack;
    for (int i = 0; i < N + 1; i++) {
        while (!stack.empty() && stack.back()[0] > histograms[i]) {
            long long height = stack.back()[0];
            stack.pop_back();

            int left_index = stack.empty() ? -1 : stack.back()[1];
            int width = i - left_index - 1;

            max_square = max(max_square, height * width);
        }
        stack.push_back({histograms[i], i});
    }

    cout << max_square;
    return 0;
}