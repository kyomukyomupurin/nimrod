#include <vector>

// snippet-begin
template <class T>
class fenwick_2d {
 public:
  explicit fenwick_2d(int x, int y) : x_(x), y_(y) {
    d_.assign(x_ + 1, std::vector<T>(y_ + 1, 0));
  }

  explicit fenwick_2d(const std::vector<std::vector<T>>& v) {
    x_ = int(v.size());
    y_ = int(v[0].size());
    d_.assign(x_ + 1, std::vector<T>(y_ + 1, 0));
    for (int i = 0; i < x_; ++i) {
      for (int j = 0; j < y_; ++j) {
        add(i, j, v[i][j]);
      }
    }
  }

  void add(int x, int y, T x) {
    for (int i = x + 1; i < x_ + 1; i += i & -i) {
      for (int j = y + 1; j < y_ + 1; j += j & -j) {
        d_[i][j] += x;
      }
    }
  }

  T get(int x, int y) const {
    T s = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
      for (int j = y + 1; j > 0; j -= j & -j) {
        s += d_[i][j];
      }
    }
    return s;
  }

  T get(int sx, int sy, int gx, int gy) const {
    return get(gx, gy) - get(sx - 1, gy) - get(gx, sy - 1) +
           get(sx - 1, sy - 1);
  }

 private:
  int x_;
  int y_;
  std::vector<std::vector<T>> d_;
};