#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
void solve() {
    int t[4], b, maxl = 0, need = 0, cnt = 0;
    for (int i = 0; i < 4; i++) {
        cin >> t[i];
        maxl = max(t[i], maxl);
    }
    cin >> b;
    for (int i = 0; i < 4; i++) {
        if (maxl - t[i]) cnt++;
        need += (maxl - t[i]);
    }
 
    if (cnt == 0) cout << 1;
    else if (cnt == 1 && b == need) cout << 1;
    else cout << 0;
   
}
 
int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}