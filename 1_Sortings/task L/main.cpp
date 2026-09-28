#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

vector<int> QuickSort(vector<int>& A, bool reverse) {
    if (A.size() < 2) {
        return A;
    }

    int choice_i = rand() % A.size();
    int choice = A[choice_i];

    vector<int> left;
    vector<int> equal;
    vector<int> right;

    for (int i = 0; i < A.size(); i++) {
        if ((A[i] < choice && !reverse) || (A[i] > choice && reverse)) {
            left.push_back(A[i]);
        }
        else if (A[i] == choice) {
            equal.push_back(A[i]);
        }
        else {
            right.push_back(A[i]);
        }
    }

    vector<int> left1 = QuickSort(left, reverse);
    vector<int> right1 = QuickSort(right, reverse);

    vector<int> result;

    for (int i = 0; i < left1.size(); i++) {
        result.push_back(left1[i]);
    }
    for (int i = 0; i < equal.size(); i++) {
        result.push_back(equal[i]);
    }
    for (int i = 0; i < right1.size(); i++) {
        result.push_back(right1[i]);
    }

    return result;
}

int main() {
    srand(time(0));
    vector<int> dist;
    vector<int> price;
    string x1, x2;
    getline(cin, x1);
    getline(cin, x2);

    stringstream ss1(x1);
    stringstream ss2(x2);

    int temp;
    while (ss1 >> temp) {
        dist.push_back(temp);
    }

    while (ss2 >> temp) {
        price.push_back(temp);
    }

    dist = QuickSort(dist, false);
    price = QuickSort(price, true);

    int sum = 0;

    for (int i = 0; i < dist.size(); i++) {
        sum += dist[i] * price[i];
    }

    cout << sum;
    return 0;
}