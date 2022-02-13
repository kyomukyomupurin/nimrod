#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_C"
#include "../../nimrod/dev_graph/scc.cc"
#include "../../nimrod/misc/fastio.cc"

int main() {
  int N, M;
  in >> N >> M;
  scc_digraph<int> scc(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    in >> a >> b;
    scc.add(a, b);
  }
  scc.build();
  out.println(int(scc.components().size()));
  for (auto&& v : scc.components()) {
    out << int(v.size());
    for (auto&& e : v) {
      out << ' ' << e;
    }
    out << '\n';
  }
  return 0;
}