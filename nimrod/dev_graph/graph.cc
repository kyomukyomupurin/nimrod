#include <limits>
#include <vector>

template <class T>
class graph {
 public:
  explicit graph(int n) : n_(n) { edges_.resize(n); }

  struct edge {
    int from, to;
    T cost;
  };

  virtual void add(int from, int to, T cost) = 0;

  int size() const { return n_; }

  const T inf_cost() const { return std::numeric_limits<T>::max() / 2; }

  const std::vector<edge>& edges(int v) const { return this->edges_[v]; }

 protected:
  int n_;
  std::vector<std::vector<edge>> edges_;
};

template <class T>
class forest : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::edges_;

  explicit forest(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    edges_[from].push_back({from, to, cost});
    edges_[to].push_back({to, from, cost});
  }
};

template <class T>
class digraph : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::edges_;

  explicit digraph(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    edges_[from].push_back({from, to, cost});
  }

  digraph<T> reverse() const {
    digraph<T> rev(n_);
    for (int from = 0; from < n_; ++from) {
      for (const auto& [_, to, cost] : edges_[from]) {
        rev.add(to, from, cost);
      }
    }
    return rev;
  }
};

template <class T>
class undigraph : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::edges_;

  explicit undigraph(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    edges_[from].push_back({from, to, cost});
    edges_[to].push_back({to, from, cost});
  }
};