#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define PII std::pair<int, int>
#define AA first
#define BB second
#define MP std::make_pair

char s[100][100];
PII ans[100];

int main() {
  int n, m;
  int f[256];
  while(~scanf("%d%d", &m, &n)) {
    for(int i = 0; i < n; i++) scanf("%s", s + i);

    for(int i = 0; i < n; i++) {
      memset(f, 0, sizeof f);
      ans[i].second = i;
      ans[i].first = 0;
      for(int j = m - 1; j >= 0; j--) {
        for(int k = 0; k < s[i][j]; k++)
          ans[i].first += f[k];
        f[s[i][j]]++;
      }
    }
    std::sort(ans, ans + n);
    for(int i = 0; i < n; i++) printf("%s\n", s[ans[i].second]);
  }
  return 0;
}
