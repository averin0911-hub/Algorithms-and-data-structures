#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>


using namespace std;


vector<pair<int, int>> get_neighbours(vector<vector<int>>& maze, pair<int, int>& cell, int N, int M){
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<pair<int, int>> neighbours;
    for (vector<int> direct : directions){
        pair<int, int> new_neighbour{cell.first + direct[0], cell.second + direct[1]};

        if (new_neighbour.first >= 0 && new_neighbour.first < N && new_neighbour.second >= 0 && new_neighbour.second < M
        && maze[new_neighbour.first][new_neighbour.second] != -1){
            neighbours.push_back(new_neighbour);
        }
    }

    return neighbours;
}



int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> maze(N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            int x;
            cin >> x;
            maze[i].push_back(x);
        }
    }

    queue<pair<int, int>> q_start;
    queue<pair<int, int>> q_finish;

    pair<int, int> start{0, 0};
    pair<int, int> finish{N - 1, M - 1};

    q_start.push(start);
    q_finish.push(finish);

    map<pair<int, int>, int> dist_start; // Для хранения расстояния в клетку от старта
    map<pair<int, int>, int> dist_finish; // Для хранения расстояния в клетку от финиша
    dist_start[start] = 0;
    dist_finish[finish] = 0;


    set<pair<int, int>> visited_start;
    set<pair<int, int>> visited_finish;
    visited_start.insert(start);
    visited_finish.insert(finish);

    pair<int, int> connected_cell; // Клетка соеденения
    bool is_found = false;
    while (!q_start.empty() && !q_finish.empty()){

        // Сначала иду со стороны старта
        pair<int, int> current = q_start.front(); q_start.pop();

        if (visited_finish.find(current) != visited_finish.end()){
            connected_cell = current;
            is_found = true;
            break;
        }

        vector<pair<int, int>> neighbours = get_neighbours(maze, current, N, M);
        for (pair<int, int>& nb : neighbours){
            if (visited_start.find(nb) == visited_start.end()){
                q_start.push(nb);
                dist_start[nb] = dist_start[current] + 1;
                visited_start.insert(nb);
            }
        }

        // Затем со стороны финиша
        current = q_finish.front(); q_finish.pop();

        if (visited_start.find(current) != visited_start.end()){
            connected_cell = current;
            is_found = true;
            break;
        }

        neighbours = get_neighbours(maze, current, N, M);
        for (pair<int, int>& nb : neighbours){
            if (visited_finish.find(nb) == visited_finish.end()){
                dist_finish[nb] = dist_finish[current] + 1;
                q_finish.push(nb);
                visited_finish.insert(nb);
            }

        }
    }

    if (is_found || start == finish) {

        cout << dist_start[connected_cell] + dist_finish[connected_cell] << '\n';
    }
    else {
        cout << -1 << '\n';
    }


    return 0;
}