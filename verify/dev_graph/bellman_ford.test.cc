#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B"
#include "../../nimrod/dev_graph/bellman_ford.cc"

#include <iostream>

using i64 = int64_t;

int main() {
  int V, E, r;
  std::cin >> V >> E >> r;
  digraph<i64> g(V);
  for (int i = 0; i < E; ++i) {
    int s, t;
    std::cin >> s >> t;
    i64 d;
    std::cin >> d;
    g.add(s, t, d);
  }
  auto dist = bellman_ford(g, E, r);
  if (!dist) {
    std::cout << "NEGATIVE CYCLE" << '\n';
  } else {
    for (auto&& e : dist.value()) {
      if (e == g.inf_cost()) {
        std::cout << "INF" << '\n';
      } else {
        std::cout << e << '\n';
      }
    }
  }
  return 0;
}