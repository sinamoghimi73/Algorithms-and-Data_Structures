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
  
void partition (std::vector<int> &vec, int F, int L, int *p)
{
    int pivot = vec.at(L);
    int i = (F-1);
    for (int j = F; j <= L - 1; j++)
    {
        if (vec.at(j) < pivot)
        {
			i++;
			std::swap(vec.at(i), vec.at(j));
        }
    }
    std::swap(vec.at(i+1), vec.at(L));
	*p = i+1;
}
  
void Quick_Sort(std::vector<int> &vec, int F, int L)
{
	int p{0};
    if (F < L)
    {
        partition(vec, F, L, &p);
        Quick_Sort(vec, F, p - 1);
        Quick_Sort(vec, p + 1, L);
    }
}
  
  
int main()
{
	short n{0};
	std::cin >> n;
	
	std::vector<int> vec;
	int num{0};
	for (short i = 0; i < n; i++){
		std::cin >> num;
		vec.push_back(num);
	}
	
    Quick_Sort(vec, 0, n - 1);
	print_Num(vec, 0, n);
	return 0;
}
