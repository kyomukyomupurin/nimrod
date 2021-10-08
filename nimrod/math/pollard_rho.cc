#include <algorithm>

#include "miller_rabin.cc"

// snippet-begin
namespace pollard_rho {
int binary_gcd(int x, int y) {
  if (x == 0) return y;
  if (y == 0) return x;
  int s = __builtin_ctz(x | y);
  x >>= __builtin_ctz(x);
  do {
    y >>= __builtin_ctz(y);
    if (x > y) std::swap(x, y);
    y -= x;
  } while (y);
  return x << s;
}

long long binary_gcd(long long x, long long y) {
  if (x == 0) return y;
  if (y == 0) return x;
  int s = __builtin_ctzll(x | y);
  x >>= __builtin_ctzll(x);
  do {
    y >>= __builtin_ctzll(y);
    if (x > y) std::swap(x, y);
    y -= x;
  } while (y);
  return x << s;
}

int rho(int n, int c = 1) {
  if (is_prime(n)) return n;
  int x = 2, y = 2, g;
  do {
    x = ((long long)(x)*x + c) % n;
    y = ((long long)(y)*y + c) % n;
    y = ((long long)(y)*y + c) % n;
    g = binary_gcd(x > y ? x - y : y - x, n);
  } while (g == 1);
  return (g < n ? g : rho(n, c + 1));
}

long long rho(long long n, int c = 1) {
  if (is_prime(n)) return n;
  long long x = 2, y = 2, g;
  do {
    x = (__int128_t(x) * x + c) % n;
    y = (__int128_t(y) * y + c) % n;
    y = (__int128_t(y) * y + c) % n;
    g = binary_gcd(x > y ? x - y : y - x, n);
  } while (g == 1);
  return (g < n ? g : rho(n, c + 1));
}
}  // namespace pollard_rho