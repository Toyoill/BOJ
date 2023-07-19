#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <cstring>
using namespace std;

int n, m, company[1250][55], cnt[1250][55], own[1250];

void InitCompany(int c);
int Find(int c, int f);
void Union(int c, int f, int s);

void solve() {
  memset(company, 0, sizeof(company));
  memset(cnt, 0, sizeof(cnt));
  memset(own, 0, sizeof(own));

  cin >> n >> m;

  int num = 1, from, to, c;
  InitCompany(1);
  
  for (int i = 1; i <= m; i++) {
    cin >> from >> to;
    c = 1;
    while (c <= num) {
      if (Find(c, from) == Find(c, to)) {
        own[i] = c;
        break;
      } else if (cnt[c][Find(c, from)] + cnt[c][Find(c, to)] < n) {
        Union(c, from, to);
        own[i] = c;
        break;
      }

      c++;
    }

    if (num < c) {
      num++;
      InitCompany(c);
      Union(c, from, to);
      own[i] = c;
    }
  }

  cout << num << '\n';
  for (int i = 1; i <= m; i++) {
    cout << own[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}

void InitCompany(int c) {
  for (int i = 1; i <= n; i++) {
    company[c][i] = i;
    cnt[c][i] = 1;
  }
}

int Find(int c, int f) {
  if (f == company[c][f]) return f;
  return company[c][f] = Find(c, company[c][f]);
}

void Union(int c, int f, int s) {
  f = Find(c, f);
  s = Find(c, s);

  if (f > s) swap(f, s);

  if (cnt[c][f] < cnt[c][s]) {
    company[c][f] = s;
    cnt[c][s] += cnt[c][f];
  } else {
    company[c][s] = f;
    cnt[c][f] += cnt[c][s];
  }
}