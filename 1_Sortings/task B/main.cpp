#include <iostream>
#include <vector>


using namespace std;

void InsertionSort(vector<int>& A){
	int size_A = A.size();
	int count_sorted = 0;
	
	for (int i = 1; i < size_A; i++){
		int key = A[i];
		int j = i;
		while (j >= 1 && A[j - 1] > key){
			A[j] = A[j - 1];
			j--;
		} 
		A[j] = key;
	}
	
}

int main(int argc, char** argv) {
	vector<int> A;
	int temp;

	while (cin >> temp){
		A.push_back(temp);
	}
	
	int size_A = A.size();
	
	InsertionSort(A);
	
	for (int i = 0; i < size_A; i++){
		cout << A[i] << " ";
	}
		
	return 0;
}