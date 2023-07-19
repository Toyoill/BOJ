#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, vst[10'101];
vector<int> v[10'101];
priority_queue<pair<int, int>> pq;

int dfs(int cur);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;

  int f, s;

  while (m--) {
    cin >> f >> s;
    v[s].push_back(f);
  }

  for (int i = 1; i <= n; i++) {
    memset(vst, 0, sizeof(vst));
    pq.push({dfs(i), i});
  }

  int M = pq.top().first;
  vector<int> ans;
  while (!pq.empty() && pq.top().first == M) {
    ans.push_back(pq.top().second);
    pq.pop();
  }

  while (!ans.empty()) {
    cout << ans.back() << ' ';
    ans.pop_back();
  }
}

int dfs(int cur) {
  int ret = 1;
  vst[cur] = 1;
  for (auto iter : v[cur]) {
    if (!vst[iter]) ret += dfs(iter);
  }
  return ret;
}