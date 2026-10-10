#include <iostream>
#include <vector>
#include <string>

using namespace std;

int pop(vector<int>& A) {
    int a = A.back();
    A.pop_back();
    return a;
}

vector<string> split(string s) {
    vector<string> res = {""};

    for (char el : s) {
        if (el == ' ') {
            res.push_back("");
            continue;
        }
        res[res.size() - 1] += el;
    }
    return res;
}

int main() {
    string input;
    getline(cin, input);

    vector<string> A = split(input);
    vector<int> res;

    for (string el : A) {
        if (el.empty()) {
            continue;
        }
        if (el != "+" && el != "-" && el != "*") {
            res.push_back(stoi(el));
        }
        else {
            int b = pop(res);
            int a = pop(res);

            if (el == "+") {
                res.push_back(a + b);
            }
            else if (el == "-") {
                res.push_back(a - b);
            }
            else {
                res.push_back(a * b);
            }
        }
    }
    cout << res.back();

    return 0;
}