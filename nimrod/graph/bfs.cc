#include <queue>
#include <vector>

#include "./graph.cc"

template <class T>
std::vector<T> bfs(const graph<T>& g, int s) {
  std::vector<T> d(g.size(), -1);
  std::queue<int> q;
  d[s] = 0;
  q.emplace(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int id : g.data()[v]) {
      const auto& [from, to, cost] = g.edges()[id];
      int nxt = from ^ to ^ v;
      if (d[nxt] != -1) continue;
      d[nxt] = d[v] + cost;
      q.emplace(nxt);
    }
  }
  return d;
}