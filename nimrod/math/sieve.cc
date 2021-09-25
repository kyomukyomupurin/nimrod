#include <vector>

// snippet-begin
std::vector<int> sieve(int n) {
  std::vector lp(n + 1, 0);
  std::vector<int> p;
  for (int i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      p.emplace_back(i);
    }
    for (int j = 0; j < int(p.size()) && p[j] <= lp[i] && i * p[j] <= n; ++j) {
      lp[i * p[j]] = p[j];
    }
  }
  return p;
}