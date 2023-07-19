#include <iostream>
#include <vector>
#include <set>
using namespace std;

int board[50][50];

// bottom(0), left(1), back(2), front(3), right(4), top(5);
vector<int> up(const vector<int> &x) {
  vector<int> res = {x[2], x[1], x[5], x[0], x[4], x[3]};
  return res;
}

vector<int> left(const vector<int> &x) {
  vector<int> res = {x[1], x[5], x[2], x[3], x[0], x[4]};
  return res;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];

  vector<int> init = {board[n - 1][n - 1], -1, -1, -1, -1, -1};
  vector<vector<set<vector<int>>>> v(n, vector<set<vector<int>>>(n));
  v[n - 1][n - 1].insert(init);

  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      for (auto iter : v[i][j]) {
        if (i > 0) {
          vector<int> next = up(iter);
          if (next[0] == -1) next[0] = board[i - 1][j];
          if (next[0] == board[i - 1][j]) v[i - 1][j].insert(next);
        }
        if (j > 0) {
          vector<int> next = left(iter);
          if (next[0] == -1) next[0] = board[i][j - 1];
          if (next[0] == board[i][j - 1]) v[i][j - 1].insert(next);
        }
      }
    }
  }

  if (v[0][0].empty()) cout << "No\n";
  else {
    cout << "Yes\n";
    for (auto iter : *v[0][0].begin()) {
      if (iter == -1) cout << 0 << ' ';
      else cout << iter << ' ';
    }
    cout << '\n';
  }

}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}