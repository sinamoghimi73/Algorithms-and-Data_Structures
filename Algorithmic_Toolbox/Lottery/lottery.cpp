#include <iostream>
#include <vector>


void Lottery(int s, int p, std::vector<int> &Begin, std::vector<int> &End, std::vector<int> &Point){
    std::vector<int> lottery(p,0);
    long num{0};

    for(std::size_t i = 0; i < p; i++){
        num = Point.at(i);
        for(std::size_t j = 0; j < s; j++){
            lottery.at(i) += (Begin.at(j) <= num)&&(num <= End.at(j));
        }
    }

    for (std::size_t i = 0; i < p; i++){
        std::cout<< lottery.at(i) << ' ';
    }
    std::cout<<"\n";
}


int main() {
    int s{0}, p{0};
    std::cin >> s >> p;

    std::vector<int> Begin(s), End(s);
    for (std::size_t i = 0; i < s; i++){
        std::cin >> Begin.at(i) >> End.at(i);
    }




    std::vector<int> Point(p);
    for (std::size_t i = 0; i < p; i++){
        std::cin >> Point.at(i);
    }

    Lottery(s, p, Begin, End, Point);

    // for (int i = 0; i < p; i++){
    //     std::cout<< lottery.at(i) << ' ';
    // }
    // std::cout<<"\n";

    return 0;
}
