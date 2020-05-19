#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> 

using namespace std::chrono;


int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    auto start = high_resolution_clock::now();
    std::cout << MaxPairwiseProduct(numbers) << "\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken by function: "
         << duration.count() << " microseconds" << std::endl; 
    return 0;
}
