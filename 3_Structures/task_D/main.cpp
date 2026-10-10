#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Queue {
    vector<int> queue;
    int count = 0;

public:
    bool is_empty() {
        return queue.empty();
    }

    void push(int x) {
        queue.push_back(x);
        count += 1;
    }
    int pop() {
        if (this->is_empty()) {
            throw exception();
        }
        else {
            int a = queue[0];
            queue.erase(queue.begin());
            count--;
            return a;
        }
    }
    int front() {
        if (this->is_empty()) {
            throw exception();
        }
        else {
            return queue[0];
        }
    }
    void clear() {
        queue.clear();
        count = 0;
    }
    int size() {
        return count;
    }
};

int main() {
    Queue queue;
    string input;

    while (true) {
        getline(cin, input);
        if (input == "pop") {
            try {
                cout << queue.pop() << endl;
            }
            catch (const exception&) {
                cout << "error" << endl;
            }
        }
        else if (input == "front") {
            try {
                cout << queue.front() << endl;
            }
            catch (const exception&) {
                cout << "error" << endl;
            }
        }
        else if (input == "size") {
            cout << queue.size() << endl;
        }
        else if (input == "clear") {
            queue.clear();
            cout << "ok" << endl;
        }
        else if (input == "exit") {
            cout << "bye";
            break;
        }
        else if (input.substr(0, 4) == "push") {
            int x = stoi(input.substr(5));
            queue.push(x);
            cout << "ok" << endl;
        }
        else {
            cout << "incorrect input" << endl;
        }
    }
    return 0;
}