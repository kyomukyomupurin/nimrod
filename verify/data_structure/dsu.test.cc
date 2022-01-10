#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"
#include "../../nimrod/data_structure/dsu.cc"

#include <iostream>

int main() {
  int n, q;
  std::cin >> n >> q;
  dsu d(n);
  while (q--) {
    int com, x, y;
    std::cin >> com >> x >> y;
    if (com == 0) {
      d.merge(x, y);
    } else {
      std::cout << d.same(x, y) << '\n';
    }
  }
  return 0;
}