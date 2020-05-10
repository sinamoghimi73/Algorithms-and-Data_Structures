#include <iostream>

long long Great_Common_Divisor(long long a, long long b){
	int mod = 0;
	int gcd = 0;

	if (a == 0){
		return b;
	}

	if (b == 0){
		return a;
	}

	if (b > a){
		std::swap(a,b);
		}

	while(b > 0) {
		mod = a % b;
		a = b;
		b = mod;
	}
	gcd = a;
	return gcd;
}


int main(){
	long long a = 0;
	long long b = 0;
	std::cin >> a >> b;

	std::cout << Great_Common_Divisor(a,b) << std::endl;

	return 0;
}
