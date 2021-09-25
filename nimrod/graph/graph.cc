#include <vector>

// snippet-begin
template <class T>
class graph {
 public:
  explicit graph(int n) : n_(n) { data_.resize(n); }

  struct edge {
    int from, to;
    T cost;
  };
  int n_;

  virtual void add(int from, int to, T cost) = 0;

  int size() const { return n_; }

  const std::vector<std::vector<int>>& data() const { return this->data_; }

  const std::vector<edge>& edges() const { return this->edges_; }

 protected:
  std::vector<std::vector<int>> data_;
  std::vector<edge> edges_;
};

template <class T>
class forest : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::data_;
  using graph<T>::edges_;

  explicit forest(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    int id = edges_.size();
    data_[from].emplace_back(id);
    data_[to].emplace_back(id);
    edges_.push_back({from, to, cost});
  }
};

template <class T>
class digraph : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::data_;
  using graph<T>::edges_;

  explicit digraph(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    int id = edges_.size();
    data_[from].emplace_back(id);
    edges_.push_back({from, to, cost});
  }

  digraph<T> reverse() const {
    digraph<T> rev(n_);
    for (const auto& [from, to, cost] : edges_) {
      rev.add(to, from, cost);
    }
    return rev;
  }
};

template <class T>
class undigraph : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::data_;
  using graph<T>::edges_;

  explicit undigraph(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    int id = edges_.size();
    data_[from].emplace_back(id);
    data_[to].emplace_back(id);
    edges_.push_back({from, to, cost});
  }
};