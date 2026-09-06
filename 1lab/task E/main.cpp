#include <iostream>
#include <vector>

using namespace std;

vector<int> Merge(vector<int>& left, vector<int>& right);


vector<int> MergeSort(vector<int>& A, int size){
	if (size <= 1){
		return A;
	}
	
	int med = size / 2;
	vector<int> left, right;
	
	for (int i = 0; i < med; i++){
		left.push_back(A[i]);
	}
	for (int i = med; i < size; i++){
		right.push_back(A[i]);
	}
	
	left = MergeSort(left, left.size());
	right = MergeSort(right, right.size());
	
	return Merge(left, right);
}

vector<int> Merge(vector<int>& left, vector<int>& right){
	vector<int> result;
	int i = 0, j = 0;
	
	while (i < left.size() && j < right.size()){
		if (left[i] <= right[j]){
			result.push_back(left[i]);
			i++;
		} 
		else{
			result.push_back(right[j]);
			j++;
		}
	}
	
	if (i == left.size()){
		for (int k = j; k < right.size(); k++){
			result.push_back(right[k]);
		}
	}
	else{
		for (int k = i; k < left.size(); k++){
			result.push_back(left[k]);
		}
	}
	
	return result;
}

int main(int argc, char** argv) {
	vector<int> A;
	int temp;
	
	int size;
	cin >> size;
	
	while (cin >> temp){
		A.push_back(temp);
	}
	
	A = MergeSort(A, size);
	
	for (int i = 0; i < size; i++){
		cout << A[i] << " ";
	}
		
	
	return 0;
}