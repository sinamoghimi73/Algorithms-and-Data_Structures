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

int Sina_loop(std::vector<long> &list, int m, int n){
    long index{0}, count{0}, check_index{0};
    if (m == 1){
        long index{0}, count{0}, check_index{0};
        for (int i = 0; i < n-1; i++){
            index = i;
            check_index = i+m;
            if (n - index == 2){
                if (list.at(index) > list.at(n-1)){
                    std::swap(list.at(index), list.at(n-1));
                }
            }
            while((check_index < n)){
                if((list.at(index) > list.at(check_index))){
                    std::swap(list.at(index), list.at(check_index));
                }
                check_index += m;
                count++;
            }
            // check_index = 0;
        }
    }
    else{
        for (int i = 0; i < n-1; i++){
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
            // check_index = 0;
        }
    }

    return count;
}

int decim(std::vector<long> &list, int n){
    int d{-1}, m{n};
    while(m > 0){
        m = m / 10;
        d++;
    }
    return d;
}

unsigned int Power(int Num, int d){
    long power{1};

    for(int i = 0; i < d; i++){
        power *= 10;
    }

    return power;
}

std::vector<long> SieveOfEratosthenes(int n) {
   bool pno[n+1];
   std::vector<long> prime;
   int count{0};
   memset(pno, true, sizeof(pno));
   for (int i = 2; i*i<= n; i++) {
      if (pno[i] == true) {
         for (int j = i*2; j<= n; j += i)
            pno[j] = false;
            count++;
      }
      count++;
   }
   for (int i = 2; i<= n; i++){
      if (pno[i]){
          prime.push_back(i);
      }
  }
     return prime;
}

int Sina_sort(std::vector<long> &vec, int n){
    int count{0};
    int d{0};
    // int m{n};
    // unsigned int p{0};

    std::vector<long> prime;

    // prime = SieveOfEratosthenes(n);
    prime = SieveOfEratosthenes(n);


    for (int i = prime.size()-1; i >= 0 ; i--){
        count += Sina_loop(vec, prime.at(i), n);
        count += Sina_loop(vec, 1, n);
        // std::cout<<prime.at(i)<<" ";
    }


    d = decim(vec, n);



    // for(int i = 1; i <= d*d; i+=d){
    //     count += Sina_loop(vec, i, n);
    // }

    count += Sina_loop(vec, 1, n);
    // count += Sina_loop(vec, 1, n);
    // std::cout<<"\n";


    // d = decim(list, n);
    // for(int i = d - 1; i > 0; i--){
    //     p = Power(10, i);
    //     count += Sina_loop(list, p, n);
    // }

    // std::cout << "Sina_count : " << count + n << std::endl;
    return count + n;
}

int main(){
    // ////////////////////___Stress_Test___////////////////////

    int i{1};
    int flag{1}, max{0}, min{0};
    while (flag == 1){
        int n{5};
        // std::cout << n << std::endl;
        std::vector<long> vec;
        std::vector<long> vec_2;

        int Num{0};
        for(int i = 0; i < n; i++){
            Num = rand() % 100;
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
    // int num{0};
    // for(int i = 0; i < n; i++){
    //     std::cin >> num;
    //     vec.push_back(num);
    // }
    //
    // vec = Sina_sort(vec, n);
    // print_Num(vec, 0, n);


    return 0;
}
