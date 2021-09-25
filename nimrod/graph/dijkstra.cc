#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

#include "./graph.cc"

// snippet-begin
template <class T>
std::vector<T> dijkstra(const graph<T>& g, int s) {
  std::vector<T> dist(g.size(), std::numeric_limits<T>::max() / 2);
  using P = std::pair<T, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  dist[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (dist[v] < d) continue;
    for (int id : g.data()[v]) {
      const auto& [from, to, cost] = g.edges()[id];
      int nxt = from ^ to ^ v;
      if (dist[nxt] > dist[v] + cost) {
        dist[nxt] = dist[v] + cost;
        pq.emplace(dist[nxt], nxt);
      }
    }
  }
  return dist;
}