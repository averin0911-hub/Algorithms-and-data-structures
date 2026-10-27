#include <iostream>
#include <vector>
#include <string>

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
        int removed = heap[1];
        heap[1] = heap[len];
        heap.pop_back();
        len--;
        shiftDown(1);
        return removed;
    }

    void clear() {
        heap.clear();
        len = 0;
        heap.push_back(0);
    }

    bool isEmpty() {
        return len == 0;
    }
};

int main() {
    heapMax heap;

    string op;
    int val;
    while (cin >> op) {
        if (op == "ADD") {
            cin >> val;
            heap.insert(val);
        }
        else if (op == "CLEAR") {
            heap.clear();
        }
        else {
            if (heap.isEmpty()) {
                cout << "CANNOT" << '\n';
            }
            else {
                cout << heap.delMax() << '\n';
            }
        }
    }

    return 0;
}