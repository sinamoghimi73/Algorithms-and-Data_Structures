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

std::vector<long> LCS2S(int n, std::vector<long> &Seq_1, int m, std::vector<long> &Seq_2){
    int index{-1}, index_2{0}, flag{1}, count{0}, cc{0};
    std::vector<long> column;

//    if((n == 0)|| (m == 0)){
//        return count;
//    }

    ////////////////////////////////////////////////////////
    int i{0}, z{1};
    while((i < n)&&(z == 1)){
        flag = 1;
        while((index_2 < m)&&(flag == 1)){
            if(Seq_1.at(i) == Seq_2.at(index_2)){
                count++;
                column.push_back(Seq_2.at(index_2));
                cc++;

                index = index_2;
                index_2++;

                if(index == m-1){
                    z = 0;
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
        i++;
    }
    //////////////////////////////////////////////////////////
    index = -1; index_2 = 0; flag = 1; count = 0; cc = 0;
    i = 0; z = 1;

    std::vector<long> row;
    while((i < m)&&(z == 1)){
        flag = 1;
        while((index_2 < n)&&(flag == 1)){
            if(Seq_2.at(i) == Seq_1.at(index_2)){
                count++;
                row.push_back(Seq_1.at(index_2));
                cc++;

                index = index_2;
                index_2 += 1;

                if(index == n-1){
                    z = 0;
                }
                flag = 0;
            }
            else{
                index_2 += 1;
            }
        }

        if(cc == 0){
            index_2 = index + 1;
        }
        else{
            index_2 = index + 1;
            cc = 0;
        }
        i++;
    }

    //////////////////////////////////////////////////////////

    if(column.size() > row.size()){
        return column;
    }
    else{
        return row;
    }
}


int main(){
//    ///////////////////////////////////////////////
    int i{0};
    int n{0}, num{0}, m{0}, cx{0}, flag{1}, mod{5};
    std::vector<long> list;

    
    int sze{0};
    while((i > -1)&&(flag == 1)){
        n = (rand() % mod)+1;
        std::cout << n << "\n";
        if(n == 0){
            return 0;
        }

        std::vector<long> Seq_1(n);
        for(size_t i = 0; i < n; i++){
            num = rand() % 10;
            Seq_1.at(i) = num;
            std::cout << num << ' ';
        }
        std::cout << std::endl;

        m = (rand() % mod)+1;
        std::cout << m << "\n";

        std::vector<long> Seq_2(m);
        for(size_t i = 0; i < m; i++){
            num = rand() % 5;
            Seq_2.at(i) = num;
            std::cout << num << ' ';
        }
        std::cout << std::endl;


        list = LCS2S(n, Seq_1, m, Seq_2);
        sze = naive_LCS2S(n, Seq_1, m, Seq_2);
        
        std::cout << "List : " << list.size() << std::endl;
        std::cout << "NUM : " << sze << std::endl << std::endl;
        
        if (list.size() != sze){
            flag = 0;
            std::cout << "Error \n";
            
                    std::cout << "List : [";
                    for(size_t i = 0; i < list.size(); i++){
                        std::cout << list.at(i) << ", ";
                    }
                    std::cout << "] "<< std::endl;

        }
        
//        std::cout << "List : [";
//        for(size_t i = 0; i < list.size(); i++){
//            std::cout << list.at(i) << ", ";
//        }
//        std::cout << "] "<< std::endl;

//



//        i++;
    }


    
    
//    ///////////////////////////////////////////////
    
//    int n{0};
//    std::cin >> n;
//
//    std::vector<long> Seq_1(n);
//    for(size_t i = 0; i < n; i++){
//        std::cin >> Seq_1.at(i);
//    }
//
//    int m{0};
//    std::cin >> m;
//
//    std::vector<long> Seq_2(m);
//    for(size_t i = 0; i < m; i++){
//        std::cin >> Seq_2.at(i);
//    }
//
////    std::vector<long> list;
//    int list{0};
//    list = LCS2S(n, Seq_1, m, Seq_2);
//    std::cout << list << std::endl;

//    std::cout << "List1 : [";
//    for(size_t i = 0; i < list.size(); i++){
//        std::cout << list.at(i) << ", ";
//    }
//    std::cout << "] "<< std::endl;
//
    

//    std::vector<long> list_2;
//    list_2 = LCS2S(n, Seq_1, list.size(), list);
//
//    std::cout << "List2 : [";
//    for(size_t i = 0; i < list_2.size(); i++){
//        std::cout << list_2.at(i) << ", ";
//    }
//    std::cout << "] "<< std::endl;
//
//    std::vector<long> list_3;
//    list_3 = LCS2S(list.size(), list, m, Seq_2);
//
//    std::cout << "List3 : [";
//    for(size_t i = 0; i < list_3.size(); i++){
//        std::cout << list_3.at(i) << ", ";
//    }
//    std::cout << "] "<< std::endl;

//    std::cout << list.size() << std::endl;

    return 0;
}
