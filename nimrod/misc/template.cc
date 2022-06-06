#include <algorithm>
#include <bit>
#include <cassert>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstring>
#include <deque>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using i64 = int64_t;

#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...) void(0)
#endif

void Yes(bool f) { cout << (f ? "Yes" : "No") << '\n'; }
void YES(bool f) { cout << (f ? "YES" : "NO") << '\n'; }
template <class T> istream& operator>>(istream& is, vector<T>& v) { for (auto&& e : v) is >> e; return is; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(17);


  return 0;
}