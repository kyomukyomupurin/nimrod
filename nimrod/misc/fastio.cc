#include <charconv>
#include <cstring>
#include <iostream>

// snippet-begin
namespace fast_io {
class scanner {
 public:
  scanner() { fread(buf, 1, sz, stdin); }

  template <class T>
  inline scanner& operator>>(T& x) {
    skip();
    scan(x);
    return *this;
  }

 private:
  static constexpr int sz = 1 << 19;
  char buf[sz];
  char* cur = buf;

  inline void reload() {
    int d = buf + sz - cur;
    std::memcpy(buf, cur, d);
    fread(buf + d, 1, sz - d, stdin);
    cur = buf;
  }

  inline void skip() {
    while (*cur == ' ' || *cur == '\n') ++cur;
  }

  inline void scan(int& n) {
    if (cur + 12 >= buf + sz) reload();
    cur = const_cast<char*>(std::from_chars(cur, cur + 12, n).ptr);
  }

  inline void scan(long long& n) {
    if (cur + 20 >= buf + sz) reload();
    cur = const_cast<char*>(std::from_chars(cur, cur + 20, n).ptr);
  }
};

class printer {
 public:
  printer() {}

  ~printer() { flush(); }

  template <class T>
  inline printer& operator<<(T x) {
    print(x);
    return *this;
  }

  template <class T>
  inline void println(T x) {
    print(x);
    print('\n');
  }

 private:
  static constexpr int sz = 1 << 19;
  char buf[sz];
  char* cur = buf;

  void flush() {
    fwrite(buf, 1, cur - buf, stdout);
    cur = buf;
  }

  inline void print(int n) {
    if (cur + 12 >= buf + sz) flush();
    cur = std::to_chars(cur, cur + 12, n).ptr;
  }

  inline void print(long long n) {
    if (cur + 20 >= buf + sz) flush();
    cur = std::to_chars(cur, cur + 20, n).ptr;
  }

  inline void print(char c) {
    if (cur + 1 >= buf + sz) flush();
    *cur = c;
    ++cur;
  }

  inline void print(const std::string& s) {
    if (cur + s.size() >= buf + sz) flush();
    std::strcpy(cur, s.data());
    cur += s.size();
  }

  inline void print(const char* s) { print(std::string(s)); }
};
}  // namespace fast_io

fast_io::scanner in;
fast_io::printer out;