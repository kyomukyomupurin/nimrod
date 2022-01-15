#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <iostream>

#include "../../nimrod/data_structure/lazy_segtree.cc"
#include "../../nimrod/math/modint.cc"

constexpr int mod = 998244353;
using mint = modint<mod>;

struct Node {
  mint val, len;
};

struct Op {
  mint op1, op2;
  bool operator==(const Op& rhs) const {
    return rhs.op1 == op1 && rhs.op2 == op2;
  };
  bool operator!=(const Op& rhs) const {
    return rhs.op1 != op1 || rhs.op2 != op2;
  };
};
constexpr Node ie = {0, 1};
constexpr Op oie = {1, 0};
auto f1 = [](Node e1, Node e2) {
  return Node({e1.val + e2.val, e1.len + e2.len});
};
auto f2 = [](Node e, Op x) {
  return Node({e.val * x.op1 + e.len * x.op2, e.len});
};
auto f3 = [](Op x1, Op x2) {
  return Op({x1.op1 * x2.op1, x1.op2 * x2.op1 + x2.op2});
};

int main() {
  int N, Q;
  std::cin >> N >> Q;
  std::vector<Node> v;
  for (int i = 0; i < N; ++i) {
    mint a;
    std::cin >> a;
    v.push_back({a, 1});
  }
  lazy_segtree seg(v, ie, oie, f1, f2, f3);
  while (Q--) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int l, r;
      mint b, c;
      std::cin >> l >> r >> b >> c;
      seg.modify(l, r, Op({b, c}));
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << seg.get(l, r).val << '\n';
    }
  }
  return 0;
}