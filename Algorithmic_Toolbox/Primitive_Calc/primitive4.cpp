//
//  main.cpp
//  Test
//
//  Created by Sina Moghimi on 1/11/20.
//  Copyright © 2020 Sina Moghimi. All rights reserved.
//

#include<iostream>
#include<vector>



std::vector<int> primitive_calculator(int number)
{
    std::vector<int> min_steps(number + 1);
    std::vector<int> predecessor(number + 1);

    for (int i = 2; i <= number; i++) {
        min_steps.at(i) = min_steps.at(i-1) + 1;
        predecessor.at(i) = i - 1;
        if (i % 3 == 0) {
            if (min_steps.at(i/3) < min_steps.at(i)) {
                min_steps.at(i) = min_steps.at(i/3) + 1;
                predecessor.at(i) = i/3;
            }
        }
        if (i % 2 == 0) {
            if (min_steps.at(i/2) < min_steps.at(i)) {
                min_steps.at(i) = min_steps.at(i/2) + 1;
                predecessor.at(i) = i/2;
            }
        }
    }

    std::vector<int> sequence;
    for (int i = number; i != 0; i = predecessor.at(i)) {
        sequence.push_back(i);
    }
	
	return sequence;
}

std::vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 2 == 0) {
      n /= 2;
    } else if (n % 3 == 0) {
      n /= 3;
    } else {
      n = n - 1;
    }
  }
    
  return sequence;
}

int Primitive_count(int n){
    
    int count{0};
    while (n > 1){
        if(n % 2 == 0){
            n /= 2;
            count++;
        }
        else if(n % 3 == 0){
            n /= 3;
            count++;
        }
        else{
            n--;
            count++;
        }
    }
    
    return count;
}

int Primitive_list(int n){

        if(n % 2 == 0){
            n /= 2;
        }
        else if(n % 3 == 0){
            n /= 3;
        }
        else{
            n--;
        }
    
    return n;
}

std::vector<int> Primitive_Calc(int n){
    int a{0}, b{0};
    std::vector<int> list;
    list.push_back(n);
    
    
    while(n > 1){
        
        a = Primitive_count(n);
        b = Primitive_count(n-1) + 1;
        if (b < a){
            n--;
            list.push_back(n);
            n = Primitive_list(n);
        }
        else{
            n = Primitive_list(n);
        }
        list.push_back(n);
    }
    
    return list;
}

int Primitive_count_2(int n){
    
    int count{0};
    while (n > 1){
        if(n % 3 == 0){
            n /= 3;
            count++;
        }
        else if(n % 2 == 0){
            n /= 2;
            count++;
        }
        else{
            n--;
            count++;
        }
    }
    
    return count;
}

int Primitive_list_2(int n){

        if(n % 3 == 0){
            n /= 3;
        }
        else if(n % 2 == 0){
            n /= 2;
        }
        else{
            n--;
        }
    
    return n;
}


std::vector<int> Primitive_Calc_2(int n){
    int a{0}, b{0};
    std::vector<int> list_2;
    list_2.push_back(n);
    
    while(n > 1){
        a = Primitive_count_2(n);
        b = Primitive_count_2(n-1) + 1;
    
        if (b < a){
            n--;
            list_2.push_back(n);
            n = Primitive_list_2(n);
        }
        else{
            n = Primitive_list_2(n);
        }
        list_2.push_back(n);

    }

    return list_2;
}

std::vector<int> Primit(int n){
	int sz_list{0}, sz_seq{0}, sz_seq2{0}, sz_list2{0}, min{0};
    std::vector<int> list = Primitive_Calc(n);
    std::vector<int> list_2 = Primitive_Calc_2(n);
    std::vector<int> sequence = optimal_sequence(n);
	std::vector<int> sequence_2 = primitive_calculator(n);
    
    sz_list = (int)list.size() - 1;
    min = sz_list;
    sz_list2 = (int)list_2.size() - 1;
    if(sz_list2 < min){
        min = sz_list2;
    }
    sz_seq = (int)sequence.size() - 1;
    if(sz_seq < min){
        min = sz_seq;
    }
	sz_seq2 = (int)sequence_2.size() - 1;
    if(sz_seq2 < min){
        min = sz_seq2;
    }
    
//    std::cout << sz_list << ' ' << sz_list2 << ' '<< sz_seq << ' ' << sz_seq2 << std::endl;
    
    
    if(min == sz_list){
//        std::cout << "List\n";
        return list;
    }
    
    else if(min == sz_list2){
//        std::cout << "List_2\n";
        return list_2;
    }
    
    else if(min == sz_seq){
//        std::cout << "Sequence\n";
        return sequence;
    }
	else{
//		std::cout << "Sequence_2\n";
		return sequence_2;
	}

}



int main(){
//    ////////////////////////////////////////////
//    int n{50}, i{1};
//    bool flag = true;
//    while((i > 0)&&(flag == true)){
//        std::cout << i << std::endl;
//
//        std::vector<int> vec = Primit(i);
//
//        int sze{(int) vec.size()};
//
//        std::cout << sze - 1 << std::endl;
//
//        int num{0};
//        for(int i = (sze - 1); i > 0; i--){
//            num = vec.at(i-1) / vec.at(i);
//            if((num < 1)&&(num > 3)){
//                std::cout << "ERROR\n";
//                flag = false;
//            }
//
//            if(vec.at(i-1) == vec.at(i)){
//                std::cout << "ERROR\n";
//                flag = false;
//            }
//         }
//
//    //    for(int i = (sze - 1); i >= 0; i--){
//    //           std::cout << vec.at(i) << ' ';
//    //    }
//        std::cout << std::endl;
//
//        i++;
//    }

    
    
    //////////////////////////////////////////
    int n{0};
    std::cin >> n;

    //////////////////////////////////////////////////
    std::vector<int> vec = Primit(n);

    int sze{(int) vec.size()};

    std::cout << sze - 1 << std::endl;
    for(int i = (sze - 1); i >= 0; i--){
           std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
    

    return 0;
}

