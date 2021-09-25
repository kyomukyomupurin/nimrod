#include <algorithm>
#include <vector>

// snippet-begin
template <class T>
std::vector<T> divisor(T n) {
  std::vector<int> v;
  for (T i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      v.emplace_back(i);
      if (i * i != n) v.emplace_back(n / i);
    }
  }
  std::sort(v.begin(), v.end());
  return v;
}