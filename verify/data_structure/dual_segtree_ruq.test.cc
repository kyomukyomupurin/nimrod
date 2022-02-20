#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"
#include <iostream>

#include "../../nimrod/data_structure/dual_segtree.cc"

using i64 = int64_t;

int main() {
  int n, q;
  std::cin >> n >> q;
  constexpr i64 oie = (i64(1) << 31) - 1;
  auto f = [](i64 e, i64 x) { return x; };
  dual_segtree seg(n, oie, f);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int s, t;
      i64 x;
      std::cin >> s >> t >> x;
      seg.modify(s, t + 1, x);
    } else {
      int i;
      std::cin >> i;
      std::cout << seg[i] << '\n';
    }
  }
  return 0;
}