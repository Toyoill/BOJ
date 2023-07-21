#include <iostream>
#include <string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  string from, to;
  cin >> from >> to;

  int fromH, fromM, toH, toM;
  fromH = (from[0] - '0') * 10 + (from[1] - '0');
  fromM = (from[3] - '0') * 10 + (from[4] - '0');
  toH = (to[0] - '0') * 10 + (to[1] - '0');
  toM = (to[3] - '0') * 10 + (to[4] - '0');

  int ans = 0;
  if (toM < fromM) {
    toM += 60;
    fromH += 1;
  }

  if (toH < fromH) toH += 24;

  ans += toM - fromM;
  ans += toH - fromH;

  cout << ans;

  return 0;
}