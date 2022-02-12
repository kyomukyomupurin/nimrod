#include <vector>

// snippet-begin
template <class T>
class cumulative_2d {
 public:
  explicit cumulative_2d(const std::vector<std::vector<T>>& v) {
    x_ = int(v.size());
    y_ = int(v[0].size());
    s_.assign(x_ + 1, std::vector<T>(y_ + 1, 0));
    for (int i = 0; i < x_; ++i) {
      for (int j = 0; j < y_; ++j) {
        s_[i][j + 1] = s_[i][j] + v[i][j];
      }
    }
    for (int i = 0; i < y_; ++i) {
      for (int j = 0; j < x_; ++j) {
        s_[j + 1][i + 1] += s_[j][i + 1];
      }
    }
  }

  // [sx, gx] * [sy, gy]
  // O(1)
  T get(int sx, int sy, int gx, int gy) {
    return s_[gx + 1][gy + 1] - s_[gx + 1][sy] - s_[sx][gy + 1] + s_[sx][sy];
  }

 private:
  int x_;
  int y_;
  std::vector<std::vector<T>> s_;
};