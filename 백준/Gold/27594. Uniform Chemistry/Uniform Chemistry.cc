#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
double prob[101][101];

void solve() {
  cout << fixed;
  cout.precision(10);

  cin >> n >> m;
  v = vector<int>(m);
  for (int i = 0; i < m; i++) cin >> v[i];

  double sum = 0;
  prob[n][0] = 1;
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= n - i; j++) {
      sum = 0;
      for (int k = i + 1; k <= n; k++) sum += prob[k][j - 1];
      prob[i][j] = (double) sum / ((double) n - (double) i);
    }
  }

  double tmp, ans;
  for (int i = 0; i < m; i++) {
    ans = 0;
    for (int j = 1; j <= n - v[i]; j++) {
      tmp = 1;
      for (int k = 0; k < m; k++) {
        if (k == i) continue;
        sum = 0;
        for (int t = 1; t < j; t++) sum += prob[v[k]][t];
        tmp *= (1 - sum);
      }
      ans += tmp * prob[v[i]][j];
    }
    cout << ans << ' ';
  }

}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int tc = 1;
  //cin >> tc;
  while (tc--) solve();
  return 0;
}