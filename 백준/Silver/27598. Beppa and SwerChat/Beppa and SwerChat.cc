#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int n;
string str;

void solve() {
  int inp;
  vector<int> v, w;
  map<int, int> m;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    v.push_back(inp);
  }
  for (int i = 0; i < n; i++) {
    cin >> inp;
    w.push_back(inp);
  }
  int vi = n - 1, wi = n - 1, cnt = 0;
  while (0 <= vi && 0 <= wi) {
    while (0 <= vi && 0 <= wi && v[vi] != w[wi]) {
      vi--;
      cnt++;
    }
    vi--;
    wi--;
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
  return 0;
}