#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> QuickSort(vector<int>& A, int size) {
    if (A.size() < 2) {
        return A;
    }


    int choice_i = rand() % size;
    int choice = A[choice_i];

    vector<int> left;
    vector<int> equals;
    vector<int> right;
    for (int i = 0; i < size; i++) {
        if (A[i] < choice) {
            left.push_back(A[i]);
        }
        else if (A[i] == choice) {
            equals.push_back(A[i]);
        }
        else {
            right.push_back(A[i]);
        }
    }

    vector<int> result;
    vector<int> left1 = QuickSort(left, left.size());
    vector<int> right1 = QuickSort(right, right.size());

    for (int i = 0; i < left1.size(); i++) {
        result.push_back(left1[i]);
    }
    for (int i = 0; i < equals.size(); i++) {
        result.push_back(equals[i]);
    }
    for (int i = 0; i < right1.size(); i++) {
        result.push_back(right1[i]);
    }

    return result;
}

int main() {
    srand(time(0));

    vector<int> A;
    int temp;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    A = QuickSort(A, size);

    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;



    return 0;
}