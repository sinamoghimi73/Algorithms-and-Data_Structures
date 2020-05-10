#include <iostream>
#include <string>

int max(int a, int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}


int LCS2S(int n, std::string &Seq_1, int m, std::string &Seq_2){
    if (n == 0 || m == 0)
        return 0;
    if (Seq_1[n-1] == Seq_2[m-1])
        return 1 + LCS2S(n-1, Seq_1, m-1, Seq_2);
    else
        return max(LCS2S(n, Seq_1, m-1, Seq_2), LCS2S(n-1, Seq_1, m, Seq_2));
}

int main(){
//    ///////////////////////////////////////////////

    
    
//    ///////////////////////////////////////////////
    
    std::string Seq_1;
    std::cin >> Seq_1;
    
    std::string Seq_2;
    std::cin >> Seq_2;
    
    int n{0}, m{0};
    n = Seq_1.size();
    m = Seq_2.size();
//
//    std::cout << Seq_1 << std::endl;
//    std::cout << Seq_2 << std::endl;
//
//
    
    std::cout << LCS2S(n, Seq_1, m, Seq_2) << std::endl;
    
    return 0;
}
