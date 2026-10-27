#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <deque>

using namespace std;

int main() {
    int N, K, P;
    cin >> N >> K >> P;

    priority_queue<vector<int>, vector<vector<int>>, greater<>> heapMin;
    for (int i = 0; i < P; i++) {
        int op;
        cin >> op;
        heapMin.push({i, op});
    }

    int count = 0;
    set<int> pol; // Множество
    while (!heapMin.empty()) {
        if (pol.size() < K) {
            pol.insert(heapMin.top()[1]);
            heapMin.pop();
            count++;
        }
        else if (pol.count(heapMin.top()[1]) == 0) {

            deque<vector<int>> in_pol; // Дек для выбора игрушки, которую нужно поднять с пола (последний эл-т)
            set<vector<int>> set; // Множество для проверки наличия номера игрушки в dq
            vector<vector<int>> out_pol; // Игрушки которых нет на полу

            while (!heapMin.empty()) {
                vector<int> toy = heapMin.top();
                heapMin.pop();
                if (pol.count(toy[1]) == 0) {
                    out_pol.push_back(toy);
                }
                else {
                    if (set.count(toy) == 0) {
                        set.insert(toy);
                        in_pol.push_back(toy);
                    }
                }
            }
            pol.erase(in_pol.back()[1]);

            while (!in_pol.empty()) {
                heapMin.push(in_pol.back()); in_pol.pop_back();
            }
            while (!out_pol.empty()) {
                heapMin.push(out_pol.back()); out_pol.pop_back();
            }

            count++;
        }
        heapMin.pop();
    }

    cout << count;

    return 0;
}