#include<iostream>
#include<vector>

std::vector<int> Primitive(int n){
    int count{0};
    std::vector<int> list;

    if(n == 1){
        list.push_back(1);
        list.push_back(0);
        return list;
    }

    list.push_back(n);

    while(n > 1){
        // list.push_back(n);
        while(n % 3 == 0){
            n /= 3;
            list.push_back(n);
            count++;
        }

        while(n % 2 == 0){
            if((n - 1) % 3 == 0){
                n -= 1;
                list.push_back(n);
                count++;
            }
            else{
                n /= 2;
                list.push_back(n);
                count++;
            }

        }

        if((n % 2 != 0)&&(n % 3 != 0)&&(n != 1)){
            n -= 1;
            list.push_back(n);
            count++;
        }

    }

    list.push_back(count);

    return list;
}




int main(){
    int n{0};
    std::cin >> n;

    std::vector<int> list;
    list = Primitive(n);
    std::cout << list.size() - 1) << std::endl;
    for(int i = (list.size()- 2); i >= 0; i--){
        std::cout << list.at(i) << ' ';
    }
    std::cout << std::endl;
    // std::cout << Steps << std::endl;
    return 0;
}
