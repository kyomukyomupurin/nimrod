#include <vector>

template <class T>
class cumulative {
 public:
  explicit cumulative(const std::vector<T>& v) {
    s_.resize(v.size() + 1);
    s_[0] = 0;
    std::partial_sum(v.begin(), v.end(), s_.begin() + 1);
    for (int i = 0; i < int(v.size()); ++i) {
      s_[i + 1] = s_[i] + v[i];
    }
  }

  T get(int l, int r) const { return s_[r + 1] - s_[l]; }

 private:
  std::vector<T> s_;
};