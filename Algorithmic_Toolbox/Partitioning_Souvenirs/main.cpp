//
//  main.cpp
//  Partitioning_Souvenirs
//
//  Created by Sina Moghimi on 3/7/20.
//  Copyright © 2020 Sina Moghimi. All rights reserved.
//

#include <iostream>
#include <vector>

int Add(int n, std::vector<int> &vec){
    int sum{};
    
    for(int x : vec)
        sum += x;
    
    return sum;
}

bool Div(std::vector<int> &vec, int n, int a, int b, int c)
{
    if (a == 0 && b == 0 && c == 0)
        return true;

    if (n < 0)
        return false;

    bool A{false};
    if (a - vec.at(n) >= 0)
        A = Div(vec, n - 1, a - vec.at(n), b, c);
        
    bool B{false};
    if (!A && (b - vec.at(n) >= 0))
        B = Div(vec, n - 1, a, b - vec.at(n), c);

    bool C{false};
    if ((!A && !B) && (c - vec.at(n) >= 0))
        C = Div(vec, n - 1, a, b, c - vec.at(n));

    return A || B || C;
}

bool Souvenir(std::vector<int> &vec, int n, int friends_num)
{
    
    if (n < 3)
        return false;
    
    int sum{Add(n, vec)}, each_portion{sum / friends_num};
    return !(sum % 3) && Div(vec, n - 1, each_portion, each_portion, each_portion);
}

int main(){
    int friends_num{3};

    int n{};
    std::cin >> n;


    std::vector<int> vec{};
    int num{};
    for(size_t i{0}; i < n; i++){
        std::cin >> num;
        vec.push_back(num);
    }

    std::cout << Souvenir(vec, n, friends_num) << std::endl;

    return 0;
}

