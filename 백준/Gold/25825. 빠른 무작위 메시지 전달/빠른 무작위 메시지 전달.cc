#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;

#define INF 2'000'000'000

int t[12][12], table[1 << 12][12];

int solve(int state, int student);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  memset(table, -1, sizeof(table));
  for (int i = 0; i < 12; i++)
    for (int j = 0; j < 12; j++)
      cin >> t[i][j];

  int ans = INF;
  for (int i = 0; i < 12; i++)
    ans = min(ans, solve(1 << i, i));
  cout << ans;

  return 0;
}

int solve(int state, int student) {
  if (state == (1 << 12) - 1) return 0;

  int &ret = table[state][student];
  if (ret != -1) return ret;
  ret = INF;

  if (student % 2 == 0 && !(state & (1 << (student + 1))))
    return ret = solve(state | (1 << (student + 1)), student + 1) + t[student][student + 1];
  if (student % 2 == 1 && !(state & (1 << (student - 1))))
    return ret = solve(state | (1 << (student - 1)), student - 1) + t[student][student - 1];

  for (int i = 0; i < 12; i++) {
    if (!(state & (1 << i)))
      ret = min(ret, solve(state | (1 << i), i) + t[student][i]);
  }
  return ret;
}
