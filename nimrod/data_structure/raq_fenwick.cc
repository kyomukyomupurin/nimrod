#include <vector>

#include "./fenwick.cc"

template <class T>
class fenwick_raq {
 public:
  explicit fenwick_raq(int n) : n_(n), f1_(fenwick<T>(n)), f2_(fenwick<T>(n)) {}

  explicit fenwick_raq(const std::vector<T>& v)
      : n_(int(v.size())), f1_(fenwick<T>(v)), f2_(fenwick<T>(v)) {}

  void add(int l, int r, T x) {
    add(f1_, l, r, x);
    add(f2_, l, r, -x * (l - 1));
    add(f2_, r, n_, x * (r - l));
  }

  T get(int p) const { return f1_.get(0, p + 1) * p + f2_.get(0, p + 1); }

  T get(int l, int r) const { return get(r) - get(l - 1); }

 private:
  int n_;
  fenwick<T> f1_;
  fenwick<T> f2_;

  void add(fenwick<T>& f, int l, int r, T x) {
    f.add(l, x);
    f.add(r, -x);
  }
};