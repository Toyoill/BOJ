#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LL long long
#define PLL pair<LL, LL>

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  LL n, m, from, to;
  vector<PLL > v;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> from >> to;
    if (from > to) v.emplace_back(to, from);
  }

  if (v.empty()) {
    cout << m;
    return 0;
  }

  sort(v.begin(), v.end());

  from = v[0].first, to = v[0].second;
  LL ans = m;
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first <= to) to = max(to, v[i].second);
    else {
      ans += (to - from) * 2;
      from = v[i].first, to = v[i].second;
    }
  }
  ans += (to - from) * 2;
  cout << ans;

  return 0;
}