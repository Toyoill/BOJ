#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, ans = 0, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    ans += t + 8;
  }
  ans -= 8;
  cout << ans / 24 << ' ' << ans % 24;
  return 0;
}