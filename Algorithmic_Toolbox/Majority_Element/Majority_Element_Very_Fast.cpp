#include <iostream>
#include <vector>


std::vector<long> tim_sort(std::vector<long> &list, int n){
    long index{0}, count{0};
    // std::vector<long> lst;

    for(int i = 1; i < n; i++){
        index = i;
        for(int j = 1; j <=i; j++){
            count++;
            if (list.at(index) < list.at(i - j)){
                std::swap(list.at(index),list.at(i-j));
                // mediator = list.at(index);
                // list.at(index) = list.at(i-j);
                // list.at(i-j) = mediator;
                index = i-j;
                // for(int k = 0; k < n; k++){
                //     std::cout << list.at(k) << " ";
                // }
                // std::cout << std::endl;
            }
        }

    }
    // std::cout << "Tim_count : " << count << std::endl;
    return list;
}

int divide_and_conquer(const std::vector<long> &vec, int n){

    std::vector<long> list;
    for(int i = 0; i < n; i++){
        list.push_back(vec.at(i));
    }

    list = tim_sort(list, n);

    // for(int i = 0; i < n; i++){
    //     std::cout<<list.at(i)<<" ";
    // }
    // std::cout << std::endl;

    int x{n}, y{n-1}, count{0}, m{n/2}, del{0}, c{0};
    while (x > 0){
        del = list.at(x-1);
        c++;
        while (y >= 0){
            c++;
            if(list.at(y) == del){
                count++;
                list.erase(list.begin() + y);
                x = list.size();
                y = x-1;
            }
            else{
                y -= 1;
            }

        }

        // for(int i = 0; i < x; i++){
        //     std::cout<<list.at(i)<<" ";
        // }
        // std::cout << std::endl;

        x = list.size();
        y = x-1;
        if (count > m){
            // std::cout<<"count : "<< c<<std::endl;
            return 1;
        }
        else{
            count = 0;
        }
    }
    // std::cout<<"count D : "<< c <<std::endl;
    return 0;
}




int main(){

    int n{0};
    std::cin >> n;

    std::vector<long> vec;
    int num{0};
    for(int i = 0; i < n; i++){
        std::cin >> num;
        vec.push_back(num);
    }


    std::cout << divide_and_conquer(vec, n) << std::endl;


    return 0;
}
