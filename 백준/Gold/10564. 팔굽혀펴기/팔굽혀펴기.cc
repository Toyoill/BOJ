#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

int n, m, table[5050][5050], vst[5050][5050];
vector<int> v;

int solve(int score, int sum);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    memset(table, -1, sizeof(table));
    memset(vst, 0, sizeof(vst));

    cin >> n >> m;
    v = vector<int>(m);

    for (int i = 0; i < m; i++) cin >> v[i];
    sort(ALL(v));
    cout << solve(0, 0) << '\n';
  }
  return 0;
}

int solve(int score, int sum) {
  if (sum == n) return score;
  int &ret = table[score][sum];
  if (vst[score][sum]) return ret;
  vst[score][sum] = 1;

  for (int i = 0; i < m; i++) {
    if (sum + score + v[i] <= n) {
      ret = max(ret, solve(score + v[i], sum + score + v[i]));
    } else break;
  }
  return ret;
}