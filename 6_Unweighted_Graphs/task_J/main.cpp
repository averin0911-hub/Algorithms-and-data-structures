#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> list_of_connections;
    for (int i = 1; i <= n; i++) {
        unordered_set<int> set;
        list_of_connections[i] = set;
    }

    for (int i = 0; i < m; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        list_of_connections[node1].insert(node2);
    }



    vector<int> possible_sort;
    int node;
    while (cin >> node) {
        possible_sort.push_back(node);
    }



    unordered_set<int> visited;
    bool is_topology_sort = true;
    for (int node : possible_sort) {
        visited.insert(node);
        for (int neigh : list_of_connections[node]) {
            if (visited.find(neigh) != visited.end()) { // Проверяем делали ли мы следующий шаг ранее
                is_topology_sort = false; // Если это так, то это не топологическая сортировка
                break;
            }
        }

        if (!is_topology_sort) {
            break;
        }
    }

    if (is_topology_sort) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

}