#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"
#include <iostream>

#include "../../nimrod/data_structure/segtree.cc"

using i64 = int64_t;

int main() {
  int N, Q;
  std::cin >> N >> Q;
  constexpr i64 ie = (1LL << 31) - 1;
  auto f = [](i64 x, i64 y) -> i64 { return std::min(x, y); };
  segtree seg(N, ie, f);
  while (Q--) {
    int com;
    std::cin >> com;
    if (com == 0) {
      int i;
      i64 x;
      std::cin >> i >> x;
      seg.update(i, x);
    } else {
      int s, t;
      std::cin >> s >> t;
      std::cout << seg.get(s, t + 1) << '\n';
    }
  }
  return 0;
}