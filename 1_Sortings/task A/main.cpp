#include <iostream>
#include <vector>


using namespace std;

void SelectionSort(vector<int>& A){
	int size_A = A.size();
	int index_max;
	
	for (int i = 0; i < size_A; i++){
		int index_max = i;
		for (int j = i + 1; j < size_A; j++){
			if (A[j] > A[index_max]){
				index_max = j;
			}
		}
		
		int temp = A[i];
		A[i] = A[index_max];
		A[index_max] = temp;
		}
	}


int main(int argc, char** argv) {
	vector<int> A;
	int temp;

	while (cin >> temp){
		A.push_back(temp);	
	}

	SelectionSort(A);
	
	for (int i = 0; i < A.size(); i++){
		cout << A[i] << " ";
	}
	
	return 0;
}