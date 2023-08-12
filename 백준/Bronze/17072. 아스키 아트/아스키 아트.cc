#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int val, inp;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> val;
      val *= 2126;
      cin >> inp;
      val += inp * 7152;
      cin >> inp;
      val += inp * 722;

      if (val < 510'000) cout << '#';
      else if (val < 1'020'000) cout << 'o';
      else if (val < 1'530'000) cout << '+';
      else if (val < 2'040'000) cout << '-';
      else cout << '.';
    }
    cout << '\n';
  }

  return 0;
}