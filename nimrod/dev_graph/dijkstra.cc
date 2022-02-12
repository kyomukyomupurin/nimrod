#include <algorithm>
#include <queue>
#include <vector>

#include "./graph.cc"

template <class T>
std::vector<T> dijkstra(const graph<T>& g, int s) {
  std::vector<T> dist(g.size(), g.inf_cost());
  using P = std::pair<T, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  dist[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (dist[v] < d) continue;
    for (const auto& [_, to, cost] : g.edges(v)) {
      if (dist[to] > dist[v] + cost) {
        dist[to] = dist[v] + cost;
        pq.emplace(dist[to], to);
      }
    }
  }
  return dist;
}