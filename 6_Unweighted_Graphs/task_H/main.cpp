#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, unordered_set<int>> list_of_connections;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;

            if (x == 1) {
                list_of_connections[i].insert(j);
            }
        }
    }

    int start, finish;
    cin >> start >> finish;

    unordered_set<int> visited;
    unordered_map<int, int> dict_for_path; // (Ребёнок : Родитель)
    queue<int> q;
    q.push(start);
    visited.insert(start);

    bool finish_is_found = false;
    while (!q.empty()) {
        int current_node = q.front(); q.pop();

        if (current_node == finish) {
            finish_is_found = true;
            break;
        }

        for (int neighbour : list_of_connections[current_node]) {
            if (visited.find(neighbour) == visited.end()) {
                visited.insert(neighbour);
                q.push(neighbour);
                dict_for_path[neighbour] = current_node;
            }
        }
    }

    if (finish_is_found) {
        vector<int> reverse_path;

        int current_node = finish;
        while (current_node != start) {
            reverse_path.push_back(current_node);
            current_node = dict_for_path[current_node];
        }
        reverse_path.push_back(start);


        cout << reverse_path.size() - 1 << '\n';
        if (reverse_path.size() - 1 != 0) {
            while (!reverse_path.empty()) {
                cout << reverse_path.back() << " ";
                reverse_path.pop_back();
            }
        }
    }
    else {
        cout << -1 << '\n';
    }
}