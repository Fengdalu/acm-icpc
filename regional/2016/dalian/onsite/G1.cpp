/*
 * 树分治
 * Kyb , 待验证
 */

#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

const int N = 200000 + 5;
int last[N];
int to[2*N], next[2*N];
bool vis[N];
int parent[N];
int sz[N];
int que[N];
int balance[N];
int color[N];
int n, K;
long long ans;
int cnt;
typedef long long ll;

void add(int a, int b) {
  to[cnt] = b;
  next[cnt] = last[a];
  last[a] = cnt++;
}

int bfs(int source,int fa = -1) {
  int qf = 0,qe = 0;
  que[qe++] = source;
  parent[source] = fa;
  while (qf != qe) {
    int u = que[qf++];
    sz[u] = 1;
    balance[u] = 0;
    for(int k = last[u]; k != -1; k = next[k]) {
      int v = to[k];
      if (!vis[v] && parent[u] != v) {
        parent[v] = u;
        que[qe++] = v;
      }
    }
  }
  for (int i = qe - 1; i > 0; -- i) {
    int u = que[i];
    sz[parent[u]] += sz[u];
    balance[parent[u]] = std::max(balance[parent[u]],sz[u]);
  }
  return qe;
}

void dfs(int u, int fa, int mk, std::vector<ll>&son) {
  int cur = 1 << color[u];
  mk |= cur;
  son[mk]++;
  for(int k = last[u]; k != -1; k = next[k]) {
    int v = to[k];
    if(v == fa || vis[v]) continue;
    dfs(v, u, mk, son);
  }
}

void divide(int root) {
  int tot = bfs(root);
  for (int i = tot - 1; i > 0; -- i) {
    int u = que[i];
    balance[u] = std::max(balance[u], tot - sz[u]);
    if (balance[u] < balance[root]) {
      root = u;
    }
  }
  bfs(root);

  std::vector<long long> dp(1 << K, 0);
  dp[0] = 1;
  int full = 1 << K; full--;
  int now = 1 << color[root];
  if(now == full) ans++;
  for(int k = last[root]; k != -1; k = next[k]) {
    int v = to[k];
    if(vis[v]) continue;
    std::vector<long long> son(1 << K, 0);
    dfs(v, root, 0, son);
    for(int mk = 1; mk <= full; mk++) {
      int T = mk | now;
      ans = (ans + 2ll * son[mk] * dp[full ^ T]);
    }
    for(int i = 0; i < K; i++) {
      for(int mk = full; mk >= 0; mk--)
        if(mk >> i & 1) {
          son[mk ^ (1 << i)] += son[mk];
        }
    }
    for(int mk = 0; mk <= full; mk++)
      dp[mk] += son[mk];
  }

  vis[root] = true;
  for(int k = last[root]; k != -1; k = next[k]) {
    int u = to[k];
    if (!vis[u]) {
      divide(u);
    }
  }

}

int main() {
  while(~scanf("%d%d", &n, &K)) {
    for(int i = 0; i < n; i++) scanf("%d", color + i);
    for(int i = 0; i < n; i++) color[i]--;
    for(int i = 0; i < n; i++) vis[i] = 0;
    for(int i = 0; i < n; i++) last[i] = -1;

    cnt = 0;
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--; v--;
      add(u, v); add(v, u);
    }
    ans = 0;
    divide(0);
    printf("%lld\n", ans);
  }
  return 0;
}
