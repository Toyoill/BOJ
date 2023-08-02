#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

int n, sum[1000][2];
vector<array<int, 3>> v;

int solve(int cur, int type);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int x, y, c;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x >> y >> c;
    v.push_back({x, y, c});
  }

  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, solve(i, 0));
    ans = max(ans, solve(i, 1));
  }
  cout << ans;

  return 0;
}

int solve(int cur, int type) {
  if (cur == n) return 0;

  int &ret = sum[cur][type];
  if (ret > 0) return ret;

  if (type == 0) {
    for (int i = cur + 1; i < n; i++)
      if (v[cur][1] < v[i][1]) ret = max(ret, solve(i, type));
  } else {
    for (int i = cur + 1; i < n; i++)
      if (v[cur][1] > v[i][1]) ret = max(ret, solve(i, type));
  }
  
  return ret = ret + v[cur][2];
}