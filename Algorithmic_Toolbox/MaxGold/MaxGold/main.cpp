//
//  main.cpp
//  MaxGold
//
//  Created by Sina Moghimi on 1/21/20.
//  Copyright © 2020 Sina Moghimi. All rights reserved.
//

#include <iostream>
#include <vector>

void partition (std::vector<int> &Weight, int F, int L, int *p)
{
    int pivot = Weight.at(L);
    int i = (F-1);
    for (int j = F; j <= L - 1; j++)
    {
        if (Weight.at(j) < pivot)
        {
			i++;
			std::swap(Weight.at(i), Weight.at(j));
        }
    }
    std::swap(Weight.at(i+1), Weight.at(L));
	*p = i+1;
}
  
void Quick_Sort(std::vector<int> &Weight, int F, int L)
{
	int p{0};
    if (F < L)
    {
        partition(Weight, F, L, &p);
        Quick_Sort(Weight, F, p - 1);
        Quick_Sort(Weight, p + 1, L);
    }
}

void SORT(int n, std::vector<int> &Weight){
	
	Quick_Sort(Weight, 0, n - 1);
	
}

int Bin_Search(int x, std::vector<int> &vec, int *index){
	
	int left{0}, right{(int)(vec.size()-1)}, mid{0};
	bool flag{true};

	while ((((right - left) / 2) > 0)&&(flag == true)){
		mid = left + ((right - left) / 2);

		if (x > vec.at(mid)){
			left = mid;
			mid = left + ((right - left) / 2);
		}

		if (x < vec.at(mid)){
			right = mid;
			mid = left + ((right - left) / 2);
		}

		if (x == vec.at(mid)){
			*index = mid;
			return x;
		}
	}
	
	if(x == vec.at(mid+1)){
		*index = mid+1;
		return x;
	}
	
	return -1;
}


int Max_Gold(int W, int n, std::vector<int> &Weight){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		if(Weight.at(0) <= W){
			return Weight.at(0);
		}
		else{
			return 0;
		}
	}
	
	SORT(n, Weight);
	std::vector<int> WW(n);
	
	int val{0}, rem{0}, x{0}, amount{0}, max{0}, index{0}, max_num{(int)Weight.at(n-1)};
	
	if(max_num == W){
		return W;
	}
	
	int c = n-1;
	
	while((c > -1)&&(Weight.at(c) > W)){
		c--;
	}
	
	if(c == -1){
		return max;
	}
	
	int cc{0}, cc_old{0};
	for(int i = c; i >= 0; i--){
		WW = Weight;
		val = WW.at(i);
		rem = W - val;
		amount = val;
		
		for(int j = i-1; j >= 0; j--){
			cc = WW.at(j);
			while((cc > 0)){
				cc_old = cc;
				x = Bin_Search(cc, WW, &index);
				if((x != -1)&&(amount + x <= W)){
					amount = amount + x;
					cc = W - amount;
					if((cc >= cc_old)&&(j > 0)&&(index > 0)){
						cc = WW.at(j-1);
						j = j - 1;
					}
					else if(j == 0 || index == 0){
						cc = 0;
					}
					
				}
				else{
					cc--;
				}
			}
			if(amount > max){
				max = amount;
			}
			amount = val;
		}
		
		if(amount > max){
			max = amount;
		}
		
	}
	return max;
}


	
	
int main() {

	int W{0};
	std::cin >> W;
		
	int n{0};
	std::cin >> n;
	
	std::vector<int> Weight(n);
	int num{0};
	for(int i = 0; i < n; i++){
		std::cin >> num;
		Weight.at(i) = num;
	}

	std::cout << Max_Gold(W, n, Weight) << std::endl;

	return 0;
}
