#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"
#include "../../nimrod/graph/dijkstra.cc"

#include <iostream>

int main() {
  int V, E, r;
  std::cin >> V >> E >> r;
  digraph<long long> g(V);
  for (int i = 0; i < E; ++i) {
    int s, t;
    std::cin >> s >> t;
    long long d;
    std::cin >> d;
    g.add(s, t, d);
  }
  auto dist = dijkstra(g, r);
  for (auto&& e : dist) {
    if (e == std::numeric_limits<long long>::max() / 2) {
      std::cout << "INF" << '\n';
    } else {
      std::cout << e << '\n';
    }
  }
  return 0;
}