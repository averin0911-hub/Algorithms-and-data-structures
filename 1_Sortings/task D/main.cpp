#include <iostream>
#include <vector>

using namespace std;

int BubbleSort(vector<int>& A, int size_A){
	bool flag = false;
	int i = size_A;
	int count = 0;
	
	while (flag == false){
		flag = true;
		for (int j = 0; j < i - 1; j++){
			if (A[j] > A[j + 1]){
				flag = false;
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				count++;
			}
		}
		i--;
	}
	return count;
}

int main(int argc, char** argv) {
	int size;
	cin >> size;
	
	vector<int> A;
	int temp;

	while (cin >> temp){
		A.push_back(temp);
	}
	
	cout << BubbleSort(A, size) << endl;
	
	return 0;
}