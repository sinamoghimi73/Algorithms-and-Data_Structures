#include <iostream>
#include <vector>


int Binary_Search(const std::vector<int> &vec, int x){
    int left{0}, right{(int)(vec.size()-1)}, mid{0};

    while (((right - left) / 2) > 0){
        mid = left + ((right - left) / 2);
        // std::cout << vec.at(mid) << "\n";
        if (x > vec.at(mid)){
            left = mid;
            mid = left + ((right - left) / 2);
        }

        if (x < vec.at(mid)){
            right = mid;
            mid = left + ((right - left) / 2);
        }

        if (x == vec.at(mid)){
            return mid;
        }
    }
	if(x == vec.at(mid+1)){
		return mid+1;
	}
	
    return -1;
}


int main(){
    int n{0};
    std::cin >> n;

    std::vector<int> vec(0);
    int num{0};
    for(int i = 0; i < n; i++){
        std::cin >> num;
        vec.push_back(num);
    }

    // std::cout << Binary_Search(vec, 5) << " ";

    int m{0};
    std::cin >> m;

//    std::vector<int> num_to_find(0);
//    // int num{0};
//    for(int i = 0; i < m; i++){
//        std::cin >> num;
//        num_to_find.push_back(num);
//    }
//
//    for(int i = 0; i < m; i++){
//        std::cout << Binary_Search(vec, num_to_find.at(i)) << " ";
//    }
	std::cout << Binary_Search(vec, m) << " ";


    return 0;
}
