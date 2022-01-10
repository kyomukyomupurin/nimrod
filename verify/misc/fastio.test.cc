#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../nimrod/misc/fastio.cc"

int main() {
  int T;
  in >> T;
  while (T--) {
    long long A, B;
    in >> A >> B;
    out.println(A + B);
  }
  return 0;
}