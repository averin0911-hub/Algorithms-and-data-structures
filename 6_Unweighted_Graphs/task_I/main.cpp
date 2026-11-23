#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

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
    int N;
    pair<int, int> start, finish;

    cin >> N;
    cin >> start.first >> start.second;
    cin >> finish.first >> finish.second;

    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    map<pair<int, int>, pair<int, int>> dict_for_path;

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        pair<int, int> current_coord = q.front(); q.pop();

        if (current_coord == finish) {
            break;
        }

        for (pair<int, int> neigh : neighbours(current_coord, N)) {
            if (visited.find(neigh) == visited.end()) {
                visited.insert(neigh);
                dict_for_path[neigh] = current_coord;
                q.push(neigh);
            }
        }
    }

    vector<pair<int, int>> reversed_path;
    pair<int, int> current_coord = finish;

    while (current_coord != start) {
        reversed_path.push_back(current_coord);
        current_coord = dict_for_path[current_coord];
    }
    reversed_path.push_back(start);


    cout << reversed_path.size() - 1 << '\n';
    while (!reversed_path.empty()) {
        cout << reversed_path.back().first << " " << reversed_path.back().second << '\n';
        reversed_path.pop_back();
    }
}