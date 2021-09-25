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

bool is_prime(unsigned int n) {
  if (n < 2) return false;
  for (unsigned int x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}) {
    if (n % x == 0) {
      return n == x;
    }
  }
  if (n < 37 * 37) return true;
  int s = __builtin_ctz(n - 1);
  unsigned int d = (n - 1) >> s;
  for (unsigned int a : {2, 7, 61}) {
    if (a % n == 0) continue;
    unsigned long long cur = a;
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

bool is_prime(unsigned long long n) {
  if (n < 2) return false;
  for (unsigned long long x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}) {
    if (n % x == 0) {
      return n == x;
    }
  }
  if (n < 37 * 37) return true;
  int s = __builtin_ctzll(n - 1);
  unsigned long long d = (n - 1) >> s;
  for (unsigned long long a :
       {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (a % n == 0) continue;
    __uint128_t cur = a;
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

bool is_prime(int n) { return is_prime(static_cast<unsigned int>(n)); }

bool is_prime(long long n) {
  return is_prime(static_cast<unsigned long long>(n));
}
}  // namespace miller_rabin

using miller_rabin::is_prime;