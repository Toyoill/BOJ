#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;

  cout << fixed;
  cout.precision(2);

  if (n == 0) cout << "divide by zero";
  else cout << 1.0;

  return 0;
}

