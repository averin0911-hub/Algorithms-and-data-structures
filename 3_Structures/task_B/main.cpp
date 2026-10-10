#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector<char> stack;
    vector<char> open_smb = {'(', '[', '{'};
    vector<char> close_smb = {')', ']', '}'};
    string ans = "yes";

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack.push_back(str[i]);
            continue;
        }

        for (int j = 0; j < 3; j++) {
            if (str[i] == close_smb[j]) {
                if (!stack.empty() && stack.back() == open_smb[j]) {
                    stack.pop_back();
                    break;
                }
                else {
                    ans = "no";
                    break;
                }
            }
        }

        if (ans == "no") {
            break;
        }

    }

    if (!stack.empty()) {
        ans = "no";
    }
    cout << ans;

    return 0;
}
