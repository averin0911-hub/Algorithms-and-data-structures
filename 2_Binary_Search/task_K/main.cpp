#include <iostream>
#include <vector>

using namespace std;

void DelExcessBallons(vector<int>& res, int res_sum, int M) {
    if (res_sum > M) {
        int different = res_sum - M;
        for (int i = static_cast<int>(res.size()) - 1; i >= 0; i--) {
            if (different - res[i] > 0) {
                different -= res[i];
                res[i] = 0;
            }
            else {
                res[i] -= different;
                different = 0;
                break;
            }
        }
    }
}

void OutArray(vector<int>& arr) {
    for (int el : arr) {
        cout << el << " ";
    }
}

int F(int t, int T, int Z, int Y) {
    int periods_count = t / (T * Z + Y);
    int t_without_periods = t - periods_count * (T * Z + Y);
    int t_without_periods_and_inflation = t_without_periods - T * Z;
    int relax_time;
    if (t_without_periods_and_inflation <= 0) {
        relax_time = periods_count * Y;
    }
    else {
        relax_time = periods_count * Y + t_without_periods_and_inflation;
    }

    return (t - relax_time) / T;
}

void MinTime(vector<vector<int>>& A, int M, int N) {
    int l = 0;
    int r = 0;
    int m;

    for (int i = 0; i < N; i++) {
        r = max((A[i][0] * A[i][1] + A[i][2]) * M, r);
    }
    vector<int> res(N);
    int res_sum = 0;

    while (r - l > 1) {
        m = (l + r) / 2;
        int sum_ball = 0;
        int count_balls;

        vector<int> temp_res(N);


        for (int i = 0; i < N; i++) {
            count_balls = F(m, A[i][0], A[i][1], A[i][2]);
            temp_res[i] = count_balls;
            sum_ball += count_balls;
        }

        if (sum_ball >= M) {
            r = m;
            res = temp_res;
            res_sum = sum_ball;
        }
        else {
            l = m;
        }
    }
    cout << r << endl;

    DelExcessBallons(res, res_sum, M);
    OutArray(res);

}

void InputArray(vector<vector<int>>& arr, int N) {
    for (int i = 0; i < N; i++) {
        vector<int> arr1(3);
        int temp;

        for (int j = 0; j < 3; j++) {
            cin >> temp;
            arr1[j] = temp;
        }

        arr[i] = arr1;
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> A(N);
    InputArray(A, N);

    MinTime(A, M, N);

    return 0;
}