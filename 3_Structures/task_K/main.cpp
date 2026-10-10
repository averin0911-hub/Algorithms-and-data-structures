#include <iostream>
#include <vector>

using namespace std;


int minim;
long long res;
vector<vector<int>> res_period;

void f(vector<vector<long long>>& days) {
    if (days.size() == 1) {
        if ((long long)days.back()[1] * (long long)days.back()[2] > res) {
            res = (long long)days.back()[1] * (long long)days.back()[2];
            res_period = days;
        }
        return;
    }
    else if (days.empty()) {
        return;
    }

    vector<vector<vector<long long>>> periods;

    vector<vector<long long>> period;
    int count = 0;
    for (int i = 0; i < days.size() + 1; i++) {

        if (i == days.size() || days[i][0] == days.back()[1]) {
            if (period.empty()) {
                continue;
            }
            if ((long long)period.back()[1] * (long long)period.back()[2] > res) {
                res = (long long)period.back()[1] * (long long)period.back()[2];
                res_period = period;
            }
            periods.push_back(period);
            count = 0;
            period.clear();
            continue;
        }

        if (count == 0) {
            period.push_back({days[i][0], days[i][0], days[i][0], days[i][3]});
            count++;
            continue;
        }
        period.push_back({days[i][0], min(days[i][0], period.back()[1]), period.back()[2] + days[i][0], days[i][3]});
    }

    for (vector<vector<long long>>& period: periods) {
        f(period);
    }

}

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> days;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (i == 0) {
            days.push_back({temp, temp, temp, i + 1});
            continue;
        }
        days.push_back({temp, min(temp, days.back()[1]), days.back()[2] + temp, i + 1});
    }

    res = days.back()[1] * days.back()[2];
    res_period = days;

    f(days);

    cout << res << '\n';
    cout << res_period.front()[3] << " " << res_period.back()[3];


    return 0;
}