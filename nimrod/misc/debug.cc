#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class Tuple, std::size_t... Is>
void tuple_out(std::ostream& os, const Tuple& t, std::index_sequence<Is...>) {
  ((os << (Is ? ", " : "(") << std::get<Is>(t)), ...) << ")";
}

template <class... Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) {
  tuple_out(os, t, std::index_sequence_for<Args...>{});
  return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  bool f = true;
  for (auto&& e : v) os << (f ? "{" : ", ") << e, f = false;
  return os << (f ? "{}" : "}");
}

template <class T, class Compare>
std::ostream& operator<<(std::ostream& os, const std::set<T, Compare>& s) {
  bool f = true;
  for (auto&& e : s) os << (f ? "{" : ", ") << e, f = false;
  return os << (f ? "{}" : "}");
}

template <class T, class U, class Compare>
std::ostream& operator<<(std::ostream& os, const std::map<T, U, Compare>& m) {
  bool f = true;
  for (auto&& e : m) os << (f ? "{" : ", ") << e, f = false;
  return os << (f ? "{}" : "}");
}

template <class T, class Compare>
std::ostream& operator<<(std::ostream& os, const std::multiset<T, Compare>& s) {
  bool f = true;
  for (auto&& e : s) os << (f ? "{" : ", ") << e, f = false;
  return os << (f ? "{}" : "}");
}

template <class T, class U, class Compare>
std::ostream& operator<<(std::ostream& os, const std::multimap<T, U, Compare>& m) {
  bool f = true;
  for (auto&& e : m) os << (f ? "{" : ", ") << e, f = false;
  return os << (f ? "{}" : "}");
}

#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) void(0)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}