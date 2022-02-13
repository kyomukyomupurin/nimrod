#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../nimrod/dev_graph/lca.cc"
#include "../../nimrod/misc/fastio.cc"

int main() {
  int N, Q;
  in >> N >> Q;
  lca_forest<int> lca(N);
  for (int i = 1; i < N; ++i) {
    int p;
    in >> p;
    lca.add(i, p);
  }
  lca.build();
  while (Q--) {
    int u, v;
    in >> u >> v;
    out.println(lca.lca(u, v));
  }
  return 0;
}