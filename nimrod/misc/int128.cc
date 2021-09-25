#include <algorithm>
#include <iostream>
#include <string>

// snippet-begin
__int128_t to_int128(const std::string& s) {
  __int128_t n = 0;
  bool neg = s[0] == '-';
  for (int i = int(neg); i < int(s.size()); ++i) {
    n = n * 10 + (s[i] & 0b1111);
  }
  return neg ? -n : n;
}

__int128_t to_int128(const char* c) { return to_int128(std::string(c)); }

std::string to_string(const __int128_t& n) {
  if (n == 0) return "0";
  std::string s = "";
  __int128_t t = n;
  bool neg = n < 0;
  if (neg) t = -t;
  while (t) {
    s += char(t % 10 | 0b110000);
    t /= 10;
  }
  if (neg) s += '-';
  std::reverse(s.begin(), s.end());
  return s;
}

std::istream& operator>>(std::istream& is, __int128_t& n) {
  std::string s;
  is >> s;
  n = to_int128(s);
  return is;
}

std::ostream& operator<<(std::ostream& os, const __int128_t& n) {
  return os << to_string(n);
}