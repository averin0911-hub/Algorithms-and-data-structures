#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main() {
    string n;
    getline(cin, n);
    int N = stoi(n);

    string op;
    vector<int> res;
    int j = 0;

    deque<int> left;
    deque<int> right;

    for (int i = 0; i < N; i++) {
        getline(cin, op);
        if (op[0] == '-') {
            res.push_back(left.front());
            left.pop_front();
            if (left.size() < right.size()) {
                left.push_back(right.front());
                right.pop_front();
            }
        }
        else if (op[0] == '+') {
            if (left.empty()) {
                left.push_back(stoi(op.substr(2)));
            }
            else {
                right.push_back(stoi(op.substr(2)));
            }
            if (right.size() > left.size()) {
                left.push_back(right.front());
                right.pop_front();
            }
        }
        else{
            if (left.size() == right.size()) {
                left.push_back(stoi(op.substr(2)));
            }
            else {
                right.push_front(stoi(op.substr(2)));
            }

        }
    }

    for (int el : res) {
        cout << el << '\n';
    }

    return 0;
}
