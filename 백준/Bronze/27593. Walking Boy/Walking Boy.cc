#include <bits/stdc++.h>
#include <array>
#define ll long long int
#define ld long double
#define pii array<int, 2>
#define pld pair<ld, ld>
#define X first
#define Y second
#define all(v) v.begin(),v.end()
using namespace std;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846264;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int n;

void solve()
{
	int inp, prev ,pos = 0;
	cin >> n;
	cin >> inp;
	pos += inp / 120;
	prev = inp;

	for (int i = 0; i < n - 1; i++) {
		cin >> inp;
		 pos+= (inp- prev)/120;
		prev = inp;
	}
	pos+= (1440 - inp) / 120;

	if (pos > 1) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int tc = 1; 
	cin >> tc;
	while (tc--) solve();
	return 0;
}