#include <iostream>

int Fib(int a, int b, int m){
	// if (a <= 1){
	// 	return n;
	// }

	int Fib1 = 0;
	int Fib2 = 1;
	int Num = 0;

	for (int i = 1; i < a; i++ ){
		Num = (Fib1 % m) + (Fib2 % m);
		Fib1 = Fib2 % m;
		Fib2 = Num % m;
	}
    int Sum = Fib2;

    for (int i = 0; i < (b-a); i++){
        Num = (Fib1 % m) + (Fib2 % m);
        Fib1 = Fib2 % m;
        Fib2 = Num % m;
        Sum += Fib2;
    }

	return Sum % m;
}

int main(){

	int a = 0;
    int b = 0;
    int m = 10;
	std::cin >> a >> b;

	std::cout << Fib(a,b,m) << std::endl;

	return 0;
}
