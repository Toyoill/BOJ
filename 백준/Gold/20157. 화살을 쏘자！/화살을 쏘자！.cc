#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

vector<pair<int, int>> balloons;

int main() {
  int n, x, y, g;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x && y) {
      g = gcd(x, y);
      balloons.emplace_back(x / g, y / g);
    } else {
      if (x)
        balloons.emplace_back(x / abs(x), 0);
      else balloons.emplace_back(0, y / abs(y));
    }
  }

  sort(ALL(balloons));

  int cnt = 1, ans = 0;
  x = balloons[0].first, y = balloons[0].second;
  for (int i = 1; i < n; i++) {
    if (balloons[i].first == x && balloons[i].second == y) cnt++;
    else {
      ans = max(cnt, ans);
      cnt = 1;
      x = balloons[i].first, y = balloons[i].second;
    }
  }
  ans = max(cnt, ans);
  cout << ans;

  return 0;
}

