#include <iostream>

#include <chrono> 
using namespace std::chrono;


long long Fib(int n){
	long long Fib_Num;

	if (n <= 1){
		Fib_Num = n;
		return Fib_Num;
	}

	int Fib1 = 0;
	int Fib2 = 1; 
	int Num = 0;

	for (int i = 1; i < n; i++ ){
		Num = Fib1 + Fib2;
		Fib_Num = Num;
		Fib1 = Fib2;
		Fib2 = Num;
		// std::cout << Fib_Num << std::endl;
	}
	return Fib_Num;
}

int main(){

	int n =0;
	std::cin>>n;



	auto start = high_resolution_clock::now();

	long long Fib_Num = Fib(n);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);

	std::cout << Fib_Num << std::endl;

	std::cout << "duration: "<< duration.count() << " nanoseconds" << "\n\n";

	return 0;
}