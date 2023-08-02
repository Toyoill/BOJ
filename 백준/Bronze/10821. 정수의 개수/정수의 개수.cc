#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  string str;
  cin >> str;

  int ans = 1;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == ',') ans++;
  }
  cout << ans;
  return 0;
}