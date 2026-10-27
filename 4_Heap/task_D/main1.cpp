#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    priority_queue<int> heapMax;

    string op;
    int val;
    while (cin >> op) {
        if (op == "ADD") {
            cin >> val;
            heapMax.push(val);
        }
        else if (op == "CLEAR") {
            while (!heapMax.empty()) {
                heapMax.pop();
            }
        }
        else {
            if (heapMax.empty()) {
                cout << "CANNOT" << '\n';
            }
            else {
                cout << heapMax.top() << '\n';
                heapMax.pop();
            }
        }
    }

    return 0;
}