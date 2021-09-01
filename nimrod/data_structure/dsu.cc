#include <vector>

class dsu {
 public:
  explicit dsu(int n) : n_(n) { p_.assign(n, -1); }

  int root(int x) { return (p_[x] < 0) ? x : p_[x] = root(p_[x]); }

  bool same(int x, int y) { return root(x) == root(y); }

  void merge(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (p_[x] > p_[y]) std::swap(x, y);
    p_[x] += p_[y];
    p_[y] = x;
  }

  int size(int x) { return -p_[root(x)]; }

 private:
  int n_;
  std::vector<int> p_;
};