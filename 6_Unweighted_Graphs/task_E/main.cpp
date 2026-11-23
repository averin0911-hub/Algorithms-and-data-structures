#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, unordered_set<int>> list_of_connections; // Список смежностей
    for (int i = 1; i <= N; i++) { // Заполняем весь список вершинами без соседей, чтобы просмотреть все вершины в дальнейшем
        unordered_set<int> neighbours;
        list_of_connections[i] = neighbours;
    }

    for (int i = 0; i < M; i++) { // Заполняем смежными вершинами
        int node1, node2;
        cin >> node1 >> node2;
        list_of_connections[node1].insert(node2);
        list_of_connections[node2].insert(node1);
    }

    vector<unordered_set<int>> components; // Массив с компонентами связанности
    unordered_set<int> visited;
    for (int node = 1; node <= N; node++) {

        if (visited.find(node) == visited.end()) {
            unordered_set<int> comp;
            comp.insert(node);

            vector<int> stack;
            stack.push_back(node);
            visited.insert(node);

            while (!stack.empty()) {
                int current_node = stack.back();

                bool next_is_find = false;
                for (int next_node : list_of_connections[current_node]) {
                    if (visited.find(next_node) == visited.end()) {
                        stack.push_back(next_node);
                        visited.insert(next_node);
                        next_is_find = true;

                        comp.insert(next_node);
                        break;
                    }
                }

                if (!next_is_find) {
                    stack.pop_back();
                }
            }

            components.push_back(comp);
        }
    }

    cout << components.size() << '\n';
    for (unordered_set<int>& comp : components) {
        cout << comp.size() << '\n';
        for (int node : comp) {
            cout << node << " ";
        }
        cout << '\n';
    }

    return 0;

}