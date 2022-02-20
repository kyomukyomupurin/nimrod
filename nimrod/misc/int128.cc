#include <algorithm>
#include <iostream>
#include <string>

using i128 = __int128_t;

// snippet-begin
i128 to_i128(const std::string& s) {
  i128 n = 0;
  bool neg = s[0] == '-';
  for (int i = int(neg); i < int(s.size()); ++i) {
    n = n * 10 + (s[i] & 15);
  }
  return neg ? -n : n;
}

i128 to_i128(const char* c) { return to_i128(std::string(c)); }

std::string to_string(const i128& n) {
  if (n == 0) return "0";
  std::string s = "";
  i128 t = n;
  bool neg = n < 0;
  if (neg) t = -t;
  while (t) {
    s += char(t % 10 | 48);
    t /= 10;
  }
  if (neg) s += '-';
  std::reverse(s.begin(), s.end());
  return s;
}

std::istream& operator>>(std::istream& is, i128& n) {
  std::string s;
  is >> s;
  n = to_i128(s);
  return is;
}

std::ostream& operator<<(std::ostream& os, const i128& n) {
  return os << to_string(n);
}