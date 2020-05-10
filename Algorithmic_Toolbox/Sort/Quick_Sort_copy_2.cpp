#include <iostream>
#include <vector>


int count_Num(std::vector<long> &list, int z, int n){
    int pass{1}, k{1};

    while((k < n)&& (list.at(k) >= list.at(k-1))){
        pass++;
        k++;
        // if (k == n){
        //     return pass;
        // }
    }

    return pass;
}

int print_Num(std::vector<long> &list, int z, int n){
    for(int i = z; i < n; i++){
        std::cout << list.at(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}

std::vector<long> quick_sort_1(std::vector<long> &list, int z, int n){

    int i{1}, indexL{z}, indexR{n-1}, indexP{z}, t{0}, time{0};
    time++;

    // Pivot < Right     // Pivot > Left

    while (i > 0){
        while(list.at(indexP) < list.at(indexR)){
            indexR--;
            t++;
        }

        while(list.at(indexP) > list.at(indexL)){
            indexL++;
            t++;
        }

        if(list.at(indexP) > list.at(indexR)){
            std::swap(list.at(indexP), list.at(indexR));
            indexP = indexR;
            indexL++;
            t++;
        }

        if(list.at(indexP) < list.at(indexL)){
            std::swap(list.at(indexP), list.at(indexL));
            indexP = indexL;
            indexR--;
            t++;
        }

        if ((indexP != indexR) && (list.at(indexP) == list.at(indexR))){
            indexR--;
            t++;
        }

        if ((indexP != indexL) && (list.at(indexP) == list.at(indexL))){
            indexL++;
            t++;
        }


        if ((indexL == indexR) && (indexL == indexP)){
            i = 0;
            t++;
        }
        // print_Num(list, 0, list.size());
    }

    if (count_Num(list, 0, n) == n){
        std::cout << "t : " << t*time << std::endl;
        return list;
    }


    if (indexP != n-1){
        quick_sort_1(list, indexL + 1, n);
    }
    else{
        quick_sort_1(list, 0, indexR);
    }






    return list;
}


int main(){

    int n{0};
    std::cin >> n;

    std::vector<long> vec;
    int num{0};
    for(int i = 0; i < n; i++){
        std::cin >> num;
        vec.push_back(num);
        // vec.push_back(n);
    }
    vec = quick_sort_1(vec, 0, n);
    print_Num(vec, 0, n);



    return 0;
}
