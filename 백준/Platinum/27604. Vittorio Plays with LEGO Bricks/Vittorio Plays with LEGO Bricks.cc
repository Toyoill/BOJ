
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <array>
#define ll long long int
#define ld long double
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define X first
#define Y second
#define all(v) v.begin(),v.end()
using namespace std;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846264;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int n, h;
int table[300][300];
vector<int> blocks;

int dp(int l, int r);

void solve() {
  memset(table, -1, sizeof(table));

  cin >> n >> h;
  blocks = vector<int>(n);

  for (int i = 0; i < n; i++) cin >> blocks[i];

  cout << dp(0, n - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  //cin >> tc;
  while (tc--) solve();
  return 0;
}

int dp(int l, int r) {
  if (l == r) return h;
  if (l + 1 == r) {
    if ((blocks[r] - blocks[l] + 1) / 2 > h) return 2 * h;
    return ((blocks[r] - blocks[l] + 1) / 2 - 1) + h;
  }

  int &ret = table[l][r];
  if (ret != -1) return ret;
  ret = 1'000'000'000;

  int d = blocks[r] - blocks[l];

  if ((d + 1) / 2 > h) {
    for (int i = l; i < r; i++)
      ret = min(ret, dp(l, i) + dp(i + 1, r));
  } else {
    for (int i = l; i < r; i++)
      ret = min(ret, dp(l, i) + dp(i + 1, r) - 2 * h);
    ret += ((d + 1) / 2 - 1) + h;
  }

  return ret;
}