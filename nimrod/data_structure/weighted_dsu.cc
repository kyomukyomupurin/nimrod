#include <vector>

// snippet-begin
class weighted_dsu {
 public:
  explicit weighted_dsu(int n) {
    p_.assign(n, -1);
    r_.assign(n, 0);
    w_.assign(n, 0);
  }

  int root(int x) {
    if (p_[x] == -1) {
      return x;
    } else {
      int r = root(p_[x]);
      w_[x] += w_[p_[x]];
      return p_[x] = r;
    }
  }

  int weight(int x) {
    root(x);
    return w_[x];
  }

  bool same(int x, int y) { return root(x) == root(y); }

  // y is w larger than x
  void merge(int x, int y, int w) {
    w += weight(x);
    w -= weight(y);
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (r_[x] < r_[y]) {
      std::swap(x, y);
      w = -w;
    }
    if (r_[x] == r_[y]) ++r_[x];
    p_[y] = x;
    w_[y] = w;
  }

  // y - w (only if same(x, y))
  int diff(int x, int y) { return weight(y) - weight(x); }

 private:
  std::vector<int> p_;
  std::vector<int> r_;
  std::vector<int> w_;
};