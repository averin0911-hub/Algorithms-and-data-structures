#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> list_of_connection;
    for (int i = 1; i <= N; i++) {
        int kopilka_with_i_key;
        cin >> kopilka_with_i_key;
        list_of_connection[i] = kopilka_with_i_key;
    }

    unordered_map<int, char> kopilka_status; // 0 - не смотрелась, 1 - смотрелась, 2 - открыта (разбита)
    for (int i = 1; i <= N; i++) {
        kopilka_status[i] = 0;
    }

    unordered_set<int> opened;
    int count_broken = 0;
    for (int kopilka = 1; kopilka <= N; kopilka++) {
        if (kopilka_status[list_of_connection[kopilka]] == 2 || // Если копилка в которой лежит ключ от текущей копилки открыта
            kopilka_status[kopilka] == 2) { //  или если текущая копилка уже открыта
            kopilka_status[kopilka] = 2;
            continue;
        }

        vector<int> stack;
        kopilka_status[kopilka] = 1;
        stack.push_back(kopilka);

        while (!stack.empty()) {
            int current_kopilka = stack.back();
            int next_copilka = list_of_connection[current_kopilka];

            if (kopilka_status[next_copilka] == 2) { // Если следущая копилка открыта или разбита
                kopilka_status[current_kopilka] = 2; // то открываем копилку ключом
                stack.pop_back();
                continue;
            }

            if (kopilka_status[next_copilka] == 1 || current_kopilka == next_copilka) { // Если оказался цикл
                kopilka_status[current_kopilka] = 2; // то разбиваем копилку
                count_broken++;
                stack.pop_back();
                continue;
            }

            stack.push_back(next_copilka);
            kopilka_status[current_kopilka] = 1;
        }

    }

    cout << count_broken;

    return 0;
}