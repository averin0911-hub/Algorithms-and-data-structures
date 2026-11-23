#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

vector<pair<int, int>> get_neighbours(pair<int, int> ceil, vector<vector<int>>& maze, int N, int M) {
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    vector<pair<int, int>> neighbours;
    for (vector<int> direct : directions) {
        pair<int, int> new_ceil = ceil;
        while (new_ceil.first + direct[0] >= 0 && new_ceil.first + direct[0] < N &&
        new_ceil.second + direct[1] >= 0 && new_ceil.second + direct[1] < M &&
        maze[new_ceil.first + direct[0]][new_ceil.second + direct[1]] != 1) {

            new_ceil.first += direct[0];
            new_ceil.second += direct[1];

            if (maze[new_ceil.first][new_ceil.second] == 2) { // Если отверстие, то считаем, что дальше стена и записываем в соседи
                break;
            }
        }

        neighbours.push_back(new_ceil);
    }

    return neighbours;
}

int main() {
    int N, M;
    cin >> N >> M;


    vector<vector<int>> maze(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            maze[i].push_back(x);
        }
    }


    pair<int, int> start{0, 0};

    queue<pair<int, int>> q;
    map<pair<int, int>, int> dist; // Количество наклонов
    set<pair<int, int>> visited;

    q.push(start);
    visited.insert(start);
    dist[start] = 0;

    pair<int, int> hole; // Отверстие
    while (!q.empty()) {
        pair<int, int> current_ceil = q.front(); q.pop();

        if (maze[current_ceil.first][current_ceil.second] == 2) {
            hole = current_ceil;
            break;
        }

        for (pair<int, int> neighbour : get_neighbours(current_ceil, maze, N, M)) {
            if (visited.find(neighbour) == visited.end()) {
                visited.insert(neighbour);
                q.push(neighbour);
                dist[neighbour] = dist[current_ceil] + 1;
            }
        }
    }

    cout << dist[hole];

    return 0;
}