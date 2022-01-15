#include <vector>

// snippet-begin
template <class M, class F>
class segtree {
 public:
  explicit segtree(int n, M ie, F f) : ie_(ie), f_(f) {
    sz_ = 1;
    while (sz_ < n) sz_ <<= 1;
    d_.assign(2 * sz_, ie_);
  }

  explicit segtree(const std::vector<M>& v, M ie, F f) : ie_(ie), f_(f) {
    sz_ = 1;
    int n = int(v.size());
    while (sz_ < n) sz_ <<= 1;
    d_.assign(2 * sz_, ie_);
    for (int i = 0; i < n; ++i) d_[i + sz_] = v[i];
    for (int i = sz_ - 1; i > 0; --i) d_[i] = f_(d_[2 * i], d_[2 * i + 1]);
  }

  // [p] -> x
  // O(logN)
  void update(int p, M x) {
    p += sz_;
    d_[p] = x;
    while (p) {
      p >>= 1;
      d_[p] = f_(d_[2 * p], d_[2 * p + 1]);
    }
  }

  // [l, r)
  // O(logN)
  M get(int l, int r) const {
    M vl = ie_, vr = ie_;
    for (l += sz_, r += sz_; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f_(vl, d_[l++]);
      if (r & 1) vr = f_(d_[--r], vr);
    }
    return f_(vl, vr);
  }

  // [0, N)
  // O(1)
  M all() const { return d_[1]; }

  // [p]
  // O(1)
  M operator[](int p) const { return d_[p + sz_]; }

 private:
  int sz_;
  M ie_;
  F f_;
  std::vector<M> d_;
};