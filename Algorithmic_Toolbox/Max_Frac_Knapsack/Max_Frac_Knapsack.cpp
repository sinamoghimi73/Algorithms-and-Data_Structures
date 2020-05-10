#include <iostream>
#include <vector>
#include <array>

using std::vector;
using std::array;

double get_optimal_value(int n, int capacity, vector<int> values, vector<int> weights) {
  double value(0.0);
  double z(-1.0);
  int pl(-1);
  double per[values.size()];
  double val[values.size()];
  double wei[values.size()];

  for (int i = 0; i < values.size(); i++){
      per[i] = double(values[i])/ weights[i];
      // std::cout << per[i] << std::endl;
  }


  for (int i = 0; i < values.size(); i++){
      for (int j = 0; j < values.size(); j++){
          if (per[j] > z){
              z = per[j];
              pl = j;
          }
      }
      val[i] = values[pl];
      wei[i] = weights[pl];
      // std::cout << val[i] << "\n\n";
      per[pl]= -1.0;
      z = -1;
  }

  for (int i = 0; i < values.size(); i++){
      if (capacity > 0){
          if (wei[i] > capacity){
              value = value + (val[i] * capacity / wei[i]);
          }
          else{
              value = value + val[i];
          }
          capacity -= wei[i];
      }
      else {
          return value;
      }
      // std::cout << value << std::endl;
  }



  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n, capacity, values, weights);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
