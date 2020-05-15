#include <iostream>

size_t Fib(int const *n) {
  size_t Fib_Num{}, *Fn{&Fib_Num};

  if (*n <= 1) {
    return *n;
  }

  int Fib1{0}, *F1{&Fib1};
  int Fib2{1}, *F2{&Fib2};

  for (int i = 1; i < *n; i++) {
    *Fn = *F1 + *F2;
    *F1 = *F2;
    *F2 = *Fn;
  }
  return *Fn;
}

int main() {

  int n{};
  std::cin >> n;

  std::cout << Fib(&n) << std::endl;

  return 0;
}
