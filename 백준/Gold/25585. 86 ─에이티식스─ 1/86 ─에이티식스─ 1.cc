#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, dp[1 << 10][100][100], dist[10][100][100], vst[100][100];
int dir[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
vector<pair<int, int>> pos;

void chk_dist(int r, int c, int idx);
int solve(int state, int r, int c);

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  memset(dp, -1, sizeof(dp));
  int r, c, inp;

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> inp;
      if (inp == 1) pos.emplace_back(i, j);
      else if (inp == 2) r = i, c = j;
    }

  for (int i = 0; i < pos.size(); i++) {
    memset(vst, 0, sizeof(vst));
    vst[pos[i].first][pos[i].second] = 1;
    chk_dist(pos[i].first, pos[i].second, i);
    if ((r + c) % 2 != (pos[i].first + pos[i].second) % 2) {
      cout << "Shorei";
      return 0;
    }
  }

  cout << "Undertaker\n";
  cout << solve(0, r, c);

  return 0;
}

void chk_dist(int r, int c, int idx) {
  int nextR, nextC;
  queue<pair<int, int>> q;
  q.push({r, c});
  q.push({-1, -1});

  int cnt = 0;
  while (q.size() != 1) {
    r = q.front().first, c = q.front().second;
    q.pop();
    if (r == -1) {
      cnt++;
      q.push({-1, -1});
      continue;
    }

    dist[idx][r][c] = cnt;
    for (int i = 0; i < 4; i++) {
      nextR = r + dir[i][0];
      nextC = c + dir[i][1];
      if (0 <= nextR && nextR < n && 0 <= nextC && nextC < n && !vst[nextR][nextC]) {
        vst[nextR][nextC] = 1;
        q.push({nextR, nextC});
      }
    }
  }
}

int solve(int state, int r, int c) {
  if (state + 1 == (1 << pos.size())) {
    return 0;
  }

  int &ret = dp[state][r][c];
  if (ret != -1) return ret;
  ret = 1'000'000'000;

  for (int i = 0; i < pos.size(); i++) {
    if (!(state & (1 << i)))
      ret = min(ret, solve(state | (1 << i), pos[i].first, pos[i].second) + dist[i][r][c]);
  }

  return ret;
}