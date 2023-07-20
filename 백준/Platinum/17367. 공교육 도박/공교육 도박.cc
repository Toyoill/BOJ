#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
double table[10][10][10][1001];

double solve(int f, int s, int t, int remain);
int calc(int f, int s, int t);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;

  cout << fixed;
  cout.precision(10);
  cout << solve(0, 0, 0, n);

  return 0;
}

double solve(int f, int s, int t, int remain) {
  if (remain == 0) return calc(f, s, t);
  double &ret = table[f][s][t][remain];
  if (ret != 0) return ret;

  ret = calc(f, s, t);

  double tmp = 0;
  for (int i = 1; i <= 6; i++)
    tmp += solve(s, t, i, remain - 1) / 6;

  if (ret < tmp) ret = tmp;
  return ret;
}

int calc(int f, int s, int t) {
  if (f == 0) return 0;
  if (f == s && s == t) return 10'000 + f * 1000;
  else if (f == s) {
    return 1'000 + f * 100;
  } else if (s == t) {
    return 1'000 + s * 100;
  } else if (f == t) {
    return 1'000 + t * 100;
  } else {
    f = max(f, s);
    f = max(f, t);
    return f * 100;
  }
}