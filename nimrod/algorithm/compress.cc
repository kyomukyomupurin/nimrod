#include <algorithm>
#include <vector>

// snippet-begin
template <class T>
class compress {
 public:
  explicit compress(const std::vector<T>& v) : d_(v) {
    n_ = int(v.size());
    std::sort(d_.begin(), d_.end());
    d_.erase(std::unique(d_.begin(), d_.end()), d_.end());
  }

  T find_by_order(int p) const { return d_[p]; }

  int find_by_value(T x) const {
    return std::distance(d_.begin(), std::lower_bound(d_.begin(), d_.end(), x));
  }

  int size() const { return n_; }

 private:
  int n_;
  std::vector<T> d_;
};