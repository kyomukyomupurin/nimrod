#include <vector>

template <class OM, class F>
class dual_segtree {
 public:
  explicit dual_segtree(int n, OM oie, F f) {
    sz_ = 1, h_ = 0;
    while (sz_ < n) sz_ <<= 1, ++h_;
    lazy_.assign(2 * sz_, oie_);
  }

  // [p] -> f([p], x) for p in [l, r)
  // O(logN)
  void modify(int l, int r, OM x) {
    thrust(l + sz_);
    thrust(r + sz_ - 1);
    for (l += sz_, r += sz_; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lazy_[l] = f_(lazy_[l], x), ++l;
      if (r & 1) --r, lazy_[r] = f_(lazy_[r], x);
    }    
  }

  // [p]
  // O(logN)
  OM operator[](int p) {
    p += sz_;
    thrust(p);
    return lazy_[p];
  }

 private:
  int sz_, h_;
  std::vector<OM> lazy_;
  OM oie_;
  F f_;

  inline void propagate(int p) {
    if (lazy_[p] != oie_) {
      lazy_[2 * p] = f_(lazy_[2 * p], lazy_[p]);
      lazy_[2 * p + 1] = f_(lazy_[2 * p + 1], lazy_[p]);
      lazy_[p] = oie_;
    }
  }

  inline void thrust(int p) {
    for (int i = h_; i > 0; --i) propagate(p >> i);
  }
};