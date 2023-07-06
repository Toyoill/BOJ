#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

int n, cnt[404'040], priority[404'040], t[404'040];
vector<int> graph[404'040];
priority_queue<array<int, 2>> pq;

int dfs(int cur);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int m, nd;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    cin >> m;

    cnt[i] = m;
    while (m--) {
      cin >> nd;
      graph[nd].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!priority[i]) dfs(i);
    if (cnt[i] == 0) pq.push({priority[i], i});
  }

  int ans = 0;
  while (!pq.empty()) {
    nd = pq.top()[1];
    ans = max(pq.top()[0] + cnt[0], ans);
    pq.pop();

    cnt[0]++;
    for (auto next : graph[nd])
      if (--cnt[next] == 0) pq.push({priority[next], next});
  }

  cout << ans;
  return 0;
}

int dfs(int cur) {
  priority[cur] = t[cur];

  for (auto next : graph[cur]) {
    if (priority[next])
      priority[cur] = max(priority[cur], priority[next]);
    else priority[cur] = max(priority[cur], dfs(next));
  }
  return priority[cur];
}