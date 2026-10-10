#include <iostream>
#include <vector>

using namespace std;

class Queue {
    vector<int> left;
    vector<int> right;
    int count = 0;

public:
    void push(int x) {
        left.push_back(x);
        count++;
    }
    int pop() {
        int a = this->front();
        right.pop_back();
        count--;
        return a;
    }
    int size() {
        return count;
    }
    int front() {
        if (right.empty()) {
            for (int i = 0; i < count; i++) {
                right.push_back(left.back());
                left.pop_back();
            }
        }
        return right.back();
    }
    bool is_empty() {
        return left.empty() && right.empty();
    }
};

int main() {
    Queue player1;
    Queue player2;

    int input;
    for (int i = 0; i < 5; i++) {cin >> input; player1.push(input);}
    for (int i = 0; i < 5; i++) {cin >> input; player2.push(input);}

    int card1;
    int card2;
    int count = 0;
    while (!player1.is_empty() && !player2.is_empty() && count < 1e6) {
        card1 = player1.pop();
        card2 = player2.pop();

        if ((card1 > card2 || (card1 == 0 && card2 == 9)) && !(card1 == 9 && card2 == 0)) {
            player1.push(card1);
            player1.push(card2);
        }
        else {
            player2.push(card1);
            player2.push(card2);
        }
        count++;
    }

    if (count <= 1e6) {
        if (!player1.is_empty()) {
            cout << "first ";
        }
        else {
            cout << "second ";
        }
        cout << count;
    }
    else {
        cout << "botva";
    }

    return 0;
}