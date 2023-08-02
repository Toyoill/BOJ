#include <iostream>
using namespace std;
#define MOD 1'000'000'007
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long ans, n;
  cin >> n;
  ans = --n;
  n -= 2;
  while (n > 0) {
    ans *= n;
    ans %= MOD;
    n -= 2;
  }
  cout << ans % MOD;
  return 0;
}