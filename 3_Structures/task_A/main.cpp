#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {

    vector<int> stack;
    int count_el = 0;

public:
    bool is_empty() {
        return stack.empty();
    }

    void push_n(int n) {
        stack.push_back(n);
        count_el++;
    }

    int pop() {
        if (this->is_empty()) {
            throw exception();
        }
        else {
            int a = stack[stack.size() - 1];
            stack.pop_back();
            count_el--;
            return a;
        }

    }

    int back() {
        if (this->is_empty()) {
            throw exception();
        }
        else {
            return stack[stack.size() - 1];
        }
    }

    int size() {
        return count_el;
    }

    void clear() {
        stack.clear();
        count_el = 0;
    }

};

int main(){
    system("chcp 65001 > nul");
    Stack st;
    string command;

    while (true) {
        getline(cin, command);

        if (command == "pop") {
            try {
                cout << st.pop() << endl;
            }
            catch (const exception&) {
                cout << "error" << endl;
            }
        }

        else if (command == "back") {
            try {
                cout << st.back() << endl;
            }
            catch (const exception&) {
                cout << "error" << endl;
            }
        }

        else if (command == "size") {
            cout << st.size() << endl;
        }

        else if (command == "clear") {
            st.clear();
            cout << "ok" << endl;
        }

        else if (command == "exit") {
            cout << "bye";
            break;
        }

        else if (command.substr(0, 4) == "push") {
            int n = stoi(command.substr(5)); // Приведение строки к int
            st.push_n(n);
            cout << "ok" << endl;
        }
        else {
            cout << "incorrect input" << endl;
        }
    }

    return 0;
}