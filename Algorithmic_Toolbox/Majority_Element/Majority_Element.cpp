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


int Majority_Element(const std::vector<long> &vec, int n){
    int half{n/2};

    if (n < 2){
        return 1;
    }

    std::vector<long> list;
    std::vector<long> lst;
    for (int i = 0; i < n; i++){
        list.push_back(vec.at(i));
        // lst.push_back(vec.at(i));
    }
/////////////////////////////////////////////////
    list = tim_sort(list,n);
    // for (int i = 0; i < n; i++){
    //     std::cout << list.at(i) << " ";
    // }
    // std::cout << "\n\n";
/////////////////////////////////////////////////
    // list = srt(lst, n);
    // for (int i = 0; i < n; i++){
    //     std::cout << list.at(i) << " ";
    // }
    // std::cout << "\n\n";
/////////////////////////////////////////////////
    // sort(list.begin(),list.end());

    int count{1},c{0};
    for(int i = 1; i < n; i++){
        if (list.at(i) == list.at(i-1)){
            count++;
        }
        else{
            c = c + count;
            count = 1;
        }

        if(count > half){
            return 1;
        }

    }
    return 0;
}


int main(){
    ////////////////////___Stress_Test___////////////////////

    // int i{1};
    // while (i > 0){
    //     int n{5};
    //     std::cout << n << std::endl;
    //     std::vector<long> vec;
    //
    //     for(int i = 0; i < n; i++){
    //         vec.push_back(rand() % 10);
    //         std::cout << vec.at(i) << " ";
    //     }
    //     std::cout << std::endl;
    //     std::cout << Majority_Element(vec, n) << std::endl;
    //     std::cout << "#################################\n" << std::endl;
    //     if (Majority_Element(vec, n) == 1){
    //         i = 0;
    //     }
    //     // i++;
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

    std::cout << Majority_Element(vec, n) << std::endl;


    return 0;
}
