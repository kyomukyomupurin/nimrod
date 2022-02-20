#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../nimrod/data_structure/fenwick.cc"

#include <iostream>

using i64 = int64_t;

int main() {
  int N, Q;
  std::cin >> N >> Q;
  std::vector<i64> a(N);
  for (auto&& e : a) std::cin >> e;
  fenwick ft(a);
  while (Q--) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int p;
      i64 x;
      std::cin >> p >> x;
      ft.add(p, x);
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << ft.get(l, r) << '\n';
    }
  }
  return 0;
}