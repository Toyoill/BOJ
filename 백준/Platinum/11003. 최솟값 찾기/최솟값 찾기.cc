#include <iostream>
#include <deque>
#include <array>
using namespace std;

int n, l;
deque<array<int, 2>> dq;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> l;

  int inp;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    while (!dq.empty() && dq.back()[1] > inp) dq.pop_back();
    dq.push_back({i, inp});

    while (dq.front()[0] < i - l + 1) dq.pop_front();
    cout << dq.front()[1] << ' ';
  }

  return 0;
}