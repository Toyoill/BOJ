#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double inp, prev;
  cin >> prev;

  cout << fixed;
  cout.precision(2);

  while (1) {
    cin >> inp;
    if (inp == 999) break;
    cout << inp - prev << '\n';
    prev = inp;
  }

  return 0;
}

