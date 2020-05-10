//
//  main.cpp
//  SORT_NEW
//
//  Created by Sina Moghimi on 1/21/20.
//  Copyright © 2020 Sina Moghimi. All rights reserved.
//

#include <iostream>
#include <vector>

void print_Num(std::vector<int> &vec, int z, int n){
    for(int i = z; i < n; i++){
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}


void Avg(std::vector<int> &vec, int z, int n, int *i_min, int *i_max, int *i_avg, int *count){
	int sum{0}, num{0}, min{vec.at(z)}, max{vec.at(z)};
	
	for(int i = z; i <= n; i++){
		num = vec.at(i);
		*count += 1;
		if(num <= min){
			*i_min = i;
			min = num;
			*count += 1;
		}
		if(num >= max){
			*i_max = i;
			max = num;
			*count += 1;
		}
	}
	*i_avg = 0;
	
//	std::cout << "Z :" << z << " N :" << n << std::endl;
//	std::cout << "min : " << vec.at(*i_min) << " max : " << vec.at(*i_max) << std::endl;
}

void SORT(std::vector<int> &vec, int n, int *count){
	int F{0}, L{n-1};
	int i_min{0}, i_max{0}, i_avg{0};
	bool flag_min{true}, flag_max{true};
	while(L - F > 2){
		flag_min = true;
		flag_max = true;
		*count += 1;
//		std::cout << "F :" << F << " L :" << L << std::endl;
		Avg(vec, F, L, &i_min, &i_max, &i_avg, &*count);
		if((i_min == L)&&(i_max == F)){
			std::swap(vec.at(i_min), vec.at(F));
//			print_Num(vec, 0, n);
			*count += 1;
			flag_min = false;
			flag_max = false;
		}
		else if(i_min == L){
			std::swap(vec.at(i_min), vec.at(F));
//			print_Num(vec, 0, n);
			*count += 1;
			flag_min = false;
		}
		
		if((L != i_max)&&(vec.at(L) != vec.at(i_max))&&(flag_max == true)){
			std::swap(vec.at(i_max), vec.at(L));
//			print_Num(vec, 0, n);
			*count += 1;
		}
		if((F != i_min)&&(vec.at(F) != vec.at(i_min))&&(flag_min == true)){
			std::swap(vec.at(i_min), vec.at(F));
//			print_Num(vec, 0, n);
			*count += 1;
		}
		
		
		L--;
		F++;
	}
	
	if(L - F == 2){
		int min{0}, avg{0}, max{0};
		Avg(vec, F, L, &i_min, &i_max, &i_avg, &*count);
		min = vec.at(i_min);
		max = vec.at(i_max);
		for(short i = F; i <= L; i++){
			if((i != i_min)&&(i != i_max)){
				avg = vec.at(i);
			}
			*count += 1;
		}
		vec.at(F) = min;
		vec.at(F+1) = avg;
		vec.at(L) = max;
		*count += 1;
	}

	if(L - F == 1){
		if(vec.at(F) > vec.at(L)){
			std::swap(vec.at(F), vec.at(L));
			*count += 1;
		}
	}
	
//
}



int main() {
	
	int n{0};
	std::cin >> n ;

	std::vector<int> vec;
	int num{0};
	for(int i = n; i > 0; i--){
		std::cin >> num ;
		vec.push_back(num);
	}


//
	int count{0};
	SORT(vec, n, &count);
	std::cout << "count = " << count << "\n";
	print_Num(vec, 0, n);

	return 0;
}
