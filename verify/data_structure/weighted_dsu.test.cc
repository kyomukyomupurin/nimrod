#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B"
#include "../../nimrod/data_structure/weighted_dsu.cc"

#include <iostream>

int main() {
  int n, q;
  std::cin >> n >> q;
  weighted_dsu d(n);
  while (q--) {
    int com;
    std::cin >> com;
    if (com == 0) {
      int x, y, z;
      std::cin >> x >> y >> z;
      d.merge(x, y, z);
    } else {
      int x, y;
      std::cin >> x >> y;
      if (d.same(x, y)) {
        std::cout << d.diff(x, y) << '\n';
      } else {
        std::cout << '?' << '\n';
      }
    }
  }
}