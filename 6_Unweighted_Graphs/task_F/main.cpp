#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, unordered_set<int>> list_of_connections;
    unordered_map<int, char> node_color; // Цвета узлов
    for (int i = 0; i < N; i++) {

        unordered_set<int> neighbours;
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                neighbours.insert(j);
            }
        }

        list_of_connections[i] = neighbours;
        node_color[i] = 'w'; // Параллельно красим узлы в белый цвет
    }


    bool cycle_exist = false;
    for (int node = 0; node < N; node++) {
        vector<int> stack;
        stack.push_back(node);
        unordered_set<int> visited;

        node_color[node] = 'g';

        while (!stack.empty()) {
            int current_node = stack.back();


            bool next_find = false;
            for (int next_node : list_of_connections[current_node]) {
                if (node_color[next_node] == 'g') { // Если узел серый, значит мы уже были здесь -> цикл
                    cycle_exist = true;
                    break;
                }
                if (node_color[next_node] == 'w') { // Узел в котором мы не были
                    node_color[next_node] = 'g';
                    next_find = true;
                    stack.push_back(next_node);
                    break;
                }
            }

            if (cycle_exist) {
                break;
            }

            if (!next_find) {
                node_color[current_node] = 'b';
                stack.pop_back();
            }
        }
        if (cycle_exist) {
            break;
        }
        for (int i = 0; i < N; i++) {
            node_color[i] = 'w';
        }


    }

    cout << cycle_exist;
}
