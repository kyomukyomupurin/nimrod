#include <algorithm>
#include <cassert>
#include <vector>

template <class T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    std::swap(a, m);
    u -= t * v;
    std::swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <int mod>
class Modular {
 public:
  constexpr Modular(long long val = 0) : val_(val % mod()) {
    if (val_ < 0) val_ += mod();
  }

  const long long& operator()() const noexcept { return val_; }

  constexpr int mod() const noexcept { return mod; }

  constexpr Modular& operator+=(const Modular& other) noexcept {
    if ((val_ += other.val_) >= mod()) val_ -= mod();
    return *this;
  }

  constexpr Modular& operator-=(const Modular& other) noexcept {
    if ((val_ -= other.val_) < 0) val_ += mod();
    return *this;
  }

  constexpr Modular& operator*=(const Modular& other) noexcept {
    (val_ *= other.val_) %= mod();
    if (val_ < 0) val_ += mod();
    return *this;
  }

  constexpr Modular& operator/=(const Modular& other) noexcept {
    return *this *= Modular(inverse(other.val_, static_cast<long long>(mod())));
  }

  constexpr Modular& operator++() noexcept { return *this += 1; }

  constexpr Modular& operator--() noexcept { return *this -= 1; }

  constexpr Modular operator-() const noexcept { return Modular(-val_); }

  friend std::istream& operator>>(std::istream& is, Modular& x) {
    long long n;
    is >> n;
    x = Modular(n);
    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const Modular& x) {
    return os << x();
  }

 private:
  long long val_;
};

constexpr int md = int(1e9) + 7;
using mint = Modular<md>;

mint operator+(const mint& lhs, const mint& rhs) noexcept {
  return mint(lhs) += rhs;
}

mint operator-(const mint& lhs, const mint& rhs) noexcept {
  return mint(lhs) -= rhs;
}

mint operator*(const mint& lhs, const mint& rhs) noexcept {
  return mint(lhs) *= rhs;
}

mint operator/(const mint& lhs, const mint& rhs) noexcept {
  return mint(lhs) /= rhs;
}

bool operator==(const mint& lhs, const mint& rhs) noexcept {
  return lhs() == rhs();
}

bool operator!=(const mint& lhs, const mint& rhs) noexcept {
  return !(lhs() == rhs());
}

template <class T>
mint power(const mint& a, T b) {
  assert(b >= 0);
  mint x = a, res = 1;
  while (b) {
    if (b & 1) res *= x;
    x *= x;
    b >>= 1;
  }
  return res;
}

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
