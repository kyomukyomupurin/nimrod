#include <string>
#include <vector>

// snippet-begin
std::vector<std::string> split(const std::string& s) {
  std::vector<std::string> v;
  std::string t;
  for (auto&& c : s) {
    if (std::isspace(c)) {
      if (t.empty()) continue;
      v.emplace_back(t);
      t.clear();
    } else {
      t += c;
    }
  }
  return v;
}