#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){ 
    int N, S;
    cin >> N >> S;

    unordered_map<int, vector<int>> list_of_connections;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            int x;
            cin >> x;

            if (x == 1) {
                list_of_connections[i].push_back(j);
            }
        }
    }

    unordered_set<int> visited;
    vector<int> stack;
    
    visited.insert(S);
    stack.push_back(S);

    while (!stack.empty()){
        int current_node = stack.back();

        bool is_get_next = false; // Есть ли непосещённый сосед
        for (int next_node : list_of_connections[current_node]){
            if (visited.find(next_node) == visited.end()){ // Проверка на вхождение в множество
                stack.push_back(next_node);
                visited.insert(next_node);
                is_get_next = true;
                break;
            }
        }

        if (!is_get_next){
            stack.pop_back();
        }
    }

    cout << visited.size() << '\n';

    return 0;
}