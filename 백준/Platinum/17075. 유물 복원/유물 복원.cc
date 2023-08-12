#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
int table[50][50][2550], stone[50][50], val[50][50];
int solve(int r, int c, int sum);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  memset(table, -1, sizeof(table));

  int sum = 0, flag = 0;

  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> stone[i][j];
      val[i][j] = (n - i) * (m - j) % k;
      val[i][j] = val[i][j] * (i + 1) * (j + 1) % k;
      if (stone[i][j] == 1) {
        flag = 1;
        sum = (sum + val[i][j]) % k;
      }
    }

  if (!sum || solve(0, 0, sum)) {
    cout << 1 << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (stone[i][j] == -1) cout << 0 << ' ';
        else cout << stone[i][j] << ' ';
      }
      cout << "\n";
    }
  } else cout << -1;

  return 0;
}

int solve(int r, int c, int sum) {
  if (r == n) return 0;
  if (c == m) return solve(r + 1, 0, sum);
  if (stone[r][c] != -1) return solve(r, c + 1, sum);

  int &ret = table[r][c][sum];
  if (ret != -1) return ret;

  stone[r][c] = 1;
  if ((sum + val[r][c]) % k == 0 || solve(r, c + 1, (sum + val[r][c]) % k)) return 1;
  stone[r][c] = 0;
  if (solve(r, c + 1, sum)) return 1;

  stone[r][c] = -1;
  return ret = 0;
}