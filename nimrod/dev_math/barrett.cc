#include <iostream>

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

class barrett {
 public:
  explicit barrett(u32 m) : m_(m), im_(u64(-1) / m + 1) {}

  u32 mul(u32 a, u32 b) const {
    u64 z = a;
    z *= b;
    u64 x = u64((u128(z) * im_) >> 64);
    u32 v = u32(z - x * m_);
    if (v >= m_) v += m_;
    return v;
  }

 private:
  u32 m_;
  u64 im_;
};

// int main() {
//   u32 mod;
//   std::cin >> mod;
//   barrett br(mod);
//   for (int i = 0; i < 100000000; ++i) {
//     u32 a = i + 100000, b = i + 200000;
//     u32 rem1 = u64(a) * b % mod;
//     u32 rem2 = br.mul(a, b);
//     if (rem1 != rem2) {
//       std::cout << a << " " << b << std::endl;
//       return 0;
//     }
//   }
//   return 0;
// }