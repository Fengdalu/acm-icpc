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
std::vector<int> up[1<<10];

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


void dfs(int u, int fa, int mk, std::vector<int>&son) {
  int cur = 1 << color[u];
  mk |= cur;
  son.push_back(mk);
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

  std::vector<int> fa;
  dfs(root, root, 0, fa);
  std::vector<int> num(1 << K, 0);
  int full = (1 << K); full--;
  for(auto &mk: fa) num[mk]++;

  for(auto& mk: fa) {
    int cur = full ^ mk;
    for(auto &p: up[cur]) {
      if(p > full) break;
      ans += num[p];
    }
  }
  // printf("ans: %d\n", ans);

  for(int k = last[root]; k != -1; k = next[k]) {
    std::fill(num.begin(), num.end(), 0);
    int v = to[k];
    if(vis[v]) continue;
    std::vector<int> dp;
    dfs(v, root, 1 << color[root], dp);
    for(auto &mk: dp) num[mk]++;
    for(auto &mk: dp) {
      int cur = full ^ mk;
      for(auto &p: up[cur]) {
        if(p > full) break;
        ans -= num[p];
      }
    }
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
  for(int i = 0; i < (1 << 10); i++)
    for(int j = 0; j < (1 << 10); j++)
      if((i & j) == i) up[i].push_back(j);


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
