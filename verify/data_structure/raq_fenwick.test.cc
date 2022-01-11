#include "../../nimrod/data_structure/raq_fenwick.cc"

#include <iostream>

int main() {
  int n, q;
  std::cin >> n >> q;
  raq_fenwick<long long> ft(n);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int s, t;
      long long x;
      std::cin >> s >> t >> x;
      --s;
      --t;
      ft.add(s, t + 1, x);
    } else {
      int s, t;
      std::cin >> s >> t;
      --s;
      --t;
      std::cout << ft.get(s, t) << '\n';
    }
  }
  return 0;
}