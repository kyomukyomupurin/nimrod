#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"
#include <iostream>

#include "../../nimrod/data_structure/dual_segtree.cc"

int main() {
  int n, q;
  std::cin >> n >> q;
  constexpr long long oie = (1LL << 31) - 1;
  auto f = [](long long e, long long x) { return x; };
  dual_segtree seg(n, oie, f);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int s, t;
      long long x;
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