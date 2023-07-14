#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

int n, k;
deque<int> dq;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  cin >> n >> k;

  for (int i = 1; i <= n; i++) dq.push_back(i);

  int cnt;
  while (1) {
    if (dq.size() <= k) {
      cout << dq.front();
      break;
    }

    dq.push_back(dq.front());
    cnt = k;
    while (cnt--) dq.pop_front();
  }

  return 0;
}