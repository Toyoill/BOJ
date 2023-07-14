#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define TOI(c) ((c) - '0')

int n, k;
vector<pair<int, int>> v;

int toNum(string &str);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int from, to, minNum = 1'000'000'007, maxNum = 0;
  string str;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> str;
    from = toNum(str);
    cin >> str;
    to = toNum(str);
    v.emplace_back(from, to);

    minNum = min(minNum, from);
    maxNum = max(maxNum, to);
  }
  sort(v.begin(), v.end());

  int idx = 0, ansCnt = 0, ans = 0;
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = minNum; i <= maxNum; i++) {
    while (v[idx].first == i) {
      pq.push(v[idx++].second);
    }

    if (ansCnt < pq.size()) {
      ansCnt = pq.size();
      ans = i;
    }
    while (!pq.empty() && pq.top() == i) {
      pq.pop();
    }
  }

  cout << 2000 + ans / 13 << '-';
  if (ans % 13 < 10) cout << '0' << ans % 13;
  else cout << ans % 13;

  return 0;
}

int toNum(string &str) {
  int Y, M;
  Y = TOI(str[0]) * 1000 + TOI(str[1]) * 100 + TOI(str[2]) * 10 + TOI(str[3]);
  M = TOI(str[5]) * 10 + TOI(str[6]);

  return (Y - 2000) * 13 + M;
}