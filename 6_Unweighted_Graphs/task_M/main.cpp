#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, int> table_number; // Номера столиков гостей
    for (int guest = 1; guest <= N; guest++) {
        table_number[guest] = 0; // 0 - не определён столик, 1, 2 - первый и второй столик соотв
    }

    unordered_map<int, unordered_set<int>> list_of_connections;
    for (int i = 0; i < M; i++) {
        int guest1, guest2;
        cin >> guest1 >> guest2;

        list_of_connections[guest1].insert(guest2);
        list_of_connections[guest2].insert(guest1);
    }

    bool ans = true;
    vector<int> first_table;
    for (int guest = 1; guest <= N; guest++) {
        if (table_number[guest] == 0) {
            queue<int> q;
            q.push(guest);

            table_number[guest] = 1;
            first_table.push_back(guest);

            while (!q.empty()) {
                int current_guest = q.front(); q.pop();

                for (int enemy : list_of_connections[current_guest]) {
                    if (table_number[current_guest] == table_number[enemy]) { // Если у двух неладющих гостей оказался один и тот же столик
                        ans = false; // гостей нельзя рассадить
                        break;
                    }
                    if (table_number[enemy] == 0) { // Если у врага гостя не определён стол, даём ему отличный от текущего гостя стол
                        q.push(enemy);
                        if (table_number[current_guest] == 1) {
                            table_number[enemy] = 2;
                        }
                        else {
                            table_number[enemy] = 1;
                            first_table.push_back(enemy);
                        }
                    }
                }
                if (!ans) {
                    break;
                }
            }
            if (!ans) {
                break;
            }
        }
    }

    if (ans) {
        cout << "YES" << '\n';
        for (int guest : first_table) {
            cout << guest << ' ';
        }
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}