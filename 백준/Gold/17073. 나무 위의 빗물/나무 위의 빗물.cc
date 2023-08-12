#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long n, w, vst[505'050], res[505'050];
vector<int> tree[505'050];
void dfs(int cur, long long mul);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> w;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  vst[1] = 1;
  dfs(1, 1);

  long long cnt = 0;
  double sum = 0;
  for (int i = 1; i <= n; i++) {
    if (res[i]) {
      sum += ((double) w / (double) res[i]);
      cnt++;
    }
  }

  cout << fixed;
  cout.precision(10);
  cout << sum / (double) cnt;
  return 0;
}

void dfs(int cur, long long mul) {
  int flag = 0;
  res[cur] = mul;
  for (auto iter : tree[cur]) {
    if (!vst[iter]) {
      vst[iter] = 1;
      if (cur == 1) dfs(iter, mul * tree[cur].size());
      else dfs(iter, mul * (tree[cur].size() - 1));

      flag = 1;
    }
  }
  if (flag) res[cur] = 0;
}