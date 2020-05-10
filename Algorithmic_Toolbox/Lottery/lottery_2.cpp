#include <iostream>
#include <vector>

void Lottery(int min, int max, std::vector<int> &Begin, std::vector<int> &End, int s, std::vector<int> &Point, int p){
    int i{0}, point{0}, count{0};
    std::vector<short> lot(p, 0);

    while(i < p){
        point = Point.at(i);
        if((point < min) || (point > max)){
            Point.at(i) = 0;
        }
        else{
            for(size_t j = 0; j < s; j++){
                lot.at(i) += (point > Begin.at(j))&&(point < End.at(j));
            }
        }
        i++;
    }

    for(size_t i = 0; i < p; i++){
        std::cout<<lot.at(i)<<' ';
    }
    std::cout<<std::endl;

    // std::vector<short> list(max + 1 - min, 0);
    //
    // if(min < 0){
    //     for (size_t i = 0; i < p; i++){
    //         Point.at(i) += abs(min);
    //     }
    //     for (size_t i = 0; i < s; i++){
    //         Begin.at(i) += abs(min);
    //         End.at(i) += abs(min);
    //     }
    // }
    //
    // for(size_t i = 0; i < s; i++){
    //     for(size_t j = Begin.at(i); j <= End.at(i); j++){
    //         list.at(j) += 1;
    //     }
    // }
    //
    // int num{0};
    // for (size_t i = 0; i < p; i++){
    //     num = Point.at(i);
    //     std::cout << list.at(num) << ' ';
    // }
    // std::cout<<std::endl;
}


int main() {
    int s{0}, p{0};
    std::cin >> s >> p;

    int min_s{0}, max_s{0}, begin{0}, end{0};
    std::vector<int> Begin(s), End(s);
    for (std::size_t i = 0; i < s; i++){
        std::cin >> begin >> end;

        Begin.at(i) = begin;
        End.at(i) = end;
        if(begin < min_s){
            min_s = begin;
        }
        if(max_s < end){
            max_s = end;
        }
    }


    std::vector<int> Point(p);
    int min_p{min_s}, max_p{max_s}, num{0};
    for(std::size_t i = 0; i < p; i++){
        std::cin >> num;
        Point.at(i) = num;
        if (num < min_p){
            min_p = num;
        }
        if (num > max_p){
            max_p = num;
        }
    }


    // int min{0}, max{0};
    // if(min_s < min_p){
    //     min = min_s;
    // }
    // else{
    //     min = min_p;
    // }
    //
    // if(max_s < max_p){
    //     max = max_p;
    // }
    // else{
    //     max = max_s;
    // }



    Lottery(min_s, max_s, Begin, End, s, Point, p);


    return 0;
}
