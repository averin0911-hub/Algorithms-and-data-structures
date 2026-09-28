# include <iostream>
# include <vector>

void BubbleSort(std::vector<int>& A){
	int size_A = A.size();
	bool flag = false;
	int i = 0;
	int temp;
	
	while (flag == false){
		flag = true;
		
		for (int j = size_A - 1; j > i; j--){
			if (A[j] > A[j - 1]){
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				flag = false;
			}
		}
		
		i++;
		
	}
}

int main(){
	std::vector<int> A;
	int temp;
	
	while (std::cin >> temp){
		A.push_back(temp);
	}
	
	int size_A = A.size();
	
	BubbleSort(A);
	
	for (int i = 0; i < size_A; i++){
		std::cout << A[i] << " ";
	};
	
	
	
	return 0;	
};