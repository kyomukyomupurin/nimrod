#include <cmath>

template <class F>
std::pair<double, double> golden_search(double low, double high, const F& f) {
  const double phi = (1 + std::sqrt(5)) / 2;
  double s1 = (phi * low + high) / (1 + phi);
  double s2 = (low + phi * high) / (1 + phi);
  double y1 = f(s1), y2 = f(s2);
  for (int i = 0; i < 150; ++i) {
    if (y1 > y2) {
      low = s1;
      y1 = y2;
      s1 = s2;
      s2 = (low + phi * high) / (1 + phi);
      y2 = f(s2);
    } else {
      high = s2;
      y2 = y1;
      s2 = s1;
      s1 = (phi * low + high) / (1 + phi);
      y1 = f(s1);
    }
  }
  return {low, y1};
}