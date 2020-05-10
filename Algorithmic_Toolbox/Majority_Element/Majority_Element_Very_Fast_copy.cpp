#include <iostream>
#include <vector>

int indexority_Element(std::vector<long> &vec, int n){
    int index{0}, c{1}, half{n/2};
    for (int i = 0; i < n; i++){
        if(vec.at(index) == vec.at(i)){
            c++;
        }
        else{
            c--;
        }
        if(c == 0){
            index = i;
            c++;
        }
    }


    int count{0};
    long Num{vec.at(index)};

    for(int i = 0; i < n; i++){
        if(vec.at(i) == Num){
            count++;
            if (count > half){
                return 1;
            }
        }
    }
    return 0;
}



int main(){

    int n{0};
    std::cin >> n;

    std::vector<long> vec;
    int num{0};
    for(int i = 0; i < n; i++){
        std::cin >> num;
        vec.push_back(num);
    }

    std::cout << indexority_Element(vec, n) << std::endl;


    return 0;
}
