#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B"
#include <iostream>

#include "../../nimrod/string/rolling_hash.cc"

int main() {
  std::string T, P;
  std::cin >> T >> P;
  rolling_hash rh1(T);
  rolling_hash rh2(P);
  int n = T.size(), m = P.size();
  for (int i = 0; i + m <= n; ++i) {
    if (rh1.get(i, i + m) == rh2.get(0, m)) {
      std::cout << i << '\n';
    }
  }
  return 0;  
}