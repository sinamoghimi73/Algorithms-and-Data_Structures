#include <iostream>
#include <vector>
#include <cmath>

void print_Num(std::vector<long> &vec, int z, int n){
    for(int i = z; i < n; i++){
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}

int Modified_Binary_Search(const std::vector<long> &vec, long x, int n){
    int left{0}, right{(int)(n)}, mid{0};

    if(n == 1){
        return 0;
    }

    while (((right - left) / 2) > 0){
        mid = left + ((right - left) / 2);
        if (x > vec.at(mid)){
            left = mid;
            mid = left + ((right - left) / 2);
        }

        if (x <= vec.at(mid)){
            right = mid;
            return right;
            // mid = left + ((right - left) / 2);
        }

        // if (x == vec.at(mid)){
        //     return mid;
        // }
    }
    return -1;
}

int Sina_loop(std::vector<long> &vec, int m, int a, int n){
    long index{a+1}, count{a}, check_index{0}, point{0}, i{0};
    // std::cout<<index<<std::endl;
    if(m == 1){
        while(index<n){
            check_index = index-1;
            // std::cout << "i "<<i<<std::endl;
            if (vec.at(index) < vec.at(check_index)){
                point = index;
                // std::cout << "point : "<< index<<"\n";
                return point ;
            }
            // std::cout<<vec.at(i)<<std::endl;
            count++;
            index++;
            i++;
            if (i == n-1){
                return -2;
            }
        }
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


std::vector<long> SieveOfEratosthenes(int n) {
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


int partial_sort(std::vector<long> &vec, int z, int n){
    int index{z+1}, old_index{0}, correct_point{z+1}, c{0}, cc{1}, count{0};
    z = 0;

    while(c < n/2){
        while(correct_point < n){
            if(correct_point > z){
                old_index = correct_point;
            }
            if(vec.at(correct_point) == vec.at(index)){
                std::swap(vec.at(index), vec.at(correct_point+1));
                // return count;
            }


            index = Sina_loop(vec, 1, 0 , n);
            if(index == -2){
                return count;
            }
            count += n - old_index;
            correct_point = Modified_Binary_Search(vec, vec.at(index), index);

            if((index == n-1 && correct_point == -1)||(index == z && correct_point == -1)){
                return count;
            }


            if(correct_point != -1){
                if((index != correct_point)){
                    cc++;
                    std::swap(vec.at(index), vec.at(correct_point));
                }
            }
            // index = old_index;
        }
        c++;
        cc = 1;
    }
    return count;
}


int Sina_sort(std::vector<long> &vec, int n){
    int count{0};
    std::vector<long> prime;

    prime = SieveOfEratosthenes(n);
    prime.push_back(1);

    // print_Num(prime, 0, prime.size());

    // std::cout << "From : "<< prime.at(prime.size()-1) << " To : " << n << std::endl;
    // count += partial_sort(vec, prime.at(prime.size()-1), n);
    //
    for (int i = prime.size()-1; i >= 0 ; i--){
        count += Sina_loop(vec, prime.at(i), 0, n);
    }

    // for (int i = prime.size()-1; i >= 0 ; i--){
    //     if(i-1 >= 2){
    //         count += partial_sort(vec, prime.at(i-1), prime.at(i));
    //     }
    // }
    // count += partial_sort(vec, 0, n);
    // count += Sina_loop(vec, 1, 0, n);

    return count;
}

int main(){

    // ////////////////////___Stress_Test___////////////////////

    int i{1};
    int flag{1}, max{0}, min{0};
    while (flag == 1){
        int n{1000};
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
        std::cout <<"\n\n";


        print_Num(vec, 0, n);


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
