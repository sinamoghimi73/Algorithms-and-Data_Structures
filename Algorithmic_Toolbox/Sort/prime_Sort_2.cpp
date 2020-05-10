#include <iostream>
#include <vector>


void print_Num(std::vector<long> &vec, int z, int n){
    for(int i = z; i < n; i++){
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}

std::vector<long> SieveOfEratosthenes(int n) {
    std::vector<bool> vec(n, true);
    std::vector<long> prime;

    vec.at(1) = false;

    for(int i = 2; (i*i) < n; i++){
        if(vec.at(i) == true){
            for(int j = i*2; j < n; j+=i){
                vec.at(j) = false;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(vec.at(i) == true){
            prime.push_back(i);
        }
    }

   return prime;
}

long Mean(std::vector<long> &vec, int a, int b){
    long mean{0}, add{0};
    for(int i = a; i < b; i++){
        add = add + vec.at(i);
    }
    mean = add / (b - a);

    return mean;
}


int Modified_Binary_Search(const std::vector<long> &vec, long x, int n){
    int left{0}, right{(int)(n)}, mid{0};

    if(n == 1){
        right = 2;
    }

    while (((right - left) / 2) > 0){
        if(x < vec.at(left)){
            // std::cout << "Left\n";
            return left;
        }
        if(x > vec.at(right)){
            // std::cout << "Right\n";
            return right;
        }

        mid = left + ((right - left) / 2);

        if (x >= vec.at(mid)){
            left = mid;
            mid = left + ((right - left) / 2);
        }

        if (x < vec.at(mid)){
            right = mid;
            return right;
            mid = left + ((right - left) / 2);
        }

        // if (x == vec.at(mid)){
        //     return -2;
        // }
    }
    return -1;
}



int Point(std::vector<long> &vec, int a, int n){
    int i{a + 1};
    while(i < n){
        if(vec.at(i) < vec.at(i-1)){
            return i;
        }
        i++;
    }
    return n-1;
}

std::vector<long> Mean_sort(std::vector<long> &vec, int n){
    std::vector<long> prime;


    prime = SieveOfEratosthenes(n);
    prime.push_back(n);

    int i{0};
    long mean{0};
    std::vector<long> mid;
    while(i+1 < prime.size()){
        mean = Mean(vec, prime.at(i), prime.at(i+1));
        mid.push_back(mean);
        i++;
    }

    // print_Num(mid, 0, mid.size());
    mean = Mean(mid, 0, mid.size());

    long max{0};
    for(int i = 0; i < mid.size(); i++){
        if(mid.at(i) > max){
            max = mid.at(i);
        }
    }

    long min{max+1};
    int index{0};
    std::vector<long> naive_sort;

    for(int j = 0; j < mid.size(); j++){
        for(int i = 0; i < mid.size(); i++){
            if(mid.at(i) < min){
                min = mid.at(i);
                index = i;
            }
        }
        mid.at(index) = max + 1;
        min = max+1;

        for(long k = prime.at(index); k < prime.at(index + 1); k++){
            naive_sort.push_back(vec.at(k));
        }
    }

    // print_Num(naive_sort, 0, naive_sort.size());

    return naive_sort;
}

int Prime_loop(std::vector<long> &vec, int m, int a, int n){
    long index{0}, count{0}, check_index{0};

    if(m == 1){
        for(int i = 0; i < 2; i++){
            index = i;
            check_index = index + 2;
            while(check_index < n){
                if(vec.at(index) > vec.at(check_index)){
                    std::swap(vec.at(index), vec.at(check_index));
                    // print_Num(vec, 0, vec.size());
                }
                check_index += 2;
                count++;
            }
        }

        // int k{a};
        // while(k+1 < n){
        //     index = k;
        //     check_index = index + 1;
        //
        //     if(vec.at(index) > vec.at(check_index)){
        //         std::swap(vec.at(index), vec.at(check_index));
        //         // print_Num(vec, 0, vec.size());
        //     }
        //     count++;
        //     check_index += 1;
        //     k++;
        // }



    }
    else{
        for (int i = a; i < n; i++){
            index = i;
            check_index = i+m;
            // if (n - index == 2){
            //     if (vec.at(index) > vec.at(n-1)){
            //         std::swap(vec.at(index), vec.at(n-1));
            //     }
            // }
            while((check_index < n) && (vec.at(index) > vec.at(check_index))){
                std::swap(vec.at(index), vec.at(check_index));
                // print_Num(vec, 0, vec.size());
                check_index += m;
                count++;
            }
        }
    }

    return count;
}

int Prime_sort(std::vector<long> &vec, int n){
    std::vector<long> prime;

    vec = Mean_sort(vec, n);

    prime = SieveOfEratosthenes(n);


    int count{0};
    for (int i = prime.size()-1; i >= 0 ; i--){
        count += Prime_loop(vec, prime.at(i), 0, n);
    }

    for (int i = 0; i < prime.size() ; i++){
        count += Prime_loop(vec, prime.at(i), 0, n);
    }

    // count += Prime_loop(vec, 1, 0, n);

    int point{0}, check{0};

    while(point < n){
        point = Point(vec, 0, n);


        // count += point;


        check = Modified_Binary_Search(vec, vec.at(point), point);
        if (check == -1){
            return count;
        }
        // print_Num(vec, 0, n);
        // std::cout << point << ' ' << check << std::endl;
        std::swap(vec.at(point), vec.at(check));
    }



    return count;
}



























int main(){


    // ////////////////////___Stress_Test___////////////////////

    // int i{1};
    // int flag{1}, max{0}, min{0};
    // while (flag == 1){
    //     int n{100};
    //     // std::cout << n << std::endl;
    //     std::vector<long> vec;
    //     std::vector<long> vec_2;
    //
    //     int Num{0};
    //     for(int i = 0; i < n; i++){
    //         Num = rand();
    //         vec.push_back(Num);
    //         vec_2.push_back(Num);
    //         // std::cout << vec.at(i) << " ";
    //     }
    //
    //
    //
    //     // std::vector<long> sort_prime;
    //     // std::cout << std::endl;
    //     max =  Prime_sort(vec, n);
    //     if(max > min){
    //         min = max;
    //     }
    //
    //     std::cout << "MAX : " << min << std::endl;
    //
    //     // print_Num(vec, 0, n);
    //
    //
    //     sort(vec_2.begin(), vec_2.end());
    //     // print_Num(vec_2, 0, n);
    //
    //     for(int i = 0; i < n; i++){
    //         // std::cout << vec_2.at(i) - vec.at(i) << ' ';
    //         if(vec_2.at(i) - vec.at(i) != 0){
    //             flag = 0;
    //             std::cout << "i = " << i << std::endl;
    //         }
    //     }
    //     if (flag == 0){
    //         print_Num(vec_2, 0, n);
    //         print_Num(vec, 0, n);
    //     }
    //
    //     std::cout << "\n" << std::endl;
    //
    //     i++;
    // }

    ///////////////////

    int n{0};
    std::cin >> n;

    std::vector<long> vec;
    long num{0};
    for(int i = 0; i < n; i++){
        std::cin >> num;
        vec.push_back(num);
    }

    // std::vector<long> sort;
    Prime_sort(vec, n);
    print_Num(vec, 0, n);

}
