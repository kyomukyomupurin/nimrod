#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../nimrod/algorithm/cumulative.cc"

#include <iostream>

using i64 = int64_t;

int main() {
  int N, Q;
  std::cin >> N >> Q;
  std::vector<i64> a(N);
  for (auto&& e : a) std::cin >> e;
  cumulative cs(a);
  while (Q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << cs.get(l, r - 1) << '\n';
  }
  return 0;
}