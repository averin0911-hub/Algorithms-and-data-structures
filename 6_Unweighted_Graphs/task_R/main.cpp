#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<pair<int, int>> get_neighbours(pair<int, int> ceil, vector<vector<char>>& maze, int M, int N) {
    vector<pair<int, int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    vector<pair<int, int>> neighbours;
    for (pair<int, int> direct : directions) {
        pair<int, int> new_ceil(ceil.first + direct.first, ceil.second + direct.second);
        if ((new_ceil.first >= 0 && new_ceil.first < M) && (new_ceil.second >= 0 && new_ceil.second < N)
            && maze[new_ceil.first][new_ceil.second] == '#') {
            neighbours.push_back(new_ceil);
        }
    }

    return neighbours;
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<char>> maze(M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            char x;
            cin >> x;
            maze[i].push_back(x);
        }
    }

    set<pair<int, int>> visited;
    int count_of_parts = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            pair<int, int> start_ceil(i, j);
            if (visited.find(start_ceil) == visited.end() &&
                maze[start_ceil.first][start_ceil.second] == '#') {
                queue<pair<int, int>> q;
                q.push(start_ceil);
                visited.insert(start_ceil);

                while (!q.empty()) {
                    pair<int, int> current_ceil = q.front(); q.pop();

                    for (pair<int, int> neighbour : get_neighbours(current_ceil, maze, M, N)) {
                        if (visited.find(neighbour) == visited.end()) {
                            visited.insert(neighbour);
                            q.push(neighbour);
                        }
                    }
                }

                count_of_parts++;
            }
        }
    }

    cout << count_of_parts;

    return 0;
}