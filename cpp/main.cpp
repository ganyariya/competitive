#pragma GCC optimize("O2")
#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;

//------------------------------------------
//------------------------------------------

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)

//------------------------------------------
//------------------------------------------

template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  rep(i, v.size()) in >> v[i];
  return in;
}
template <typename T1, typename T2>
bool chmin(T1 &x, T2 y) {
  if (x > y) {
    x = y;
    return true;
  } else {
    return false;
  }
}
template <typename T1, typename T2>
bool chmax(T1 &x, T2 y) {
  if (x < y) {
    x = y;
    return true;
  } else {
    return false;
  }
}
template <typename T1, typename T2>
T1 ce(T1 x, T2 y) {
  return (x + y - 1) / y;
}

//------------------------------------------
//------------------------------------------

template <int_fast64_t Modulas = 1000000007ul>
class ModInt {
  using u64 = int_fast64_t;

 public:
  u64 x;

  constexpr ModInt() : x(0) {}
  constexpr ModInt(int_fast64_t v) : x((v % Modulas + Modulas) % Modulas) {}
  constexpr ModInt operator+(const ModInt rhs) const noexcept {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt rhs) const noexcept {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt rhs) const noexcept {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt rhs) const noexcept {
    return ModInt(*this) /= rhs;
  }
  constexpr ModInt operator/(const long long rhs) const noexcept {
    return ModInt(*this) /= rhs;
  }
  constexpr ModInt operator+=(const ModInt rhs) noexcept {
    x += rhs.x;
    if (x >= Modulas) x -= Modulas;
    return *this;
  }
  constexpr ModInt operator+=(const long long rhs) noexcept {
    auto hs = ModInt<Modulas>(rhs);
    (*this) += hs;
    return *this;
  }
  constexpr ModInt operator-=(const ModInt rhs) noexcept {
    if (x < rhs.x) x += Modulas;
    x -= rhs.x;
    return *this;
  }
  constexpr ModInt operator-=(const long long rhs) noexcept {
    auto hs = ModInt<Modulas>(rhs);
    (*this) -= hs;
    return *this;
  }
  constexpr ModInt operator*=(const ModInt rhs) noexcept {
    x = x * rhs.x % Modulas;
    return *this;
  }
  constexpr ModInt operator*=(const long long rhs) noexcept {
    auto hs = ModInt<Modulas>(rhs);
    (*this) *= hs;
    return *this;
  }
  constexpr ModInt &operator/=(ModInt rhs) noexcept {
    u64 exp = Modulas - 2;
    while (exp > 0) {
      if (exp & 1ul) *this *= rhs;
      rhs *= rhs;
      exp >>= 1ul;
    }
    return *this;
  }
  constexpr ModInt &operator/=(long long rhs) noexcept {
    auto hs = ModInt<Modulas>(rhs);
    (*this) /= hs;
    return *this;
  }

  constexpr ModInt &operator++() noexcept {
    x++;
    if (x >= Modulas) x -= Modulas;
    return *this;
  }
  constexpr ModInt &operator--() noexcept {
    if (x == 0) x += Modulas;
    x--;
    return *this;
  }
  constexpr bool operator<(const ModInt rhs) const noexcept {
    return x < rhs.x;
  }
  constexpr bool operator==(const ModInt rhs) const noexcept {
    return this->x == rhs.x;
  }
  constexpr bool operator!=(const ModInt rhs) const noexcept {
    return !(*this == rhs);
  }
  friend istream &operator>>(istream &in, ModInt &m) {
    in >> m.x;
    if (m.x < 0) m.x += Modulas;
    m.x %= Modulas;
    return in;
  }
  friend ostream &operator<<(ostream &out, const ModInt &p) {
    out << p.x;
    return out;
  }
  constexpr ModInt pow(u64 p) const {
    ModInt ret(1);
    ModInt mul(x);
    while (p > 0) {
      if (p & 1ul) ret *= mul;
      mul *= mul;
      p >>= 1ul;
    }
    return ret;
  }
  constexpr ModInt operator~() const noexcept {
    u64 exp = Modulas - 2;
    return pow(exp);
  }

  constexpr static ModInt arith_sum(ModInt<Modulas> a, ModInt<Modulas> d,
                                    ModInt<Modulas> n) noexcept {
    return (a * ModInt<Modulas>(2) + (n - 1) * d) * n / ModInt<Modulas>(2);
  }
};

int main() {}
