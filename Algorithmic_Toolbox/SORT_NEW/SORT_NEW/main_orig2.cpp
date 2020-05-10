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


int Avg(std::vector<int> &vec, int z, int n, int *i_min, int *i_max, int *count, std::vector<bool> &check){
	int sum{0}, num{0}, min{vec.at(z)}, max{vec.at(z)};
	
	for(int i = z; i <= n; i++){
		num = vec.at(i);
		sum = sum + num;
		*count += 2;
		if(num <= min){
			*i_min = i;
			min = num;
		}
		if(num >= max){
			*i_max = i;
			max = num;
		}
	}
	
	int avg = sum / n;
	check.at(*i_max) = false;
	check.at(*i_min) = false;
//	std::cout << "Z :" << z << " N :" << n << std::endl;
//	std::cout << "min : " << vec.at(*i_min) << " max : " << vec.at(*i_max) << std::endl;
	return avg;
}

void SORT(std::vector<int> &vec, int n, int *count){
	int F{0}, L{n-1}, avg;
	std::vector<int> list(n);
	std::vector<bool> check(n, true);
	int i_min{0}, i_max{0};
	if(n % 2 == 0){
		while(L - F > 0){
			avg = Avg(vec, F, L, &i_min, &i_max, &*count, check);
			list.at(F) = vec.at(i_min);
			list.at(L) = vec.at(i_max);
			
			F++;
			L--;
		}
	}
	else{
		while(L - F > 1){
			avg = Avg(vec, F, L, &i_min, &i_max, &*count, check);
			list.at(F) = vec.at(i_min);
			list.at(L) = vec.at(i_max);
			
			F++;
			L--;
		}
		
		int index{0};
		bool flag{true};
		while(flag == true){
			*count += 1;
			if(check.at(index) == true){
				list.at(index) = vec.at(index);
				flag = false;
			}
			index++;
		}
	}
	
	vec = list;
}

//void Partition(std::vector<int> &vec, int n, int *count){
//	
//}


int main() {
	
	int n{20};
//	std::cin >> n ;

	std::vector<int> vec;
	int num{0};
	for(int i = n; i > 0; i--){
//		std::cin >> num ;
		num = i;
		vec.push_back(num);
	}


//
	int count{0};
	SORT(vec, n, &count);
	std::cout << "count = " << count << "\n";
	print_Num(vec, 0, n);

	return 0;
}
