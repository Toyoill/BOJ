#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
using namespace std;

long long n, q;
string str;

void solve() {
  vector<pair<long long, long long>> v;
  cin >> n;
  cin >> str;
  long long plus = 0, minus = 0, f, s;

  for (auto c : str) {
    if (c == '+') plus++;
    else minus++;
  }

  cin >> q;
  while (q--) {
    cin >> f >> s;
    if (plus == minus) {
      cout << "YES\n";
      continue;
    }

    if (f == s) {
      if (plus == minus) cout << "YES\n";
      else cout << "NO\n";
      continue;
    }

    if (f < s) swap(f, s);
    if ((f * plus - s * minus) >= 0 && (f * plus - s * minus) % (f - s) == 0
      && (f * plus - s * minus) / (f - s) <= plus + minus)
      cout << "YES\n";
    else cout << "NO\n";

  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long tc = 1;
//  cin >> tc;
  while (tc--) solve();
  return 0;
}