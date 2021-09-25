#include <string>
#include <vector>

// snippet-begin
class next_char {
 public:
  explicit next_char(const std::string& s) {
    n_ = s.size();
    t_.resize(26, std::vector<int>(n_));
    for (char c = 'a'; c <= 'z'; ++c) {
      int p = n_;
      for (int i = n_ - 1; i >= 0; --i) {
        if (s[i] == c) p = i;
        t_[c - 'a'][i] = p;
      }
    }
  }

  int find(int p, char c) const { return t_[c - 'a'][p]; }

  bool contains(char c) const { return find(0, c) != n_; }

 private:
  int n_;
  std::vector<std::vector<int>> t_;
};