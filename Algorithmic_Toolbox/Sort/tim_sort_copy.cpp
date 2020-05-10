#include <iostream>
#include <vector>

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

void print_Num(std::vector<long> &list, int z, int n){
    for(int i = z; i < n; i++){
        std::cout << list.at(i) << " ";
    }
    std::cout << std::endl;
}

int Bin(std::vector<long> &list, int z, int x){
    int count{0};
    int left{z}, right{(int)(list.size()-1)}, mid{0};

    while (((right - left) / 2) > 0){
        count++;
        mid = left + ((right - left) / 2);

        if (x > list.at(mid)){
            return mid;
        }

        if (x < list.at(mid)){
            count++;
            right = mid;
            mid = left + ((right - left) / 2);
        }
    }
    return -1;
}

std::vector<long> tim_sort(std::vector<long> &list, int n){
    long index{0}, count{0}, check_index{0};
    // std::vector<long> lst;

    for (int i = 1; i < n; i++){
        index = i;
        check_index = index - 1;
        while ( (check_index >= 0) && (list.at(index) < list.at(check_index)) ){
            std::swap(list.at(index) , list.at(check_index));
            index = check_index;
            check_index--;
            count++;
            print_Num(list, 0, n);
        }
    }
    std::cout << "Tim_count : " << count + n << std::endl;
    return list;
}

int main(){
    // ////////////////////___Stress_Test___////////////////////

    int i{1};
    while (i < 2){
        int n{8};
        std::cout << n << std::endl;
        std::vector<long> vec;

        for(int i = 0; i < n; i++){
            vec.push_back(n-i);
            // std::cout << vec.at(i) << " ";
        }
        std::cout << std::endl;
        // std::cout << tim_sort(vec, n) << std::endl;
        vec = tim_sort(vec, n);
        print_Num(vec, 0, n);
        std::cout << "\n" << std::endl;


        // if ( oR && aNd == 1){
        //     // cout << "WRONG RESULT\n";
        //     // return;
        //     i = 0;
        // }

        i++;
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
    // vec = tim_sort(vec, n);
    // print_Num(vec, 0, n);


    return 0;
}
