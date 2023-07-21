#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int> from, to;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  from = vector<int>(n);
  to = vector<int>(n);
  for (int i = 0; i < n; i++) cin >> from[i];
  for (int i = 0; i < n; i++) cin >> to[i];

  int target, idx;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    target = to[i];

    for (idx = i; from[idx] != target; idx++)
      if (abs(from[idx] - target) == 1) {
        cout << -1;
        return 0;
      }

    while (i < idx) {
      ans.push_back(idx);
      swap(from[idx], from[idx - 1]);
      idx--;
    }
  }
  cout << ans.size() << '\n';
  for (auto iter : ans) cout << iter << ' ';

  return 0;
}