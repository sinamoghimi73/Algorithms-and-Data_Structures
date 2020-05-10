#include <iostream>

int Fib(int n, int m){
	if (n <= 1){
		return n;
	}

	int Fib1 = 0;
	int Fib2 = 1;
	int Num = 0;
    int Sum = 1;


	for (int i = 1; i < n; i++ ){
		Num = (Fib1 % m) + (Fib2 % m);
		Fib1 = Fib2 % m;
		Fib2 = Num % m;
        Sum += Fib2;
	}
	return Sum % m;
}

int main(){

	int n = 0;
    int m = 10;
	std::cin >> n;

	std::cout << Fib(n,m) << std::endl;

	return 0;
}
