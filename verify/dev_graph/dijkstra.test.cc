#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"
#include "../../nimrod/dev_graph/dijkstra.cc"

#include <iostream>

using i64 = int64_t;

int main() {
  int V, E, r;
  std::cin >> V >> E >> r;
  digraph<i64> g(V);
  for (int i = 0; i < E; ++i) {
    int s, t;
    std::cin >> s >> t;
    long long d;
    std::cin >> d;
    g.add(s, t, d);
  }
  auto dist = dijkstra(g, r);
  for (auto&& e : dist) {
    if (e == g.inf_cost()) {
      std::cout << "INF" << '\n';
    } else {
      std::cout << e << '\n';
    }
  }
  return 0;
}