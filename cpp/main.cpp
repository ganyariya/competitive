#include <bits/stdc++.h>

#include <atcoder/all>
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

int main() {}
