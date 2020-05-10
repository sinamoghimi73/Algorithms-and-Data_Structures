#include <iostream>
#include <vector>


void print_Num(std::vector<long> &vec, int z, int n){
    for(int i = z; i < n; i++){
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;
}


std::vector<long> SinEl(std::vector<long> vec, int n){
    long max{0}, sz{0};

    for(int i = 0; i < n; i++){
        // std::cout << vec.at(i) << ' ';
        if(vec.at(i) > max){
            max = vec.at(i);
        }
    }

    if(n > max){
        sz = n;
    }
    else{
        sz = max;
    }

    std::vector<bool> v(sz+1, false);
    long x{0};

    for(int i = 0; i < n; i++){
        x = vec.at(i);
        v.at(x) = true;
    }


    std::vector<long> sort;
    for(int i = 0; i < sz+1; i++){
        if(v.at(i) == true){
            sort.push_back(i);
        }
    }

   return sort;
}


int main(){


    // ////////////////////___Stress_Test___////////////////////

    int i{1};
    int flag{1}, max{0}, min{0};
    while (i < 10){
        int n{10};
        // std::cout << n << std::endl;
        std::vector<long> vec;
        std::vector<long> vec_2;

        int Num{0};
        for(int i = 0; i < n; i++){
            Num = 5;
            vec.push_back(Num);
            vec_2.push_back(Num);
            // std::cout << vec.at(i) << " ";
        }

        std::vector<long> sort_SinEl;
        std::cout << std::endl;
        sort_SinEl = SinEl(vec, n);

        print_Num(sort_SinEl, 0, n);


        sort(vec_2.begin(), vec_2.end());
        // print_Num(vec_2, 0, n);

        for(int i = 0; i < n; i++){
            // std::cout << vec_2.at(i) - vec.at(i) << ' ';
            if(vec_2.at(i) - sort_SinEl.at(i) != 0){
                flag = 0;
                std::cout << "i = " << i << std::endl;
            }
        }
        if (flag == 0){
            print_Num(vec_2, 0, n);
            print_Num(sort_SinEl, 0, n);
        }

        std::cout << "\n" << std::endl;

        i++;
    }

    ///////////////////

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
    //
    // std::vector<long> sort;
    // sort = SinEl(vec, n);
    // print_Num(sort, 0, n);






    return 0;
}
