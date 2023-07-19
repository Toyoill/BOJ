#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, vst[1010], dist[1010];

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  int tc, f, s;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    memset(vst, 0, sizeof(vst));

    int dist[1010];

    for (int i = 1; i <= n; i++) dist[i] = 3000;

    vector<int> v[1010], rev[1010];

    while (m--) {
      cin >> f >> s;
      v[f].push_back(s);
      rev[s].push_back(f);
    }

    int d = 0, cur;
    queue<int> q;
    q.push(1);
    q.push(-1);
    dist[1] = 0;
    vst[1] = 1;

    while (1) {
      if (q.front() == n) break;
      if (q.front() == -1) {
        d++;
        q.pop();
        q.push(-1);
        continue;
      }
      cur = q.front();
      q.pop();

      for (auto next : v[cur]) {
        if (!vst[next]) {
          vst[next] = 1;
          q.push(next);
          dist[next] = d + 1;
        }
      }
    }

    memset(vst, 0, sizeof(vst));
    queue<int> qq;
    qq.push(n);
    vector<int> ans;
    ans.push_back(n);
    vst[n] = 1;

    while (!qq.empty()) {
      cur = qq.front();
      qq.pop();
      for (auto next : rev[cur]) {
        if (dist[next] == dist[cur] - 1 && !vst[next]) {
          ans.push_back(next);
          qq.push(next);
          vst[next] = 1;
        }
      }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';

  }

  return 0;
}
