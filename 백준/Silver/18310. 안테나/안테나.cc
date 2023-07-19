#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
vector<long long> v;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  v = vector<long long>(n + 1, 0);

  long long sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++) v[i] += v[i - 1];

  sum = v[n] - v[1] - (v[1] - v[0]) * (n - 1);
  ans = v[1];

  for (int i = 2; i <= n; i++) {
    if (v[n] - v[i] - (v[i] - v[i - 1]) * (n - i)
      + (v[i] - v[i - 1]) * (i - 1) - (v[i - 1] - v[0]) < sum) {
      sum = v[n] - v[i] - (v[i] - v[i - 1]) * (n - i)
        + (v[i] - v[i - 1]) * (i - 1) - (v[i - 1] - v[0]);
      ans = v[i] - v[i - 1];
    }

  }

  cout << ans;
  return 0;
}
