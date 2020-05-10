#include <iostream>
#include <vector>

// Denominations of 1, 3, 4.

int Money(int n){

    int four{0}, three{0}, one{0};
    if(n < 3){
        return n;
    }

    int count{0};

    if((n > 0)&& (n % 4 == 0)){
        four += n/4;
        return four;
    }


    while((n >= 10)&&(n % 4 != 0)){
        n -= 4;
        n -= 3;
        count += 2;
    }


    if((n >= 4)&& (n % 4 == 0)){
        four += n/4;
        return four+count;
    }


    if((n >= 3)&&(n % 3 == 0)){
        three += n/3;
        return three+count;
    }

    if(n >= 4){
        four = n/4;
        n -= four*4;
        count += four;
    }

    if (n >= 3){
        three = n/3;
        n -= three*3;
        count += three;
    }
    if (n >= 1){
        one = n;
        n -= one;
        count += one;
    }

    return count;
}



int main(){
    int n{0};
    std::cin >> n;

    int min{0};
    min = Money(n);
    std::cout << min << std::endl;


    return 0;
}
