#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<vector<int>, vector<vector<int>>, greater<>> heapMin;
    int N;
    cin >> N;
    if (N == 0) {
        cout << 0;
    }
    else {
        int T;
        int L;
        for (int i = 0; i < N; i++) {
            cin >> T;
            cin >> L;
            heapMin.push({T, L});
        }

        priority_queue<int , vector<int>, greater<>> heapTimeMin;
        int t = heapMin.top()[0];
        int count = 0;
        while (!heapMin.empty()) {
            while (!heapTimeMin.empty() && heapTimeMin.top() == t) {
                heapTimeMin.pop();
            }
            while (!heapMin.empty() && heapMin.top()[0] == t) {
                heapTimeMin.push(heapMin.top()[0] + heapMin.top()[1]);
                heapMin.pop();
            }
            count = max(count, (int)heapTimeMin.size());
            t++;
        }

        cout << count;
    }

    return 0;
}