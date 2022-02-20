#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I"
#include <iostream>

#include "../../nimrod/data_structure/lazy_segtree.cc"

using i64 = int64_t;

struct Node {
  i64 val, len;
};
constexpr Node ie = {0, 1};
constexpr i64 oie = (i64)-1e18;
auto f1 = [](Node e1, Node e2) {
  return Node({e1.val + e2.val, e1.len + e2.len});
};
auto f2 = [](Node e, i64 x) { return Node({e.len * x, e.len}); };
auto f3 = [](i64 x1, i64 x2) { return x2; };

int main() {
  int n, q;
  std::cin >> n >> q;
  lazy_segtree seg(n, ie, oie, f1, f2, f3);
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
      std::cout << seg.get(s, t + 1).val << '\n';
    }
  }
  return 0;
}