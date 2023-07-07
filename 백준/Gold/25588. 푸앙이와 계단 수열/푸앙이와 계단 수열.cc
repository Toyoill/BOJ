#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int num[100'000], dp[100'000], cnt[100'000];

int n, k;
int solve(int from);
int chk(int from);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  memset(dp, -1, sizeof(dp));
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> num[i];
  chk(0);
  cout << solve(0);
  return 0;
}

int chk(int from) {
  if (from == n) return 0;

  int &ret = cnt[from];
  ret = 1;

  if (abs(num[from] - num[from + 1]) == 1) ret += chk(from + 1);
  else chk(from + 1);

  return ret;
}

int solve(int from) {
  if (from == n) return 0;
  int &ret = dp[from];
  if (ret != -1) return ret;

  ret = solve(from + 1) + 1;
  ret = min(ret, solve(from + 2) + 1);
  ret = min(ret, solve(from + 3) + 1);
  if (cnt[from] >= k) ret = min(ret, solve(from + k) + 1);
  return ret;
}