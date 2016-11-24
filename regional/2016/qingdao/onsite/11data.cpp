#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

int main() {
  freopen("a.in", "w", stdout);
  int T = 1, n = 200000, m = 20000;
  printf("%d\n", T);
  for(int cas = 1; cas <= T; cas++) {
    printf("%d %d\n", n, m);
    for(int i = 0; i < n; i++) {
      printf("%d %d %d\n", rand() % n + 1, rand() % n + 1, rand() % n + 1);
    }
    for(int i = 0; i < m; i++) {
      printf("%d %d %d\n", rand() % n + 1, rand() % n + 1, rand() % n + 1);
    }
  }
  return 0;
}
