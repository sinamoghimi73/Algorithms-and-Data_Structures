#include <iostream>

int Add(int *num1, int *num2) { return *num1 + *num2; }

int main() {

  int a{}, b{};

  std::cin >> a >> b;

  std::cout << Add(&a, &b) << std::endl;

  return 0;
}
