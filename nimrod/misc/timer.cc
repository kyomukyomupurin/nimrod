#include <chrono>

class timer {
 public:
  timer() {}

  void start() { beg = std::chrono::high_resolution_clock::now(); }

  auto elapsed() {
    auto ed = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(ed - beg)
        .count();
  }

 private:
  std::chrono::high_resolution_clock::time_point beg;
};