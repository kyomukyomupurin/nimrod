#include <algorithm>
#include <string>
#include <vector>

std::string lcs(const std::string& s1, const std::string& s2) {
  int n1 = s1.size(), n2 = s2.size();
  std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      if (s1[i] == s2[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  std::string s = "";
  while (n1 > 0 && n2 > 0) {
    if (s1[n1 - 1] == s2[n2 - 1]) {
      s += s1[n1];
      --n1;
      --n2;
    } else {
      (dp[n1][n2] == dp[n1][n2 - 1]) ? --n2 : --n1;
    }
  }
  std::reverse(s.begin(), s.end());
  return s;
}