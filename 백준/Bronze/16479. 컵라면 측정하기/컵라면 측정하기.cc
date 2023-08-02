#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int k, d1, d2;
  cin >> k >> d1 >> d2;

  cout << k * k - (d1 - d2) * (d1 - d2);

  return 0;
}