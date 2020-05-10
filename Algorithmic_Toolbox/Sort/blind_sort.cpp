#include <iostream>
#include <vector>


void print_Num(std::vector<long> &vec, int z, int n){
    for(int i = z; i < n; i++){
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}

std::vector<long> SieveOfEratosthenes(int n){
    std::vector<bool> vec(n, true);
    std::vector<long> prime;


    for(int i = 2; (i*i) < n; i++){
        if(vec.at(i) == true){
            for(int j = i*2; j < n; j+=i){
                vec.at(j) = false;
            }
        }
    }

    for(int i = 2; i < n; i++){
        if(vec.at(i) == true){
            prime.push_back(i);
        }
    }

   return prime;
}


std::vector<long> SinEl(std::vector<long> vec, int n){
    int max{0};
    for(int i = 0; i < n; i++){
        if(vec.at(i) > max){
            max = vec.at(i);
        }
    }

    std::vector<bool> v(max, false);
    long x{0};

    for(int i = 0; i < n; i++){
        x = vec.at(i);
        v.at(x) = true;
    }

    std::vector<long> sort;

    for(int i = 0; i < max; i++){
        if(vec.at(i) == true){
            sort.push_back(i);
        }
    }


   return sort;
}



int Sina_loop(std::vector<long> &vec, int m, int a, int n){
    long index{a+1}, count{a}, check_index{0}, point{0}, i{1};

    if(m == 1){
        while(i < n){
            if (vec.at(i) < vec.at(i-1)){
                std::swap(vec.at(i), vec.at(i-1));
            }
            i++;
        }
        return i;
    }

    else{
        for (int i = a; i < m; i++){
            index = i;
            check_index = m;
            if (n - index == 2){
                if (vec.at(index) > vec.at(n-1)){
                    std::swap(vec.at(index), vec.at(n-1));
                }
            }
            while((check_index < n) && (vec.at(index) > vec.at(check_index))){
                std::swap(vec.at(index), vec.at(check_index));
                check_index += m;
                count++;
            }
            // count++;
            // check_index = 0;

        }
    }

    return count;
}


int Blind_Sort(std::vector<long> &vec, int n){
    int count{0}, check_index{0}, index{0}, k{1};
    long p{0};
    std::vector<long> prime;
    prime = SieveOfEratosthenes(n);

    for(int i = 0; i < prime.at(prime.size() -1); i++){
        index = i;

        for(int j = prime.size() -1; j >=0; j--){
            if(prime.at(j) > i){
                p = prime.at(j);
                check_index = index + p;
                while(check_index < n){
                    if(vec.at(i) > vec.at(check_index)){
                        std::swap(vec.at(i), vec.at(check_index));
                        k++;
                    }
                    // k++;
                    check_index += p;
                }
            }

        }

    }


    k += Sina_loop(vec, 1, prime.at(prime.size() -1) - 1, n);
    k += Sina_loop(vec, 1, 0, n);
    // std::cout << k <<std::endl;
    return k;
}
















int main(){

    // ////////////////////___Stress_Test___////////////////////

    int i{1};
    int flag{1}, max{0}, min{0};
    while (flag == 1 && i < 2){
        int count{0};
        int n{100};
        // std::cout << n << std::endl;
        std::vector<long> vec;
        std::vector<long> vec_2;
        std::vector<long> prime;

        int Num{0};
        for(int i = 0; i < n; i++){
            Num = rand() % 100;
            vec.push_back(Num);
            vec_2.push_back(Num);
            // std::cout << vec.at(i) << ' ';
        }

        std::cout << std::endl;

        vec = SinEl(vec, n);
        print_Num(vec, 0, n);
        // print_Num(prime,0,prime.size());
        //
        // count += Blind_Sort(vec, n);
        // // //
        // max = count;
        // if(max >= min){
        //     min = max;
        // }
        // std::cout << "MAX = " << min << std::endl;
        // std::cout <<"\n\n";
        //
        //
        // // print_Num(vec, 0, n);
        //
        //
        // sort(vec_2.begin(), vec_2.end());
        // print_Num(vec_2, 0, n);
        //
        // for(int i = 0; i < n; i++){
        //     // std::cout << vec_2.at(i) - vec.at(i) << ' ';
        //     if(vec_2.at(i) - vec.at(i) != 0){
        //         flag = 0;
        //         std::cout << "i = " << i << std::endl;
        //     }
        // }
        // if (flag == 0){
        //     // print_Num(vec_2, 0, n);
        //     print_Num(vec, 0, n);
        // }
        //
        // std::cout << "\n" << std::endl;

        i++;
    }

    /////////////////////////////////////////////////////////



    // int n{0};
    // std::cin >> n;
    //
    // std::vector<long> vec;
    // long num{0};
    // for(int i = 0; i < n; i++){
    //     std::cin >> num;
    //     vec.push_back(num);
    // }
    //
    // Sina_sort(vec, n);
    //
    // for (size_t i = 0; i < vec.size(); ++i){
    //   std::cout << vec.at(i) << ' ';
    // }
    // // std::cout<<std::endl;


    return 0;
}
