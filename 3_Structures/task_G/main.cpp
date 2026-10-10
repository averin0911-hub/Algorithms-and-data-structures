#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vans(N); //vans - вагоны
    for (int i = 0; i < N; i++) {
        cin >> vans[i];
    }

    int waiting = 1;
    int i = 0;

    vector<int> dead_end; //dead end - тупик
    while (true) {
        if (!dead_end.empty()) {
            if (dead_end.back() == waiting) {
                dead_end.pop_back();
                waiting++;
                continue;
            }
        }

        if (i < N) {
            if (vans[i] == waiting) {
                waiting++;
            }
            else {
                dead_end.push_back(vans[i]);
            }
            i++;
        }
        else {
            break;
        }
    }

    if (dead_end.empty()) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}