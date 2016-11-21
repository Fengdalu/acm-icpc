#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

const int N = 1e6;
int a[N];
int c[10010];
int vis[210];

template <typename T> T sqr(T x) { return x * x; }
int main() {
  int T; scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    memset(c, 0, sizeof c);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++) vis[a[i]] = true;
    for(int i = 0; i < n; i++) c[10000 - sqr((100 - a[i]))]++;
    int mx = -1, w = 0;
    for(int i = 0; i < 10001; i++) mx = std::max(mx, c[i]);
    for(int i = 0; i < 10001; i++) if(c[i] == mx) w++;
    printf("Case #%d:\n", cas);
    int cnt = 0;
    bool flag1 = false;
    for(int i = 0; i < 10001; i++) if(c[i] == mx) {
      cnt++;
    }
    else if(c[i]) flag1 = true;
    if(cnt >= 2 && !flag1) {puts("Bad Mushroom"); continue; }
    bool flag = false;
    for(int i = 0; i < 10001; i++) if(c[i] == mx) {
      if(!flag) printf("%d", i);
      else printf(" %d", i);
      flag = true;
    }
    puts("");
  }
  return 0;
}
