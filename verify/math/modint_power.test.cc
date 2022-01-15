#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_A"
#include <iostream>

#include "../../nimrod/math/modint.cc"

constexpr int mod = int(1e9) + 7;
using mint = modint<mod>;

int main() {
  int n;
  mint k;
  std::cin >> n >> k;
  std::cout << k.pow(n) << '\n';

  return 0;
}