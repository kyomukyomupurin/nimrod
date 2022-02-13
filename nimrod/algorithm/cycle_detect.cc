#include <utility>

// Brent's cycle detection algorithm
// https://en.wikipedia.org/wiki/Cycle_detection#Brent's_algorithm
// a(=x0)  b  c  d  e  f  g  h  i  j  k  i  j  k  ...
// <------------------------->  <----->  <----->
//              μ                  λ
// Start at x0 and move it μ times to enter the loop (=i)
// f(a) = b, f(b) = c, ...
// f is an element-to-element map
// ex. auto f = [&](int p) -> int { return a[p] - 1; };
// time complexity : O(μ+λ)
// space complexity : O(1)
// https://atcoder.jp/contests/abc167/submissions/29252589
template <class T, class F>
class cycle {
 public:
  cycle(T x0, F f) : x0_(x0), mu_(0), lambda_(1), f_(f) {
    int power = 1;
    int tortoise = x0;
    int hare = f(x0);
    while (tortoise != hare) {
      if (power == lambda_) {
        tortoise = hare;
        power <<= 1;
        lambda_ = 0;
      }
      advance(hare);
      ++lambda_;
    }
    tortoise = hare = x0;
    for (int i = 0; i < lambda_; ++i) advance(hare);
    while (tortoise != hare) {
      advance(tortoise);
      advance(hare);
      ++mu_;
    }
  }

  template <class U>
  T after_k_moves(U k) {
    T x = x0_;
    if (k <= mu_) {
      for (int i = 0; i < int(k); ++i) advance(x);
    } else {
      for (int i = 0; i < mu_; ++i, --k) advance(x);
      k %= lambda_;
      for (int i = 0; i < int(k); ++i) advance(x);
    }
    return x;
  }

  int mu() const { return this->mu_; }

  int lambda() const { return this->lambda_; }

 private:
  int x0_;
  int mu_;
  int lambda_;
  F f_;

  inline void advance(T& x) { x = f_(x); }
};