#include <vector>

// snippet-begin
template <class T>
class fenwick {
 public:
  explicit fenwick(int n) : n_(n + 1) { d_.assign(n_, 0); }

  explicit fenwick(const std::vector<T>& v) {
    n_ = int(v.size()) + 1;
    d_.assign(n_, 0);
    for (int i = 0; i < n_ - 1; ++i) add(i, v[i]);
  }

  // [p] -> [p] + x
  // O(logN)
  void add(int p, T x) {
    ++p;
    while (p < n_) {
      d_[p] += x;
      p += p & -p;
    }
  }

  // [l, r)
  // O(logN)
  T get(int l, int r) const {
    T s = 0;
    while (l < r) {
      s += d_[r];
      r -= r & -r;
    }
    while (r < l) {
      s -= d_[l];
      l -= l & -l;
    }
    return s;
  }

  // smallest p for which sum of [0, p] >= x
  // O(logN)
  int lower_bound(T x) const {
    if (x <= 0) return 0;
    int p = 0, k = 1;
    while (k < n_ - 1) k <<= 1;
    while (k) {
      if (p + k <= n_ - 1 && d_[p + k] < x) {
        x -= d_[p + k];
        p += k;
      }
      k >>= 1;
    }
    return p;
  }

 private:
  int n_;
  std::vector<T> d_;
};