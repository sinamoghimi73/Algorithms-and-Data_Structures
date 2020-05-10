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
                count++;
                std::swap(list.at(index),list.at(i-j));
                // mediator = list.at(index);
                // list.at(index) = list.at(i-j);
                // list.at(i-j) = mediator;
                index = i-j;
                std::cout << std::endl;
            }
        }

    }
    std::cout << "Tim_count : " << count << std::endl;
    return list;
}

int count_Num(std::vector<long> &list, int z, int n){
    int pass{1}, k{1};

    while((list.at(k) > list.at(k-1)) && k < n){
        pass++;
        k++;
        if (k == n){
            return pass;
        }
    }
    return pass;
}

int print_Num(std::vector<long> &list, int z, int n){
    for(int i = z; i < n; i++){
        std::cout << list.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}



int main(){
    // ////////////////////___Stress_Test___////////////////////
    //
    // int i{1},
    // while (i < 2){
    //     int n{100};
    //     std::cout << n << std::endl;
    //     std::vector<long> vec;
    //
    //     for(int i = 0; i < n; i++){
    //         vec.push_back(rand() % 5);
    //         // std::cout << vec.at(i) << " ";
    //     }
    //     std::cout << std::endl;
    //     std::cout << tim_sort(vec, n) << std::endl;
    //     std::cout << "\n" << std::endl;
    //
    //
    //     if ( oR && aNd == 1){
    //         // cout << "WRONG RESULT\n";
    //         // return;
    //         i = 0;
    //     }
    //
    //     i++;
    // }

    /////////////////////////////////////////////////////////

    int n{0};
    std::cin >> n;

    std::vector<long> vec;
    int num{0};
    for(int i = 0; i < n; i++){
        std::cin >> num;
        vec.push_back(num);
    }

    vec = tim_sort(vec, n);
    print_Num(vec, 0, n);


    return 0;
}
