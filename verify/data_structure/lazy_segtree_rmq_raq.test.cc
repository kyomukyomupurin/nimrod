#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H"
#include <iostream>

#include "../../nimrod/data_structure/lazy_segtree.cc"

constexpr long long ie = (long long)1e18;
constexpr long long oie = 0;
auto f1 = [](long long e1, long long e2) { return std::min(e1, e2); };
auto f2 = [](long long e, long long x) { return e + x; };
auto f3 = [](long long x1, long long x2) { return x1 + x2; };

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<long long> v(n, 0);
  lazy_segtree seg(v, ie, oie, f1, f2, f3);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int s, t;
      long long x;
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