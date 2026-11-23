#include <iostream>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, unordered_set<int>> list_of_connections;
    for (int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        list_of_connections[node1].insert(node2);
        list_of_connections[node2].insert(node1);
    }

    vector<int> parents_stack;
    vector<int> nodes_stack;

    unordered_map<int, char> nodes_color;
    for (int node = 1; node <= N; node++) {
        nodes_color[node] = 'w';
    }

    nodes_stack.push_back(1);
    parents_stack.push_back(0);
    nodes_color[1] = 'g';

    while (!nodes_stack.empty()) {
        int current_node = nodes_stack.back();

        bool have_neigh = false;
        vector<int> removed;
        for (int next_node : list_of_connections[current_node]) {
            if (nodes_color[next_node] == 'g' && parents_stack.back() != next_node) { // Если мы попадаем в посещённую клетку, ребро будет удалено
                removed.push_back(next_node);
            }
            if (nodes_color[next_node] == 'w') {
                nodes_stack.push_back(next_node);
                parents_stack.push_back(current_node);
                have_neigh = true;

                nodes_color[next_node] = 'g';
                break;
            }
        }

        for (int node : removed) { // Удаляем ребра образующие цикл
            list_of_connections[current_node].erase(node);
            list_of_connections[node].erase(current_node);
        }


        if (!have_neigh) {
            nodes_color[current_node] = 'b';
            nodes_stack.pop_back();
            parents_stack.pop_back();
        }

    }

    set<pair<int, int>> was_output;
    for (int node1 = 1; node1 < N; node1++) {

        for (int node2 : list_of_connections[node1]) {
            pair<int, int> cur_pair1(node1, node2);
            pair<int, int> cur_pair2(node2, node1);
            if (was_output.find(cur_pair1) == was_output.end() && was_output.find(cur_pair2) == was_output.end()) {
                was_output.insert(cur_pair1);
                cout << cur_pair1.first << ' ' << cur_pair1.second << '\n';
            }
        }
    }


    return 0;
}