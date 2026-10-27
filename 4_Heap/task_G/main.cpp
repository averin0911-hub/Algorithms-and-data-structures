#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<vector<int>, vector<vector<int>>, greater<>> heap;
    int x; // Кол-во рыбок в аквариуме
    for (int i = 1; i <= N; i++) {
        cin >> x;
        heap.push({max(1000 - x, 1), x, i}); // (время до новой рыбки, кол-во рыбок в аквариуме, номер аквариума)
    }

    int t = 0; // Текущее время
    int pos = 1; // Позиция Игоря

    while (true) {
        if (t == heap.top()[0]) {
            if (pos != heap.top()[2]) {
                break;
            }
            vector<int> aquarium = heap.top();
            heap.pop();
            heap.push({aquarium[0] + max(1000 - (aquarium[1] + 1), 1), aquarium[1] + 1, aquarium[2]});

            if (t == heap.top()[0]) {
                break;
            }
        }

        if (pos > heap.top()[2]) {
            pos--;
        }
        else if (pos < heap.top()[2]) {
            pos++;
        }
        t++;
    }
    cout << t;


    return 0;
}