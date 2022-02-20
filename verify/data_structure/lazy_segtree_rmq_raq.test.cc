#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H"
#include <iostream>

#include "../../nimrod/data_structure/lazy_segtree.cc"

using i64 = int64_t;

constexpr i64 ie = i64(1e18);
constexpr i64 oie = 0;
auto f1 = [](i64 e1, i64 e2) { return std::min(e1, e2); };
auto f2 = [](i64 e, i64 x) { return e + x; };
auto f3 = [](i64 x1, i64 x2) { return x1 + x2; };

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<i64> v(n, 0);
  lazy_segtree seg(v, ie, oie, f1, f2, f3);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int s, t;
      i64 x;
      std::cin >> s >> t >> x;
      seg.modify(s, t + 1, x);
    } else {
      int s, t;
      std::cin >> s >> t;
      std::cout << seg.get(s, t + 1) << '\n';
    }
  }
  return 0;
}