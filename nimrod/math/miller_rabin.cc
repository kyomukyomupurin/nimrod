#include <initializer_list>

namespace miller_rabin {
long long power(long long n, int x, int mod) {
  long long res = 1;
  n %= mod;
  while (x) {
    if (x & 1) (res *= n) %= mod;
    (n *= n) %= mod;
    x >>= 1;
  }
  return res;
}

__int128_t power(__int128_t n, long long x, long long mod) {
  __int128_t res = 1;
  n %= mod;
  while (x) {
    if (x & 1) (res *= n) %= mod;
    (n *= n) %= mod;
    x >>= 1;
  }
  return res;
}

bool is_prime(int n) {
  if (n < 2) return false;
  int s = __builtin_ctz(n - 1);
  int d = (n - 1) >> s;
  for (int a : {2, 7, 61}) {
    if (a % n == 0) continue;
    long long cur = a;
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

bool is_prime(long long n) {
  if (n < 2) return false;
  int s = __builtin_ctzll(n - 1);
  long long d = (n - 1) >> s;
  for (long long a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (a % n == 0) continue;
    __int128_t cur = a;
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
}  // namespace miller_rabin

using miller_rabin::is_prime;