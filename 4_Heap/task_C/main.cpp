#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> heapMin;

    string op;
    int val;
    while (cin >> op) {
        if (op == "ADD") {
            cin >> val;
            heapMin.push(val);
        }
        else if (op == "CLEAR") {
            while (!heapMin.empty()) {
                heapMin.pop();
            }
        }
        else {
            if (heapMin.empty()) {
                cout << "CANNOT" << '\n';
            }
            else {
                cout << heapMin.top() << '\n';
                heapMin.pop();
            }
        }
    }

    return 0;
}