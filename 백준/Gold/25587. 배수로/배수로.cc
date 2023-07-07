#include <iostream>
#include <vector>
using namespace std;

int n, m, uf[101'010], num[101'010];
long long rain[101'010];
vector<int> query;

int Find(int f);
void Union(int f, int s);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int inp, cnt = 0;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    uf[i] = i;
    num[i] = 1;
    cin >> rain[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> inp;
    rain[i] -= inp;
    if (rain[i] < 0) cnt++;
  }

  int a, b, c;
  long long sum;
  while (m--) {
    cin >> a;
    if (a == 2) cout << cnt << '\n';
    else {
      cin >> b >> c;
      b = Find(b), c = Find(c);
      if (b == c) continue;

      if (rain[b] < 0) cnt -= num[b];
      if (rain[c] < 0) cnt -= num[c];
      if ((sum = rain[b] + rain[c]) < 0) cnt += (num[b] + num[c]);

      Union(b, c);

      rain[Find(b)] = sum;
    }
  }
  return 0;
}

int Find(int f) {
  if (uf[f] == f) return f;
  return uf[f] = Find(uf[f]);
}
void Union(int f, int s) {
  f = uf[f], s = uf[s];
  if (s < f) {
    num[s] += num[f];
    uf[f] = s;
  } else {
    num[f] += num[s];
    uf[s] = f;
  }
}