#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A"
#include "../../nimrod/dev_graph/diameter.cc"

#include <iostream>

int main() {
  int n;
  std::cin >> n;
  forest<int> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g.add(s, t, d);
  }
  std::cout << diameter(g) << '\n';
  return 0;
}