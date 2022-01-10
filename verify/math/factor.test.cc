#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A"
#include "../../nimrod/math/factor.cc"

#include <iostream>

int main() {
  int n; std::cin >> n;
  auto facts = factor(n);
  std::cout << n << ":";
  for (const auto& [p, e] : facts) {
    for (int i = 0; i < e; ++i) {
      std::cout << " " << p;
    }
  }
  std::cout << std::endl;

  return 0;
}