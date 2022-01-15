#include <string>

#include "../../nimrod/math/modint.cc"

class rolling_hash {
 public:
  static constexpr int mod1 = 998244353;
  static constexpr int mod2 = 1000000007;
  static constexpr int base1 = 1000;
  static constexpr int base2 = 1006;
  using mint1 = modint<mod1>;
  using mint2 = modint<mod2>;
  using hashes = std::pair<mint1, mint2>;

  rolling_hash(const std::string& s) {
    int n = int(s.size());
    h1_.reserve(n + 1);
    h2_.reserve(n + 1);
    h1_.push_back(1);
    h2_.push_back(1);
    for (int i = 0; i < n; ++i) {
      h1_.push_back(h1_.back() * base1 + s[i]);
      h2_.push_back(h2_.back() * base2 + s[i]);
    }
    while (int(p1_.size()) < n + 1) {
      p1_.push_back(p1_.back() * base1);
      p2_.push_back(p2_.back() * base2);
    }
  }

  hashes get(int l, int r) const {
    mint1 hash1 = h1_[r] - (h1_[l] * p1_[r - l]);
    mint2 hash2 = h2_[r] - (h2_[l] * p2_[r - l]);
    return {hash1, hash2};
  }

 private:
  std::vector<mint1> h1_;
  std::vector<mint2> h2_;
  static std::vector<mint1> p1_;
  static std::vector<mint2> p2_;
};