#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000000

int failure[MAX_LEN + 1];
char str[MAX_LEN + 1], pattern[MAX_LEN + 1];

void find_failure(char *pattern, int *failure);
int solve(char *str, char *pattern, int *failure, int *ans);

int main() {

  gets(str);
  gets(pattern);

  find_failure(pattern, failure);

  int ans[MAX_LEN + 1], n = 0;
  n = solve(str, pattern, failure, ans);

  printf("%d\n", n);
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }

  return 0;
}

void find_failure(char *pattern, int *failure) {
  int idx = 0, len = strlen(pattern);
  failure[0] = 0;

  for (int i = 1; i < len; i++) {
    while (idx != 0 && pattern[idx] != pattern[i]) idx = failure[idx - 1];
    if (pattern[idx] == pattern[i]) idx++;
    failure[i] = idx;
  }
}

int solve(char *str, char *pattern, int *failure, int *ans) {
  int str_len = strlen(str), pat_len = strlen(pattern), idx = 0, ret = 0;
  for (int i = 0; i < str_len; i++) {
    while (idx != 0 && pattern[idx] != str[i]) idx = failure[idx - 1];
    if (pattern[idx] == str[i]) idx++;

    if (idx == pat_len) {
      ans[ret++] = (i - idx + 1) + 1;
      idx = failure[idx - 1];
    }
  }
  return ret;
}


