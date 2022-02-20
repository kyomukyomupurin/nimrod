#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../nimrod/misc/fastio.cc"

using i64 = int64_t;

int main() {
  int T;
  in >> T;
  while (T--) {
    i64 A, B;
    in >> A >> B;
    out.println(A + B);
  }
  return 0;
}