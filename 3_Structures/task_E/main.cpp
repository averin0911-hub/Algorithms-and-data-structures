#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Deque {

    vector<int> deque;
    int count = 0;

public:
    bool is_empty() {
        return deque.empty();
    }

    void push_front(int x) {
        count++;
        deque.resize(count);
        for (int i = deque.size() - 2; i >= 0; i--) {
            deque[i + 1] = deque[i];
        }

        deque[0] = x;

    }
    void push_back(int n) {
        deque.push_back(n);
        count++;
    }

    int pop_front() {
        if (this->is_empty()) {
            throw exception();
        }
        else {
            int a = deque[0];
            deque.erase(deque.begin());
            count--;
            return a;
        }
    }
    int pop_back() {
        if (this->is_empty()) {
            throw exception();
        }
        else {
            int a = deque[deque.size() - 1];
            deque.pop_back();
            count--;
            return a;
        }

    }

    int front() {
        if (this->is_empty()) {
            throw exception();
        }
        else {
            return deque[0];
        }
    }
    int back() {
        if (this->is_empty()) {
            throw exception();
        }
        else {
            return deque[deque.size() - 1];
        }
    }

    int size() {
        return count;
    }

    void clear() {
        deque.clear();
        count = 0;
    }

};

int main() {
    system("chcp 65001 > nul");
    Deque deque;
    string command;

    while (true) {
        getline(cin, command);

        if (command == "pop_front") {
            try {
                cout << deque.pop_front() << endl;
            }
            catch (const exception&) {
                cout << "error" << endl;
            }
        }

        else if (command == "pop_back") {
            try {
                cout << deque.pop_back() << endl;
            }
            catch (const exception&) {
                cout << "error" << endl;
            }
        }

        else if (command == "front") {
            try {
                cout << deque.front() << endl;
            }
            catch (const exception&) {
                cout << "error" << endl;
            }
        }

        else if (command == "back") {
            try {
                cout << deque.back() << endl;
            }
            catch (const exception&) {
                cout << "error" << endl;
            }
        }

        else if (command == "size") {
            cout << deque.size() << endl;
        }

        else if (command == "clear") {
            deque.clear();
            cout << "ok" << endl;
        }

        else if (command == "exit") {
            cout << "bye";
            break;
        }

        else if (command.substr(0, 10) == "push_front") {
            int n = stoi(command.substr(11)); // Приведение строки к int
            deque.push_front(n);
            cout << "ok" << endl;
        }
        else if (command.substr(0, 9) == "push_back") {
            int n = stoi(command.substr(10)); // Приведение строки к int
            deque.push_back(n);
            cout << "ok" << endl;
        }

        else {
            cout << "incorrect input" << endl;
        }
    }
    return 0;
}