#include <iostream>
#include <vector>

void print_Num(std::vector<long> &list, int z, int n){
    for(int i = z; i < n; i++){
        std::cout << list.at(i) << " ";
    }
    std::cout << std::endl;
}

int Sina_loop(std::vector<long> &list, int m, int n){
    long index{0}, count{0}, check_index{0}, finish{0};
    if (m == 1){
        for(int i = 1; i<n; i+=2){
            if (i+1 < n){
                if((list.at(i+1) < list.at(i))){
                    std::swap(list.at(i+1), list.at(i));
                    finish++;
                }
                if((list.at(i+1) < list.at(i-1))){
                    std::swap(list.at(i+1), list.at(i-1));
                    finish++;
                }
                if((list.at(i) < list.at(i-1))){
                    std::swap(list.at(i), list.at(i-1));
                    finish++;
                }

            }
            else{
                if((list.at(i) < list.at(i-1))){
                    std::swap(list.at(i), list.at(i-1));
                    finish++;
                }
            }
        }
        return finish;
    }
    else{
        for (int i = 0; i < m; i++){
            index = i;
            check_index = i+m;
            if (n - index == 2){
                if (list.at(index) > list.at(n-1)){
                    std::swap(list.at(index), list.at(n-1));
                }
            }
            while((check_index < n) && (list.at(index) > list.at(check_index))){
                std::swap(list.at(index), list.at(check_index));
                check_index += m;
                count++;
            }
            // count++;
            // check_index = 0;
        }
    }
    // std::cout << "finish = " << finish << std::endl;
    return count;
}

std::vector<long> SieveOfEratosthenes(int n) {
    std::vector<bool> list(n, true);
    std::vector<long> prime;

    for(int i = 2; (i*i) < n; i++){
        if(list.at(i) == true){
            for(int j = i*2; j < n; j+=i){
                list.at(j) = false;
            }
        }
    }

    for(int i = 2; i < n; i++){
        if(list.at(i) == true){
            prime.push_back(i);
        }
    }

   return prime;
}

int Sina_sort(std::vector<long> &vec, int n){
    int count{0}, finish{0};
    std::vector<long> prime;

    prime = SieveOfEratosthenes(n);

    for (int i = prime.size()-1; i >= 0 ; i--){
        count += Sina_loop(vec, prime.at(i), n);
        finish = Sina_loop(vec, 1, n);

        if(finish == n-1){
            return count +finish + n;
        }
    }

    return count + n;
}

int main(){

    // ////////////////////___Stress_Test___////////////////////

    int i{1};
    int flag{1}, max{0}, min{0};
    while (flag == 1){
        int n{10};
        // std::cout << n << std::endl;
        std::vector<long> vec;
        std::vector<long> vec_2;

        int Num{0};
        for(int i = 0; i < n; i++){
            Num = rand() % 1000;
            vec.push_back(Num);
            vec_2.push_back(Num);
            // std::cout << vec.at(i) << " ";
        }

        std::cout << std::endl;
        max = Sina_sort(vec, n);
        if(max >= min){
            min = max;
        }
        std::cout << "MAX = " << min << std::endl;


        // print_Num(vec, 0, n);


        sort(vec_2.begin(), vec_2.end());
        // print_Num(vec_2, 0, n);

        for(int i = 0; i < n; i++){
            // std::cout << vec_2.at(i) - vec.at(i) << ' ';
            if(vec_2.at(i) - vec.at(i) != 0){
                flag = 0;
                std::cout << "i = " << i << std::endl;
            }
        }
        if (flag == 0){
            // print_Num(vec_2, 0, n);
            print_Num(vec, 0, n);
        }

        std::cout << "\n" << std::endl;

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
