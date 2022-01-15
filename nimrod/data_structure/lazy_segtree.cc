#include <vector>

template <class M, class OM, class F1, class F2, class F3>
class lazy_segtree {
 public:
  explicit lazy_segtree(int n, M ie, OM oie, F1 f1, F2 f2, F3 f3)
      : ie_(ie), oie_(oie), f1_(f1), f2_(f2), f3_(f3) {
    sz_ = 1, h_ = 0;
    while (sz_ < n) sz_ <<= 1, ++h_;
    d_.assign(2 * sz_, ie_);
    lazy_.assign(2 * sz_, oie_);
    for (int i = sz_ - 1; i > 0; --i) d_[i] = f1_(d_[2 * i], d_[2 * i + 1]);
  }

  explicit lazy_segtree(const std::vector<M>& v, M ie, OM oie, F1 f1, F2 f2,
                        F3 f3)
      : ie_(ie), oie_(oie), f1_(f1), f2_(f2), f3_(f3) {
    int n = int(v.size());
    sz_ = 1, h_ = 0;
    while (sz_ < n) sz_ <<= 1, ++h_;
    d_.assign(2 * sz_, ie_);
    lazy_.assign(2 * sz_, oie_);
    for (int i = 0; i < n; ++i) d_[i + sz_] = v[i];
    for (int i = sz_ - 1; i > 0; --i) d_[i] = f1_(d_[2 * i], d_[2 * i + 1]);
  }

  // [p] -> f3([p], x) for p in [l, r)
  // O(logN)
  void modify(int l, int r, OM x) {
    if (l >= r) return;
    thrust(l += sz_);
    thrust(r += sz_ - 1);
    for (int cl = l, cr = r + 1; cl < cr; cl >>= 1, cr >>= 1) {
      if (cl & 1) lazy_[cl] = f3_(lazy_[cl], x), ++cl;
      if (cr & 1) --cr, lazy_[cr] = f3_(lazy_[cr], x);
    }
    recalc(l);
    recalc(r);
  }

  // [l, r)
  // O(logN)
  M get(int l, int r) {
    if (l >= r) return ie_;
    thrust(l + sz_);
    thrust(r + sz_ - 1);
    M vl = ie_, vr = ie_;
    for (l += sz_, r += sz_; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f1_(vl, apply(l++));
      if (r & 1) vr = f1_(apply(--r), vr);
    }
    return f1_(vl, vr);
  }

 private:
  int sz_, h_;
  std::vector<M> d_;
  std::vector<OM> lazy_;
  M ie_;
  OM oie_;
  F1 f1_;
  F2 f2_;
  F3 f3_;

  inline void propagate(int p) {
    if (lazy_[p] != oie_) {
      lazy_[2 * p] = f3_(lazy_[2 * p], lazy_[p]);
      lazy_[2 * p + 1] = f3_(lazy_[2 * p + 1], lazy_[p]);
      d_[p] = apply(p);
      lazy_[p] = oie_;
    }
  }

  inline M apply(int p) {
    if (lazy_[p] == oie_) {
      return d_[p];
    } else {
      return f2_(d_[p], lazy_[p]);
    }
  }

  inline void recalc(int p) {
    while (p >>= 1) d_[p] = f1_(apply(2 * p), apply(2 * p + 1));
  }

  inline void thrust(int p) {
    for (int i = h_; i > 0; --i) propagate(p >> i);
  }
};