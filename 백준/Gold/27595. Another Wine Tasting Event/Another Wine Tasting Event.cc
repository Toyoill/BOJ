#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string str;

void solve() {
  cin >> n >> str;

  int cnt = 0, idx, ans = 0;
  for (idx = 0; idx < n; idx++) if (str[idx] == 'W') cnt++;

  ans = max(ans, cnt);
  while (idx < 2 * n - 1) {
    if (str[idx] == 'W') cnt++;
    if (str[idx - n] == 'W') cnt--;
    ans = max(ans, cnt);
    idx++;
  }
  cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
  return 0;
}