#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, unordered_set<int>> list_of_connections;
    int root;
    for (int node = 1; node <= n; node++) {
        int parent;
        cin >> parent;
        if (parent == 0) {
            root = node;
            continue;
        }
        list_of_connections[parent].insert(node);
    }


    unordered_map<int, int> tin; // Храним время входа в каждый узел
    unordered_map<int, int> tout; // И время выхода из узла

    vector<int> stack;

    stack.push_back(root);
    unordered_set<int> visited;
    int t = 0;
    while (!stack.empty()) {
        int current_node = stack.back();
        if (visited.find(current_node) == visited.end()) { // При входе в новый узел запоминаем время вххода в него
            t++;
            tin[current_node] = t;
        }
        visited.insert(current_node);


        bool have_child = false;
        for (int next_node : list_of_connections[current_node]) {

            if (visited.find(next_node) == visited.end()) {
                have_child = true;
                stack.push_back(next_node);
                break;
            }
        }

        if (!have_child) {
            tout[current_node] = t; // При выходе из узла запоминаем время выхода из него
            stack.pop_back();

            t++;
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (tin[a] < tin[b] && tout[a] > tout[b]) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }

    }

    return 0;
}

