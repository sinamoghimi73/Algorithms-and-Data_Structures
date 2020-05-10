#include <iostream>

int FibLD(int n){
	int Fib_LD = 0;

	if (n <= 1){
		return n;
	}

	int Fib1 = 0;
	int Fib2 = 1; 

	for (int i = 0; i < n-1; i++ ){
		Fib_LD = (Fib1 % 10) + (Fib2 % 10);
		Fib1 = Fib2 % 10;
		Fib2 = Fib_LD % 10;
	}

	return Fib_LD % 10;
}


int main(){

	int n =0;
	std::cin >> n;

	int Fib_LD = FibLD(n);

	std::cout << Fib_LD << std::endl;

	return 0;
}

