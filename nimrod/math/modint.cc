#include <algorithm>
#include <cassert>
#include <vector>

// snippet-begin
template <int mod>
class modint {
 public:
  constexpr modint(long long val = 0) : val_(val % mod) {
    if (val_ < 0) val_ += mod;
  }
  const long long& operator()() const { return val_; }
  constexpr modint& operator+=(const modint& rhs) {
    if ((val_ += rhs.val_) >= mod) val_ -= mod;
    return *this;
  }
  constexpr modint& operator-=(const modint& rhs) {
    if ((val_ -= rhs.val_) < 0) val_ += mod;
    return *this;
  }
  constexpr modint& operator*=(const modint& rhs) {
    (val_ *= rhs.val_) %= mod;
    if (val_ < 0) val_ += mod;
    return *this;
  }
  constexpr modint& operator/=(const modint& rhs) {
    return *this *= modint(inverse(rhs.val_, static_cast<long long>(mod)));
  }
  constexpr modint operator+(const modint rhs) const {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const {
    return modint(*this) /= rhs;
  }
  constexpr bool operator==(const modint rhs) const {
    return val_ == rhs.val_;
  }
  constexpr bool operator!=(const modint rhs) const {
    return val_ != rhs.val_;
  }
  constexpr modint& operator++() { return *this += 1; }
  constexpr modint& operator--() { return *this -= 1; }
  constexpr modint operator-() const { return modint(-val_); }
  friend std::istream& operator>>(std::istream& is, modint& x) {
    long long n;
    is >> n;
    x = modint(n);
    return is;
  }
  friend std::ostream& operator<<(std::ostream& os, const modint& x) {
    return os << x();
  }
  template <class T>
  constexpr modint pow(T exp) const {
    modint x = val_, res = 1;
    while (exp) {
      if (exp & 1) res *= x;
      x *= x;
      exp >>= 1;
    }
    return res;
  }

 private:
  long long val_;
  long long inverse(long long a, long long m) {
    long long u = 0, v = 1;
    while (a != 0) {
      long long t = m / a;
      m -= t * a;
      std::swap(a, m);
      u -= t * v;
      std::swap(u, v);
    }
    assert(m == 1);
    return u;
  }
};

// std::vector<mint> fact{1, 1};
// std::vector<mint> inv{0, 1};
// std::vector<mint> ifact{1, 1};

// mint choose(int n, int k) noexcept {
//   if (n < k || n < 0 || k < 0) return 0;
//   while (int(fact.size()) < n + 1) {
//     int sz = fact.size();
//     fact.emplace_back(fact.back() * sz);
//     inv.emplace_back(md - inv[md % sz] * (md / sz));
//     ifact.emplace_back(ifact.back() * inv.back());
//   }
//   return fact[n] * ifact[k] * ifact[n - k];
// }