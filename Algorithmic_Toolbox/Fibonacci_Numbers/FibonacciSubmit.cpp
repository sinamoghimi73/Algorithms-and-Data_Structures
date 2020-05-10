#include <iostream>

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
	}
	return Fib_Num;
}

int main(){

	int n = 0;
	std::cin>>n;

	std::cout << Fib(n) << std::endl;


	return 0;
}
