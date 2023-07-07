#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, t[4] = {4, 6, 4, 10};
map<string, int> m;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string str;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 7; k++) {
        cin >> str;
        if (str != "-") m[str] += t[j];
      }
    }
  }

  int maxTime = -1, minTime = -1;
  for (auto iter : m) {
    if (maxTime == -1) maxTime = minTime = iter.second;
    else {
      if (maxTime < iter.second) maxTime = iter.second;
      if (iter.second < minTime) minTime = iter.second;
    }
  }

  if (maxTime - minTime <= 12) cout << "Yes";
  else cout << "No";
  return 0;
}