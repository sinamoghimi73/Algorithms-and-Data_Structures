#include <iostream>
#include <vector>

std::vector<long> LCS2S(int n, std::vector<long> &Seq_1, int m, std::vector<long> &Seq_2){
    int index{-1}, index_2{0}, flag{1}, count{0}, cc{0};
    std::vector<long> list;
    
//    if((n == 0)|| (m == 0)){
//        return count;
//    }
    for(size_t i = 0; i < n; i++){
        flag = 1;
        while((index_2 < m)&&(flag == 1)){
            if(Seq_1.at(i) == Seq_2.at(index_2)){
                count++;
                list.push_back(Seq_2.at(index_2));
                cc++;
                
                index = index_2;
                index_2++;
                
                if(index == m-1){
                    return list;
                }
                flag = 0;
            }
            else{
                index_2++;
            }
        }
        
        if(cc == 0){
            index_2 = index + 1;
        }
        else{
            index_2 = index + 1;
            cc = 0;
        }
    }
        
    return list;
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
    
    int o{0};
    std::cin >> o;

    std::vector<long> Seq_3(o);
    for(size_t i = 0; i < o; i++){
        std::cin >> Seq_3.at(i);
    }
    
    
    std::vector<long> list;
    list = LCS2S(n, Seq_1, m, Seq_2);
    
    list = LCS2S((int)list.size(), list, o, Seq_3);
    
//    std::cout << "List : [";
//    for(size_t i = 0; i < list.size(); i++){
//        std::cout << list.at(i) << ", ";
//    }
//    std::cout << "] "<< std::endl;


    std::cout << list.size() << std::endl;

    return 0;
}
