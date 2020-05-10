#include <iostream>
#include <cmath>

#include <chrono>
using namespace std::chrono;

long long Fib(long long n, long long m){

	if (n <= 1){
		return n;
	}

	long long Fib1(0);
	long long Fib2(1);
	long long Num(0);

	for (int i = 1; i < n; i++ ){
		Num = Fib1 + Fib2;
		Fib1 = Fib2 % m;
		Fib2 = Num % m;
	}
	return Fib2;

}

// long long Fib_naive(long long n){
// 	long long Fib_Num;
//
// 	if (n <= 1){
// 		Fib_Num = n;
// 		return Fib_Num;
// 	}
//
// 	int Fib1 = 0;
// 	int Fib2 = 1;
// 	int Num = 0;
//
// 	for (int i = 1; i < n; i++ ){
// 		Num = Fib1 + Fib2;
// 		Fib_Num = Num;
// 		Fib1 = Fib2;
// 		Fib2 = Num;
// 	}
// 	return Fib_Num;
// }


int main(){
	long long n(7);
    long long m(10);
	// std::cin >> n >> m;

	auto start = high_resolution_clock::now();

	std::cout << Fib(n,m) << std::endl;
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<nanoseconds>(stop - start);
	std::cout << "duration: "<< duration.count() << " nanoseconds" << "\n\n";



	return 0;
}
