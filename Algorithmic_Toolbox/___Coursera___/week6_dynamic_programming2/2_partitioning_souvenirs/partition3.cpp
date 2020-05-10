#include <iostream>
#include <vector>

int Addition(int n, std::vector<int> &v){
    int sum{0};

    for(int val : v)
        sum += val;

    return sum;
}

int Binary_Search(const std::vector<int> &vec, int x){
    int left{0}, right{(int)(vec.size()-1)}, mid{0};

    while (((right - left) / 2) > 0){
        mid = left + ((right - left) / 2);
        // std::cout << vec.at(mid) << "\n";
        if (x > vec.at(mid)){
            left = mid;
            mid = left + ((right - left) / 2);
        }

        if (x < vec.at(mid)){
            right = mid;
            mid = left + ((right - left) / 2);
        }

        if (x == vec.at(mid)){
            return mid;
        }
    }
    if(x == vec.at(mid+1)){
        return mid+1;
    }
    
    return mid;
}

void partition (std::vector<int> &v, int F, int L, int *p)
{
    int pivot = v.at(L);
    int i = (F-1);
    for (int j = F; j <= L - 1; j++)
    {
        if (v.at(j) < pivot)
        {
            i++;
            std::swap(v.at(i), v.at(j));
        }
    }
    std::swap(v.at(i+1), v.at(L));
    *p = i+1;
}
  
void Quick_Sort(std::vector<int> &v, int F, int L){
    int p{0};
    if (F < L)
    {
        partition(v, F, L, &p);
        Quick_Sort(v, F, p - 1);
        Quick_Sort(v, p + 1, L);
    }
}

bool Portion(int n, std::vector<int> &v, int each_portion){
    std::vector<int> A{}, B{}, C{};
    std::vector<bool> index(n, true);
    int sum{}, i{n-1}, min{v.at(0)};
    int res{}, max{v.at(n-1)};
    do{
        if((index.at(i) == true)&&(each_portion - (sum + v.at(i)) > min)){
            index.at(i) = false;
            A.push_back(v.at(i));
            sum += v.at(i);
            --i;
        }
        else{
            res = Binary_Search(v, each_portion - sum);
            if((res == -1) || ((res != -1) && (index.at(res) == true)))
                --i;
            else{
                i = res;
            }
        }
        
    }while(!(sum > each_portion) && (i >= 0));
    
    for (int x : A)
        std::cout << x << ' ';
    std::cout << std::endl;
    
    
    return true;
}

bool Souvenir(int n, std::vector<int> &v){
    int sum{};
    bool res{};
    if (n < 3)
        return false;
    else{
        sum = Addition(n, v);
        Quick_Sort(v, 0, n-1);
        res = Portion(n, v, sum/3);
        return (sum % 3) && res;
    }
}

int main() {
    int n{13};
    
    std::vector<int> v{4,5,6,7,8,9,10,10,14,15,16,16,19,21,22,23,25,26,27,29,30};
    
    std::cout << Souvenir(n, v) << std::endl;
    return 0;
}
