#include <algorithm>
#include <bit>
#include <initializer_list>
#include <vector>

using u64 = uint64_t;
using u128 = __uint128_t;

namespace fast_math {
template <class T>
T binary_gcd(T x, T y) {
  if (x == 0) return y;
  if (y == 0) return x;
  int s = std::__countr_zero(x | y);
  x >>= std::__countr_zero(x);
  do {
    y >>= std::__countr_zero(y);
    if (x > y) std::swap(x, y);
    y -= x;
  } while (y != 0);
  return x << s;
}

template <class T>
T power(T base, u64 exp, u64 mod) {
  T res = 1;
  base %= mod;
  while (exp != 0) {
    if ((exp & 1) == 1) (res *= base) %= mod;
    (base *= base) %= mod;
    exp >>= 1;
  }
  return res;
}

template <class T>
bool internal_is_prime(u64 n, const std::vector<u64>& bases) {
  if (n < 2) return false;
  for (u64 x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}) {
    if (n % x == 0) return n == x;
  }
  if (n < 37 * 37) return true;
  int s = std::__countr_zero(n - 1);
  u64 d = (n - 1) >> s;
  for (u64 a : bases) {
    if (a % n == 0) continue;
    T cur = a;
    cur = power(cur, d, n);
    if (cur == 1) continue;
    bool witness = true;
    for (int r = 0; r < s; ++r) {
      if (cur == n - 1) {
        witness = false;
        break;
      }
      (cur *= cur) %= n;
    }
    if (witness) return false;
  }
  return true;
}

bool is_prime(u64 n) {
  if (n <= (u64(1) << 32)) {
    return internal_is_prime<u64>(n, {2, 7, 61});
  } else {
    return internal_is_prime<u128>(
        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
  }
}

u64 pollard_rho(u64 n, int c = 1) {
  if (is_prime(n)) return n;
  if ((n & 1) == 0) return 2;
  u64 x = 2, y = 2, g;
  do {
    x = (u128(x) * x + c) % n;
    y = (u128(y) * y + c) % n;
    y = (u128(y) * y + c) % n;
    g = binary_gcd(x > y ? x - y : y - x, n);
  } while (g == 1);
  return (g < n ? g : pollard_rho(n, c + 1));
}

std::vector<u64> internal_factors(u64 n) {
  if (n <= 1) return {};
  if (is_prime(n)) return {n};
  u64 p = pollard_rho(n);
  std::vector<u64> l = internal_factors(p);
  std::vector<u64> r = internal_factors(n / p);
  std::copy(r.begin(), r.end(), std::back_inserter(l));
  return l;
}

std::vector<u64> factors(u64 n) {
  std::vector<u64> res = internal_factors(n);
  std::sort(res.begin(), res.end());  // Is this really necessary?
  return res;
}
}  // namespace fast_math