#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"
#include <iostream>

#include "../../nimrod/data_structure/lazy_segtree.cc"

struct Node {
  long long val, len;
};
constexpr Node ie = {0, 1};
constexpr long long oie = 0;
auto f1 = [](Node e1, Node e2) {
  return Node({e1.val + e2.val, e1.len + e2.len});
};
auto f2 = [](Node e, long long x) { return Node({e.val + e.len * x, e.len}); };
auto f3 = [](long long x1, long long x2) { return x1 + x2; };

int main() {
  int n, q;
  std::cin >> n >> q;
  lazy_segtree seg(n, ie, oie, f1, f2, f3);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int s, t;
      long long x;
      std::cin >> s >> t >> x;
      seg.modify(s - 1, t, x);
    } else {
      int s, t;
      std::cin >> s >> t;
      std::cout << seg.get(s - 1, t).val << '\n';
    }
  }
  return 0;
}