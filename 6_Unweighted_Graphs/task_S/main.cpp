#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>

using namespace std;

vector<pair<int, int>> neighbours(pair<int, int>& coord, int N) {
    vector<vector<int>> directions = {
        {-1, -2}, {1, -2},
        {2, -1}, {2, 1},
        {1, 2}, {-1, 2},
        {-2, -1}, {-2, 1}
    };

    vector<pair<int, int>> res;
    for (vector<int>& direct : directions) {
        int x = coord.first + direct[0];
        int y = coord.second + direct[1];
        if ((x >= 1 && x <= N) && (y >= 1 && y <= N)) {
            pair<int, int> new_coord(x, y);
            res.push_back(new_coord);
        }
    }

    return res;
}

int main() {
    char x1; int y1;
    char x2; int y2;
    cin >> x1 >> y1 >> x2 >> y2;

    map<char, int> dict;
    vector<vector<char>> alp = {
        {'a', 1},
        {'b', 2},
        {'c', 3},
        {'d', 4},
        {'e', 5},
        {'f', 6},
        {'g', 7},
        {'h', 8}
    };

    for (vector<char> coord : alp) {
        dict[coord[0]] = coord[1];
    }

    pair<int, int> coord_red(dict[x1], y1);
    pair<int, int> coord_green(dict[x2], y2);


    queue<pair<int, int>> q_red;
    queue<pair<int, int>> q_green;

    set<pair<int, int>> visited_red;
    set<pair<int, int>> visited_green;

    q_red.push(coord_red);
    q_green.push(coord_green);

    visited_red.insert(coord_red);
    visited_green.insert(coord_green);

    map<pair<int, int>, int> dist_red;
    map<pair<int, int>, int> dist_green;

    dist_red[coord_red] = 0;
    dist_green[coord_green] = 0;

    bool meeting = false;
    pair<int, int> meeting_ceil;
    while (!q_red.empty() && !q_green.empty()) {
        int size_q_red = q_red.size();

        set<pair<int, int>> current_visited_red; // Создаю множество координат следующего слоя у красного коня
        for (int i = 0; i < size_q_red; i++) { // Обрабатываю следующий слой
            pair<int, int> current_ceil = q_red.front(); q_red.pop();

            for (pair<int, int> neigh : neighbours(current_ceil, 8)) {
                if (visited_red.find(neigh) == visited_red.end()) {
                    visited_red.insert(neigh);
                    current_visited_red.insert(neigh);
                    dist_red[neigh] = dist_red[current_ceil] + 1;
                    q_red.push(neigh);
                }
            }
        }



        int size_q_green = q_green.size();
        for (int i = 0; i < size_q_green; i++) { // Теперь обрабатываю следующий слой у зелёного коня
            pair<int, int> current_ceil = q_green.front(); q_green.pop();


            for (pair<int, int> neigh : neighbours(current_ceil, 8)) {
                if (visited_green.find(neigh) == visited_green.end()) {
                    visited_green.insert(neigh);
                    dist_green[neigh] = dist_green[current_ceil] + 1;
                    q_green.push(neigh);

                    if (current_visited_red.find(neigh) != current_visited_red.end()) { // Если два клетка со слоя зелёного коня наложилась на клетку красного коня (столкновение)
                        meeting = true;
                        meeting_ceil = neigh;
                        break;
                    }
                }
            }
        }

        if (meeting) {
            break;
        }


    }

    if (meeting) {
        cout << dist_green[meeting_ceil];
    }
    else {
        cout << -1;
    }


    return 0;
}
//