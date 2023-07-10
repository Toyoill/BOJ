#include <iostream>
#include <cstring>
using namespace std;

#define GET(fr, fc, tr, tc) (p_sum[(tr)][(tc)] - p_sum[(tr)][(fc) - 1] - p_sum[(fr) - 1][(tc)] + p_sum[(fr) - 1][(fc) - 1])

int n;
long long board[404][404], p_sum[404][404];
long long square_cache[404][404], else_cache[404][404];

void get_max_square();
void get_else();

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> board[i][j];

  for (int i = 1; i <= n; i++) {
    p_sum[1][i] = p_sum[1][i - 1] + board[1][i];
    p_sum[i][1] = p_sum[i - 1][1] + board[i][1];
  }

  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= n; j++) {
      p_sum[i][j] = board[i][j] + p_sum[i - 1][j] + p_sum[i][j - 1] - p_sum[i - 1][j - 1];
    }

  get_max_square();
  get_else();

//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      cout << square_cache[i][j] << ' ';
//    }
//    cout << '\n';
//  }
//  cout << '\n';
//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      cout << else_cache[i][j] << ' ';
//    }
//    cout << '\n';
//  }

  long long ans = 0, tmp;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i == n && j == n) continue;

      tmp = square_cache[i][j] + max(else_cache[i + 1][1], else_cache[1][j + 1]);
      ans = max(ans, tmp);
    }

  cout << ans << '\n';

  return 0;
}

void get_max_square() {
  square_cache[1][1] = board[1][1] - 1;
  for (int i = 2; i <= n; i++) {
    square_cache[1][i] = max(square_cache[1][i - 1], board[1][i] - 1);
    square_cache[i][1] = max(square_cache[i - 1][1], board[i][1] - 1);
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      square_cache[i][j] = max(square_cache[i - 1][j], square_cache[i][j - 1]);
      for (long long k = 1; i - (k - 1) >= 1 && j - (k - 1) >= 1; k++)
        square_cache[i][j] = max(square_cache[i][j], GET(i - (k - 1), j - (k - 1), i, j) - k * k * k * k);
    }
  }
}

void get_else() {
  else_cache[n][n] = board[n][n] - 1;
  for (int i = n - 1; i >= 1; i--) {
    else_cache[n][i] = max(else_cache[n][i + 1], board[n][i] - 1);
    else_cache[i][n] = max(else_cache[i + 1][n], board[i][n] - 1);
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = n - 1; j >= 1; j--) {
      else_cache[i][j] = max(else_cache[i + 1][j], else_cache[i][j + 1]);
      for (long long k = 1; i + (k - 1) <= n && j + (k - 1) <= n; k++)
        else_cache[i][j] = max(else_cache[i][j], GET(i, j, i + (k - 1), j + (k - 1)) - k * k * k * k);
    }
  }
}