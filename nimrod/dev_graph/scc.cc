#include <vector>

#include "./graph.cc"

template <class T>
class scc_digraph : public digraph<T> {
 public:
  using digraph<T>::n_;
  using digraph<T>::edges_;

  scc_digraph(int n) : digraph<T>(n), cnt_(0), rg_(n) {
    ids_.resize(n);
    visited_.assign(n, false);
    components_.resize(n);
  }

  void build() {
    for (int i = 0; i < n_; ++i) {
      if (!visited_[i]) dfs(i);
    }
    visited_.assign(n_, false);
    rg_ = (*this).reverse();
    for (int i = n_ - 1; i >= 0; --i) {
      if (!visited_[order_[i]]) dfs2(order_[i], cnt_++);
    }
    components_.resize(cnt_);
  }

  const std::vector<std::vector<int>> components() const {
    return this->components_;
  }

  int operator[](int v) const noexcept { return ids_[v]; }

 private:
  int cnt_;
  std::vector<int> ids_;
  std::vector<int> order_;
  std::vector<bool> visited_;
  std::vector<std::vector<int>> components_;
  digraph<T> rg_;

  void dfs(int cur) {
    visited_[cur] = true;
    for (const auto& [_, to, cost] : edges_[cur]) {
      if (visited_[to]) continue;
      dfs(to);
    }
    order_.emplace_back(cur);
  }

  void dfs2(int cur, int k) {
    visited_[cur] = true;
    components_[k].emplace_back(cur);
    ids_[cur] = k;
    for (const auto& [_, to, cost] : rg_.edges_[cur]) {
      if (visited_[to]) continue;
      dfs2(to, k);
    }
  }
};