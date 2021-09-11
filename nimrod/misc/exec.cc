#include <memory>
#include <stdexcept>
#include <string>

std::string exec(const char* cmd) {
  constexpr int sz = 1 << 7;
  char buf[sz];
  std::string s;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buf, sz, pipe.get()) != nullptr) {
    s += std::string(buf);
  }
  return s;
}