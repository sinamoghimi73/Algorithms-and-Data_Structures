#include <iostream>

#include <chrono>
using namespace std::chrono;

long long Great_Common_Divisor(long long a, long long b){
	int mod = 0;

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
	return a;
}

long long Least_Common_Multiple(long long a, long long b){
    if (a == 0 || b == 0){
        return 0;
    }
    return (abs(a)/Great_Common_Divisor(a,b))*abs(b);
}


int main(){

    long long a = 0;
    long long b = 0;

    std::cin >> a >> b;

    auto start = high_resolution_clock::now();
    std::cout << Least_Common_Multiple(a,b) << std::endl;
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    std::cout << "duration: "<< duration.count() << " nanoseconds" << "\n\n";

    return 0;
}
