#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, unordered_set<int>> list_of_connections;
    vector<vector<int>> edges; // Нужно чтобы посчитать сколько ребер
    for (int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        edges.push_back({node1, node2});
        list_of_connections[node1].insert(node2);
        list_of_connections[node2].insert(node1);
    }

    if (edges.size() == N - 1) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int current_node = q.front(); q.pop();
            visited.insert(current_node);

            for (int neighbour : list_of_connections[current_node]) {
                if (visited.find(neighbour) == visited.end()) {
                    q.push(neighbour);
                }
            }
        }

        if (visited.size() == N) { // Проверка на связанность
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}