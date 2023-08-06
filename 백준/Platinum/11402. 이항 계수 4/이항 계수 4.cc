#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1'000'000'007
#define ll long long

ll n, k, m, fac[2'020][2'020];

ll get_fac(ll a, ll b);
ll lucas(ll a, ll b);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  memset(fac, -1, sizeof(fac));
  cin >> n >> k >> m;
  cout << lucas(n, k);

  return 0;
}

ll get_fac(ll a, ll b) {
  if (a == b) return 1;
  if (b == 0) return 1;
  if (fac[a][b] != -1) return fac[a][b];
  return fac[a][b] = (get_fac(a - 1, b - 1) + get_fac(a - 1, b)) % m;
}

ll lucas(ll a, ll b) {
  if (a <= 2000) return get_fac(a, b);

  ll ret = 1;
  while (a) {
    ret *= lucas(a % m, b % m);
    ret %= m;
    a /= m, b /= m;
  }
  return ret % m;
}