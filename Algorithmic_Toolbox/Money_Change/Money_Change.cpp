#include <iostream>

// Allowed Moneys are 10, 5, 1.



int get_change(int m) {
    int n(0), ten(0), five(0), one(0);

    ten = m / 10;
    m -= ten *10;

    five = m /5;
    m -= five * 5;

    one = m;
    m -= one;

    n = ten + five + one;

    return n;

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
