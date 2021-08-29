#include <vector>

template <class T>
class fenwick {
 public:
  explicit fenwick(int n) : n_(n + 1) { d_.assign(n_, 0); }

  explicit fenwick(const std::vector<T>& v) : {
    n_ = int(v.size()) + 1;
    d_.assign(n_, 0);
    for (int i = 0; i < n_ - 1; ++i) add(i, d_[i]);
  }

  void add(int p, T x) {
    ++p;
    while (p < n_) {
      d_[p] += x;
      p += p & -p;
    }
  }

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

  int lower_bound(T x) const {
    if (x <= 0) return 0;
    int p = 0, k = 1;
    while (k < n_ - 1) k <<= 1;
    while (k) {
      if (p + k <= n_ - 1 && d[p + k] < x) {
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