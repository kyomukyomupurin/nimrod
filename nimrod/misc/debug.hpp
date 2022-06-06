#include <iostream>
#include <tuple>

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

template <
    class Container, class T = typename Container::value_type,
    std::enable_if_t<!std::is_same<Container, std::string>::value>* = nullptr>
std::ostream& operator<<(std::ostream& os, Container const& container) {
  bool f = true;
  for (auto&& e : container) {
    os << (f ? "{" : ", ") << e;
    f = false;
  }
  return os << (f ? "{}" : "}");
}

#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}