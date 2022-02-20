#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"
#include "../../nimrod/data_structure/raq_fenwick.cc"

#include <iostream>

using i64 = int64_t;

int main() {
  int n, q;
  std::cin >> n >> q;
  raq_fenwick<i64> ft(n);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int s, t;
      i64 x;
      std::cin >> s >> t >> x;
      --s;
      --t;
      ft.add(s, t + 1, x);
    } else {
      int s, t;
      std::cin >> s >> t;
      --s;
      --t;
      std::cout << ft.get(s, t) << '\n';
    }
  }
  return 0;
}