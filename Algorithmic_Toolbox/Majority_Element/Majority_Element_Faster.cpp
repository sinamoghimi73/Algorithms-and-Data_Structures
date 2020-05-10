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

    // int m(n), ten(0), five(0), one(0);
    //
    // ten = m / 10;
    // m -= ten *10;
    //
    // five = m /5;
    // m -= five * 5;
    //
    // one = m;
    // m -= one;

///////////////////////////////////////////////////////

    int m{n/2};
    int o{n-m};

    std::vector<long> list1;
    std::vector<long> list2;
    for (int i = 0; i < m; i++){
        list1.push_back(vec.at(i));
    }
    for (int i = m; i < n; i++){
        list2.push_back(vec.at(i));
    }
/////////////////////////////////////////////////
    list1 = tim_sort(list1,m);
    // for (int i = 0; i < m; i++){
    //     std::cout << list1.at(i) << " ";
    // }
    // std::cout << "\n\n";
/////////////////////////////////////////////////
    list2 = tim_sort(list2,o);
    // for (int i = 0; i < o; i++){
    //     std::cout << list2.at(i) << " ";
    // }
    // std::cout << "\n\n";
///////////////////////////////////////////////
    int count2{0}, count1{0}, c{0};
    for(int i = 0; i < m; i++){

        for(int k = 0; k < m; k++){
            c++;
            if(list1.at(k) == list1.at(i)){
                count1++;
            }
        }

        for(int j = 0; j < o; j++){
            c++;
            if (list2.at(j)==list1.at(i)){
                count2++;
            }
        }

        if(count1 + count2 > m){
            std::cout<<"Steps : " << c <<std::endl;
            return 1;
        }

        else{
            count2 = 0;
            count1 = 0;
        }
    }
    std::cout<<"Steps : " << c <<std::endl;
    return 0;
}


int Majority_Element(const std::vector<long> &vec, int n){
    int Num{0};
    Num = divide_and_conquer(vec, n);
    // const int half{n/2};
    //
    // if (n < 2){
    //     return 1;
    // }
    //
    // int count{1}, c{0}, Num{0};
    // std::vector<long> list;
    //
    // for(int i = 1; i < n; i++){
    //     if (vec.at(i) == vec.at(i-1)){
    //         count++;
    //     }
    //     else{
    //         c = c + count;
    //         count = 1;
    //     }
    //
    //     if(count > half){
    //         Num = vec.at(i);
    //         return 1;
    //     }
    //
    // }
    return Num;
}


int main(){
    ////////////////////___Stress_Test___////////////////////

    int i{1};
    while (i > 0){
        int n{50};
        std::cout << n << std::endl;
        std::vector<long> vec;

        for(int i = 0; i < n; i++){
            vec.push_back(rand() % 5);
            std::cout << vec.at(i) << " ";
        }
        std::cout << std::endl;
        std::cout << Majority_Element(vec, n) << std::endl;
        std::cout << "#################################\n" << std::endl;
        if (Majority_Element(vec, n) == 1){
            i = 0;
        }
        // i++;
    }

    /////////////////////////////////////////////////////////

    // int n{0};
    // std::cin >> n;
    //
    // std::vector<long> vec;
    // int num{0};
    // for(int i = 0; i < n; i++){
    //     std::cin >> num;
    //     vec.push_back(num);
    // }
    //
    // std::cout << Majority_Element(vec, n) << std::endl;
    //

    return 0;
}
