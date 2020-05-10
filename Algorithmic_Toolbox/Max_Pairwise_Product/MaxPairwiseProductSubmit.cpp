#include <iostream>
#include <vector>



long long MaxPairwiseProduct(const std::vector<int>& num , int ntop){
	long long result = 1;
	int z = ntop;
	int m = -1;
	int pl = 0;
	int sz = num.size();
	int arrsz = sz;
	int arr [sz];
	int numm [z];
	int del = -1;
	int Steps = 0;
	
	for (int i = 0; i < sz; i++){
		arr[i]=num[i];
	}

	for (int i = 0; i < z; i++){

		for (int k = 0; k < arrsz; k++){
			if (k == del){
				for (int y = k; y < arrsz; y++ ){
					arr[y] = arr[y+1];
				}
				arrsz--;
				break;
			}
		}


		for (int j = 0; j < arrsz; j++){
			if (arr[j] > m){
				m = arr[j];
				pl = j;
			}

		}
		numm[i]=arr[pl];
		del = pl;
		Steps = Steps + arrsz;
		m = -1;
	}
	// std::cout << "Steps : " << Steps << std::endl;

	for (int i = 0; i < z; i++){
		result = ((long long)result) * numm[i];
	}
	
	return result;
}

int main(){

	int n;
	int top = 2;
	std::cin >> n;
	std::vector<int> numbers(n);
	
	for (int i=0; i<n; i++){
		std::cin >> numbers[i];
	}

	long long result = MaxPairwiseProduct(numbers,top);
	std::cout << result << "\n";

	return 0;
}
