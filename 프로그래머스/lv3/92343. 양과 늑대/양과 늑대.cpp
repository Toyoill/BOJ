#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int n;
int table[1 << 17][18][18];
vector<int> child[17];

int solve(int state, int sheep, int wolf, vector<int> &info) {
  int &ret = table[state][sheep][wolf];
  if (ret != -1) return ret;

  ret = sheep;

  for (int i = 0; i < n; i++) {
    if (state & (1 << i)) {
      for (auto iter : child[i]) {
        if (!(state & (1 << iter)) && sheep + !info[iter] > wolf + info[iter])
          ret = max(ret, solve(state | (1 << iter), sheep + !info[iter], wolf + info[iter], info));
      }
    }
  }
  return ret;
}

int solution(vector<int> info, vector<vector<int>> edges) {
  memset(table, -1, sizeof(table));

  n = info.size();
  for (auto iter : edges) {
    child[iter[0]].push_back(iter[1]);
  }

  return solve(1, 1, 0, info);
}