#include <iostream>
#include <vector>

using namespace std;

class heapMax {
    vector<int> heap = {0};
    int len = 0;

    void shiftUp(int i) {
        while (i / 2 > 0 && heap[i] > heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

    int indMaxChild(int i) {
        if (i * 2 + 1 > len || heap[i * 2] > heap[i * 2 + 1]) {
            return i * 2;
        }
        return i * 2 + 1;
    }

    void shiftDown(int i) {
        while (i * 2 <= len) {
            int j = indMaxChild(i);
            if (heap[i] < heap[j]) {
                swap(heap[i], heap[j]);
                i = j;
            }
            else {
                break;
            }
        }
    }

public:
    void insert(int x) {
        heap.push_back(x);
        len++;
        shiftUp(len);
    }

    int delMax() {
        int removing = heap[1];
        heap[1] = heap[len];
        heap.pop_back();
        len--;
        shiftDown(1);
        return removing;
    }
};

int main() {
    int N;
    cin >> N;

    heapMax heap;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        heap.insert(-temp);
    }

    for (int i = 0; i < N; i++) {
        cout << -heap.delMax() << '\n';
    }
    return 0;
}