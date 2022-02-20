#include <bit>
#include <vector>

#include "./graph.cc"

template <class T>
class lca_forest : public forest<T> {
 public:
  using forest<T>::n_;
  using forest<T>::edges_;

  lca_forest(int n) : forest<T>(n), lg_(32 - std::__countl_zero(n)) {
    dep_.resize(n);
    par_.assign(lg_, std::vector<int>(n, -1));
  }

  void build(int r = 0) {
    dfs(r, -1, 0);
    for (int i = 0; i + 1 < lg_; ++i) {
      for (int j = 0; j < n_; ++j) {
        if (par_[i][j] < 0) {
          par_[i + 1][j] = -1;
        } else {
          par_[i + 1][j] = par_[i][par_[i][j]];
        }
      }
    }
  }

  int lca(int u, int v) {
    if (dep_[u] > dep_[v]) std::swap(u, v);
    for (int i = 0; i < lg_; ++i) {
      if ((dep_[v] - dep_[u]) >> i & 1) {
        v = par_[i][v];
      }
    }
    if (u == v) return u;
    for (int i = lg_ - 1; i >= 0; --i) {
      if (par_[i][u] != par_[i][v]) {
        u = par_[i][u];
        v = par_[i][v];
      }
    }
    return par_[0][u];
  }

  int dist(int u, int v) {
    return dep_[u] + dep_[v] - 2 * dep_[lca(u, v)];
  }

 private:
  int lg_;
  std::vector<std::vector<int>> par_;
  std::vector<int> dep_;

  void dfs(int cur, int pre, int d) {
    par_[0][cur] = pre;
    dep_[cur] = d;
    for (const auto& [_, to, cost] : edges_[cur]) {
      if (to == pre) continue;
      dfs(to, cur, d + 1);
    }
  }

  void init() {
    dep_.resize(n_);
    par_.assign(lg_, std::vector<int>(n_, -1));
  }
};