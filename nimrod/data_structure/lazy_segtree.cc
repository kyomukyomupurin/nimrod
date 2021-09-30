#include <vector>

template <class M, class OM, class F, class G, class H>
class lazy_segtree {
 public:
  explicit lazy_segtree(int n, M ie, OM oie, F f, G g, H h) {}

  explicit lazy_segtree(const std::vector<M>& v, M ie, OM oie, F f, G g, H h) {}

  void modify(int l, int r, OM x) {}

  M get(int l, int r) {}
 private:
  inline void propagate(int p) {}

  inline M apply(int p) {}

  inline void calc(int p) {}

  inline void thrust(int p) {}
};