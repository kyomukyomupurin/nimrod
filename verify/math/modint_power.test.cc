#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_A"
#include <iostream>

#include "../../nimrod/math/modint.cc"

int main() {
  int n, k;
  std::cin >> n >> k;
  std::cout << power(k, n) << '\n';

  return 0;
}