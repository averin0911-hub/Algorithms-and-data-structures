#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, vector<int>> list_of_connection;
    for (int i = 0; i < M; i++) {
        int student1, student2;
        cin >> student1 >> student2;

        list_of_connection[student1].push_back(student2);
        list_of_connection[student2].push_back(student1);
    }


    unordered_map<int, int> student_group; // 0 - не определён, 1 - даёт списывать, 2 - нагло списывает
    for (int i = 1; i <= N; i++) {
        student_group[i] = 0;
    }

    bool can_divide = true;
    for (int st_giving = 1; st_giving <= N; st_giving++) { // st_giving - предположительно студент, дающий списать
        if (student_group[st_giving] == 0) {
            student_group[st_giving] = 1;

            queue<int> q;
            q.push(st_giving);

            while (!q.empty()) {
                int current_st = q.front(); q.pop();

                for (int next_st : list_of_connection[current_st]) {
                    if (student_group[next_st] == student_group[current_st]) {
                        can_divide = false;
                        break;
                    }
                    if (student_group[next_st] == 0) {
                        if (student_group[current_st] == 1) {
                            student_group[next_st] = 2;
                        }
                        else {
                            student_group[next_st] = 1;
                        }
                        q.push(next_st);
                    }
                }

                if (!can_divide) {
                    break;
                }
            }

            if (!can_divide) {
                break;
            }

        }
    }

    if (can_divide) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}