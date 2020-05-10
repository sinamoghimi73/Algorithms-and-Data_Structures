#include <iostream>
#include <vector>

int LCS2S(int n, std::vector<long> &Seq_1, int m, std::vector<long> &Seq_2){
    int min{0};
    for(size_t i = 0; i < n; i++){
        if(Seq_1.at(i) < min){
            min = Seq_1.at(i);
        }
    }
    for(size_t i = 0; i < m; i++){
        if(Seq_2.at(i) < min){
            min = Seq_2.at(i);
        }
    }
    min--;
    
    int max{0}, count{0}, com{0};
    max = std::max(m, n);
    
    for(size_t i = 0; i < (max - n); i++){
        Seq_1.push_back(min);
    }
    
    min--;
    
    for(size_t i = 0; i < (max - m); i++){
        Seq_2.push_back(min);
    }

    
    
    std::vector<bool> list(max, false);
    
            for(size_t i = 1; i <= max; i++){
                for(size_t j = 0; j < i; j++){
                    if(Seq_1.at(j) == Seq_2.at(max - i + j)){
                        list.at(j) = true;
                    }
                }


                for(size_t l = 0; l < max; l++){
                    if(list.at(l) == true){
                        count++;
                    }
                }

                if(count > com){
                    com = count;
                }
        //        std::cout << "com : " << com << std::endl;

                for(size_t j = 0; j < max; j++){
                    list.at(j) = false;
                }

                count = 0;
            }
//
        ///////////////////////////////////////////////////////
        
        for(size_t i = 0; i < max; i++){
                for(size_t j = i; j < max; j++){
                    if(Seq_1.at(j) == Seq_2.at(j - i)){
                        list.at(j) = true;
                    }
                }


                for(size_t l = 0; l < max; l++){
                    if(list.at(l) == true){
                        count++;
                    }
                }

                if(count > com){
                    com = count;
                }
//                std::cout << "com : " << com << std::endl;

                for(size_t j = 0; j < max; j++){
                    list.at(j) = false;
                }

                count = 0;
            }
    
    return com;
}


int main(){
    int n{0};
    std::cin >> n;

    std::vector<long> Seq_1(n);
    for(size_t i = 0; i < n; i++){
        std::cin >> Seq_1.at(i);
    }

    int m{0};
    std::cin >> m;

    std::vector<long> Seq_2(m);
    for(size_t i = 0; i < m; i++){
        std::cin >> Seq_2.at(i);
    }

    std::cout << LCS2S(n, Seq_1, m, Seq_2) << std::endl;

    return 0;
}
