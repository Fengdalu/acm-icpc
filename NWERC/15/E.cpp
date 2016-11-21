#include <bits/stdc++.h>

typedef long long LL;
const int N = 3000;
int a[N], b[N];
LL c[N*5];
int n;
std::vector<int> g[N];
int link[N*5];
LL op[N*5];
bool vis[N*5];

bool dfs(int u) {
  for(auto &v : g[u]) if(!vis[v]) {
    vis[v] = true;
    if(link[v] == -1 || dfs(link[v])) {
      link[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  while(~scanf("%d", &n)) {
    for(int i = 0; i < n; i++) scanf("%d%d", a + i, b + i);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      c[cnt++] = a[i] + b[i];
      c[cnt++] = 1ll * a[i] * b[i];
      c[cnt++] = a[i] - b[i];
    }
    std::sort(c, c + cnt);
    cnt = std::unique(c, c + cnt) - c;
    for(int i = 0; i < n; i++) {
      g[i].erase(g[i].begin(), g[i].end());
      LL x[] = {a[i] + b[i], 1ll * a[i] * b[i], a[i] - b[i]};
      for(int j = 0; j < 3; j++) {
        int pos = std::lower_bound(c, c + cnt, x[j]) - c;
        g[i].push_back(pos);
      }
    }
    memset(link, -1, sizeof link);
    int ans = 0;
    for(int i = 0; i < n; i++) {
      memset(vis, 0, sizeof vis);
      if(dfs(i)) ans++;
    }
    if(ans == n) {
      for(int i = 0; i < cnt; i++) {
        op[link[i]] = c[i];
      }
      for(int i = 0; i < n; i++) {
        if(1ll * a[i] * b[i] == op[i]) printf("%d * %d = %lld\n", a[i], b[i], op[i]);
        else if(a[i] - b[i] == op[i]) printf("%d - %d = %lld\n", a[i], b[i], op[i]);
        else if(a[i] + b[i] == op[i]) printf("%d + %d = %lld\n", a[i], b[i], op[i]);
      }
    }
    else puts("impossible");
  }
  return 0;
}
