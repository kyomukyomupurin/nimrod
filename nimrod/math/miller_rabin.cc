#include <initializer_list>

// snippet-begin
namespace miller_rabin {
template <class T, class U>
T power(T base, U exp, U mod) {
  T res = 1;
  base %= mod;
  while (exp) {
    if (exp & 1) (res *= base) %= mod;
    (base *= base) %= mod;
    exp >>= 1;
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