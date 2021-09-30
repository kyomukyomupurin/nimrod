#include <algorithm>

#include "miller_rabin.cc"

namespace pollard_rho {
unsigned int binary_gcd(unsigned int x, unsigned int y) {
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

unsigned long long binary_gcd(unsigned long long x, unsigned long long y) {
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

unsigned long long rho(unsigned long long n) {
  unsigned long long x = 2, y = 2, c = 1, g;
  do {
    x = (x * x + c) % n;
    y = (y * y + c) % n;
    y = (x * y + c) % n;
  } while (g = binary_gcd(x > y ? x - y : y - x, n), g == 1, ++c);
  return g;
}
}