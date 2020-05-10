#include <cstdlib>		/* It helps us to generate some random numbers!!!*/
#include <iostream>
#include <vector>


#include <chrono> 
using namespace std::chrono;


int64_t MaxPairwiseProduct(const std::vector<int>& num , int ntop){
	int64_t result = 1;
	int z = ntop;
	int m = INT_MIN;
	int pl = 0;
	int sz = num.size();
	int arrsz = sz;
	int arr [sz];
	int numm [z];
	int del = INT_MIN;
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
		m = INT_MIN;
	}

	// std::cout << "Steps : " << Steps << std::endl;

	for (int i = 0; i < z; i++){
		result = ((int64_t)result) * numm[i];
	}
	

	return result;
}

int main(){


	//////////////___Stress_Test___/////////////
	while (true){
		int top = 2;
		int n = rand() % 100 + top;
		std::cout << n << "\n";
		std::vector<int> a;
		for (int i = 0; i < n; ++i){
			a.push_back(rand() % 100);
		}
		for (int i = 0; i < n; ++i){
			std::cout << a[i] << ' ';
		}
		std::cout << "\n";
		// std::cout << top << " Max numbers are getting multiplied!"<<"\n";
		
		auto start = high_resolution_clock::now();

		int64_t res1 = MaxPairwiseProduct(a, top);
		std::cout << res1 << "\n";

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		std::cout << "duration: "
        << duration.count() << " microseconds" << "\n\n";
	}

	//////////////////////////////////////////////




	// int n;
	// int top;
	// std::cin >> n;
	// std::vector<int> numbers(n);
	// for (int i=0; i<n; i++){
	// 	std::cin >> numbers[i];
	// }
	// std::cout <<"How many Max numbers you want to multiply: "<<std::endl;
	// std::cin >> top;

	// auto start = high_resolution_clock::now();

	// long long result = MaxPairwiseProduct(numbers,top);
	// std::cout << result << "\n";

	// auto stop = high_resolution_clock::now();

	// auto duration = duration_cast<microseconds>(stop - start);

	// std::cout << "duration: "
 //         << duration.count() << " microseconds" << std::endl;
	

	return 0;
}
