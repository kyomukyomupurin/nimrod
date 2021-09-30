#include <iostream>

struct timer {
  int64_t t_;
  static constexpr int64_t freq_ = 1800000000;

  double elapsed() {
    return static_cast<double>(cycle() - t_) / static_cast<double>(freq_);
  }

  void start() { t_ = cycle(); }

  int64_t cycle() {
    uint32_t low, high;
    __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
    return (static_cast<int64_t>(low)) | (static_cast<int64_t>(high) << 32);
  }
};