#include <map>

// snippet-begin
template <class T>
std::map<T, int> factor(T n) {
  std::map<T, int> m;
  for (T i = 2; i * i <= n; ++i) {
    if (n % i != 0) continue;
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      ++cnt;
    }
    m[i] = cnt;
  }
  if (n != 1) m[n] = 1;
  return m;
}