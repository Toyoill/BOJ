#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, l, r, ans = 0;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> l;
      v.push_back(l);
    }
    sort(v.begin(), v.end());

    l = r = v[0];
    for (int i = 1; i < n; i++) {
      if (i % 2) {
        ans = max(ans, abs(r - v[i]));
        r = v[i];
      } else {
        ans = max(ans, abs(l - v[i]));
        l = v[i];
      }
    }
    cout << ans << '\n';
  }

  return 0;
}