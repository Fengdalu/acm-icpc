#include <bits/stdc++.h>
using namespace std;
#define cmax(x, y) x = max(x, y)
const int N = 100010;
const int M = 2e6;
/*
 * dfn: 标号数组
 * low: 回向边数组
 */
int ind[N], c[N], to[M], nt[M], dfn[N], low[N], color[N], u[M], v[M], deg[N];
bool vis[N];
int cnt, num, idn, ncnt, n, m, f[N];
stack<int>s;

void add(int i, int j) {
  cnt++;
  to[cnt] = j;
  nt[cnt] = ind[i];
  ind[i] = cnt;
}

void tarjan(int x) {
  if(dfn[x] != 0) return;
  low[x] = dfn[x] = ++num;
  vis[x] = true;
  s.push(x);
  for(int k = ind[x]; k != -1; k = nt[k]) {
    tarjan(to[k]);
    if(vis[to[k]]) low[x] = min(low[x], low[to[k]]);
  }
  if(dfn[x] == low[x]) {
    ncnt++;
    while(true) {
      int p = s.top();
      s.pop();
      color[p] = ncnt;
      vis[p] = false;
      if(p == x) break;
    }
  }
}

int main() {
    cnt = 0;
    memset(ind, -1, sizeof ind);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", u + i, v + i);
        add(u[i], v[i]);
    }
    for(int i = 1; i <= n; i++) tarjan(i);
    memset(ind, -1, sizeof ind);
    cnt = 0;
    for(int i = 0; i < m; i++) {
        int x = color[u[i]], y = color[v[i]];
        if(x == y) continue;
        add(x, y);
        deg[y]++;
    }
    for(int i = 1; i <= n; i++) c[color[i]]++;
    queue<int> q;
    int ans = -1;
    for(int i = 1; i <= ncnt; i++) if(deg[i] == 0) q.push(i);
    while(q.size()) {
        int cur = q.front(); q.pop();
        int w = f[cur] + c[cur];
        cmax(ans, w);
        for(int k = ind[cur]; k != -1; k = nt[k]) {
            int v = to[k];
            cmax(f[v], w);
            deg[v]--;
            if(deg[v] == 0) q.push(v);
        }
    }
    printf("%d\n", ans);
    return 0;
}
