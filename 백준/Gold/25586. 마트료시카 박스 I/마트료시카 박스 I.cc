#include <iostream>
#include <vector>
using namespace std;

int n, m, k, cnt[1010];
vector<int> boxes[1010], ans[1010];

void solve(int box);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int c, box;

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    while (c--) {
      cin >> box;
      boxes[i].push_back(box);
      cnt[box]++;
    }
  }

  int root;
  for (int i = 1; i <= n; i++)
    if (!cnt[i]) {
      root = i;
      break;
    }

  solve(root);
  cout << 1 << '\n' << 0 << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i].size() << ' ';
    for (auto sub_box : ans[i]) cout << sub_box << ' ';
    cout << '\n';
  }

  return 0;
}

void solve(int box) {
  int idx;
  for (idx = 0; idx < m && idx < boxes[box].size(); idx++)
    ans[box].push_back(boxes[box][idx]);
  for (; idx < boxes[box].size(); idx++) boxes[boxes[box][m - 1]].push_back(boxes[box][idx]);

  for (auto sub_box : ans[box]) solve(sub_box);
}