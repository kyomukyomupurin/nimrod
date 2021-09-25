#include <string>
#include <vector>

// snippet-begin
std::vector<int> z_algorithm(const std::string& s) {
  int n = s.size();
  std::vector<int> v(n);
  v[0] = n;
  int i = 1, j = 0;
  while (i < n) {
    while (i + j < n && s[j] == s[i + j]) ++j;
    v[i] = j;
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < n && k + v[k] < j) {
      v[i + k] = v[k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return v;
}