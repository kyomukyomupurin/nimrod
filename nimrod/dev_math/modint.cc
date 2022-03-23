#include <algorithm>
#include <cassert>
#include <iostream>

using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

template <int mod>
class modular {
 public:
  modular(i64 val = 0) : val_(val % mod) {
    if (val_ < 0) val_ += mod;
  }

  modular& operator+=(const modular& rhs) {
    if ((val_ += rhs.val_) >= mod) val_ -= mod;
    return *this;
  }

  modular& operator-=(const modular& rhs) {
    if ((val_ -= rhs.val_) < 0) val_ += mod;
    return *this;
  }

  modular& operator*=(const modular& rhs) {
    (val_ *= rhs.val_) %= mod;
    if (val_ < 0) val_ += mod;
    return *this;
  }

  modular& operator/=(const modular& rhs) {
    return *this *= modular(inverse(rhs.val_, static_cast<i64>(mod)));
  }

  modular operator+(const modular rhs) const { return modular(*this) += rhs; }

  modular operator-(const modular rhs) const { return modular(*this) -= rhs; }

  modular operator*(const modular rhs) const { return modular(*this) *= rhs; }

  modular operator/(const modular rhs) const { return modular(*this) /= rhs; }

  bool operator==(const modular rhs) const { return val_ == rhs.val_; }

  bool operator!=(const modular rhs) const { return val_ != rhs.val_; }

  friend std::istream& operator>>(std::istream& is, modular& x) {
    i64 n;
    is >> n;
    x = modular(n);
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const modular& x) {
    return os << x.val_;
  }

  template <class T>
  modular pow(T exp) const {
    modular x = val_, res = 1;
    while (exp != 0) {
      if ((exp & 1) == 1) res *= x;
      x *= x;
      exp >>= 1;
    }
    return res;
  }

 private:
  i64 val_;
  i64 inverse(i64 a, i64 m) {
    i64 u = 0, v = 1;
    while (a != 0) {
      i64 t = m / a;
      m -= t * a;
      std::swap(a, m);
      u -= t * v;
      std::swap(u, v);
    }
    assert(m == 1);
    return u;
  }
};

using mint = modular<1000000007>;
// using mint = modular<998244353>;