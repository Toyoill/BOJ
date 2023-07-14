#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int n;
long long psum[1'000'002], k;
vector<long long> v;
map<long long, int> mp;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> psum[i];
    psum[i] += psum[i - 1];
    mp[psum[i] % k]++;
  }

  int ans = 0;
  for (auto iter : mp)
    ans = max(ans, iter.second);
  cout << ans;

  return 0;
}
