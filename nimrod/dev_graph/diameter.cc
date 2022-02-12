#include <algorithm>
#include <vector>

#include "./bfs.cc"

template <class T>
T diameter(const forest<T>& g) {
  std::vector d1 = bfs(g, 0);
  std::vector d2 =
      bfs(g, std::distance(d1.begin(), std::max_element(d1.begin(), d1.end())));
  return *std::max_element(d2.begin(), d2.end());
}