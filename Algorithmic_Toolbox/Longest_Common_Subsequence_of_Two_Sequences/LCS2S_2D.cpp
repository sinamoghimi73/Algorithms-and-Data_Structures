#include <iostream>
#include <vector>



int LCS2S_2D(int n, std::vector<long> &Seq_1, int m, std::vector<long> &Seq_2){
    
    std::vector<std::vector<bool>> L(n+1, std::vector<bool> (m+1, false));
    std::vector<int> row;
    std::vector<int> column;
    
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < m; j++){
            if(Seq_1.at(i) == Seq_2.at(j)){
                L.at(i).at(j) = true;
                row.push_back(i);
                column.push_back(j);
                std::cout << "(" << i << ", " << j << ") \n";
            }
//            std::cout << L.at(i).at(j) << ' ';
        }
//        std::cout<<std::endl;
    }
    int sz{(int)row.size()}, c{0}, max{0};
    int index_i{0}, index_j{0};
    for(size_t i = 0; i < sz; i++){
        for(size_t j = 0; j < sz; j++){
            if(L.at(i).at(j) == true){
                if((i >= row.at(index_i)) && (j >= column.at(index_j))){
                    index_i = i;
                    index_j = j;
                    c++;
                }
            }
            
        }
    }
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
    
    std::cout << LCS2S_2D(n, Seq_1, m, Seq_2) << std::endl;
    
    
    return 0;
}
