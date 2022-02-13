#include <queue>
#include <vector>

#include "./graph.cc"

template <class T>
std::vector<T> bfs(const graph<T>& g, int s) {
  std::vector<T> dist(g.size(), g.inf_cost());
  std::queue<int> q;
  dist[s] = 0;
  q.emplace(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (const auto& [_, to, cost] : g.edges(v)) {
      if (dist[to] != g.inf_cost()) continue;
      dist[to] = dist[v] + cost;
      q.emplace(to);
    }
  }
  return dist;
}