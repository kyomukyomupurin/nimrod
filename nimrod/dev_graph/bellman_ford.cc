#include <optional>
#include <vector>

#include "./graph.cc"

template <class T>
std::optional<std::vector<T>> bellman_ford(const graph<T>& g, int m, int s) {
  std::vector<T> dist(g.size(), g.inf_cost());
  dist[s] = 0;
  int v = 0;
  for (int i = 0; i < m - 1; ++i) {
    for (int from = 0; from < g.size(); ++from) {
      for (const auto& [_, to, cost] : g.edges(from)) {
        if (dist[from] == g.inf_cost()) continue;
        if (dist[to] > dist[from] + cost) {
          dist[to] = dist[from] + cost;
        }
      }
    }
  }
  for (int from = 0; from < g.size(); ++from) {
    for (const auto& [_, to, cost] : g.edges(from)) {
      if (dist[from] == g.inf_cost()) continue;
      if (dist[to] > dist[from] + cost) return std::nullopt;
    }
  }
  return dist;
}