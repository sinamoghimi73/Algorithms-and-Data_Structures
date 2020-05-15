#include <iostream>
#include <vector>

int Binary_Search(const std::vector<int> &vec, int &x) {
  int left{0}, right{static_cast<int>(vec.size() - 1)}, mid{0};

  while (((right - left) / 2) > 0) {
    mid = left + ((right - left) / 2);

    if (x > vec.at(mid)) {
      left = mid;
      mid = left + ((right - left) / 2);
    }

    if (x < vec.at(mid)) {
      right = mid;
      mid = left + ((right - left) / 2);
    }

    if (x == vec.at(mid)) {
      return mid;
    }
  }

  if (x == vec.at(mid + 1)) {
    return mid + 1;
  }

  return -1;
}

int main() {
  int n{0};
  std::cin >> n;

  std::vector<int> vec{};
  int num{0};
  for (int i = 0; i < n; i++) {
    std::cin >> num;
    vec.push_back(num);
  }

  int x{0};
  std::cin >> x;

  std::cout << Binary_Search(vec, x) << "\n";

  return 0;
}
