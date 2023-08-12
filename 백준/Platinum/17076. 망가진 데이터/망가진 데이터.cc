#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1'000'000'007

int k, maxVal[200'000], seg[800'000], sortedIdx[200'000];
vector<int> v;
vector<pair<int, int>> sorted;

int update(int l, int r, int cur, int target);
int get(int l, int r, int cur, int from, int to);
int search(int find);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int inp;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> inp;
    v.push_back(inp);
    sorted.emplace_back(inp, -i);
  }

  sort(sorted.begin(), sorted.end());
  for (int i = 0; i < k; i++) sortedIdx[-sorted[i].second] = i;

  maxVal[0] = -1;
  maxVal[1] = v[0];
  for (int i = 2; i < k; i++)
    maxVal[i] = max(maxVal[i - 1], v[i - 1]);

  int n = -1, m = -1;
  for (int i = k - 1; 1 <= i; i--) {
    if (v[i] * 2 <= k - i - 1 && search(v[i] * 2) <= maxVal[i]) {
      if (n < maxVal[i]) {
        n = maxVal[i];
        m = v[i];
      } else if (n == maxVal[i] && m < v[i]) m = v[i];
    }
    update(0, k - 1, 1, sortedIdx[i]);
  }

  if (0 < n) cout << n << ' ' << m;
  else cout << -1;

  return 0;
}

int update(int l, int r, int cur, int target) {
  if (r < target || target < l) return seg[cur];
  if (l == r) return ++seg[cur];

  int mid = (l + r) / 2;
  return seg[cur] = update(l, mid, cur * 2, target)
    + update(mid + 1, r, cur * 2 + 1, target);
}

int get(int l, int r, int cur, int from, int to) {
  if (to < l || r < from) return 0;
  if (from <= l && r <= to) return seg[cur];

  int mid = (l + r) / 2;
  return get(l, mid, cur * 2, from, to)
    + get(mid + 1, r, cur * 2 + 1, from, to);
}

int search(int find) {
  int l, r, mid;
  l = -1, r = k, mid;
  while (l + 1 < r) {
    mid = (l + r) / 2;

    if (find <= get(0, k - 1, 1, 0, mid)) r = mid;
    else l = mid;
  }

  if (find <= get(0, k - 1, 1, 0, r)) return sorted[r].first;
  return INF;
}