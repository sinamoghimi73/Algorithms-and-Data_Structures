#include <iostream>
#include <vector>

int max(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}



int naive_LCS2S(int n, std::vector<long> &Seq_1, int m, std::vector<long> &Seq_2){
    std::vector<std::vector<long>> L((n+1),std::vector<long> (m+1, 0));
    std::vector<long> list;
    for (size_t i = 0; i <= n; i++){
        for(size_t j = 0; j <= m; j++){
            if((i == 0) || (j == 0)){
                L.at(i).at(j) = 0;
            }
            else if(Seq_1.at(i - 1) == Seq_2.at(j - 1)){
                L.at(i).at(j) = L.at(i-1).at(j-1) + 1;
            }
            else{
                L.at(i).at(j) = max(L.at(i-1).at(j), L.at(i).at(j-1));
            }
        }
    }
            
    return L.at(n).at(m);
}

int main(){
//    ///////////////////////////////////////////////

    
    
//    ///////////////////////////////////////////////
    
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
    
    int sze{0};
    sze = naive_LCS2S(n, Seq_1, m, Seq_2);
    
    std::cout << sze << std::endl;

    return 0;
}
