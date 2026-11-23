#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> edges; // Словарь смежности
    for (int i = 0; i < m; i++){
        int node1, node2;
        cin >> node1 >> node2;

        edges[node1].insert(node2); // Добавление ключа в словарь(если его нет) и одновременно добавление в множество по ключу
        edges[node2].insert(node1);
    }

    bool is_full = true;
    if (edges.size() == n){ // Проверка на одиночные узлы
        for (int i = 1; i <= n; i++){
            if (edges[i].size() != n - 1){ // Узел должен быть связан со всеми кроме себя
                is_full = false;
                break;
            }
        }
    }
    else {
        is_full = false;
    }

    if (is_full){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }

    
    
    

    return 0;
}