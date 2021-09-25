#include <string>
#include <vector>

// snippet-begin
std::vector<int> manacher(const std::string& s) {
  int n = s.size();
  std::vector<int> v(n);
  int i = 0, j = 0;
  while (i < n) {
    while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
    v[i] = j;
    int k = 1;
    while (i - k >= 0 && k + v[i - k] < j) {
      v[i + k] = v[i - k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return v;
}