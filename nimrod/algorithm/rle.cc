#include <string>
#include <vector>

// snippet-begin
std::vector<std::pair<char, int>> rle(const std::string& s) {
  int n = s.size();
  std::vector<std::pair<char, int>> v;
  int beg = 0;
  while (beg < n) {
    int ed = beg;
    while (ed + 1 < n && s[beg] == s[ed + 1]) ++ed;
    v.emplace_back(s[beg], ed - beg + 1);
    beg = ed + 1;
  }
  return v;
}

template <class T>
std::vector<std::pair<T, int>> rle(const std::vector<T>& v) {
  int n = v.size();
  std::vector<std::pair<T, int>> vp;
  int beg = 0;
  while (beg < n) {
    int ed = beg;
    while (ed + 1 < n && v[beg] == v[ed + 1]) ++ed;
    vp.emplace_back(v[beg], ed - beg + 1);
    beg = ed + 1;
  }
  return vp;
}