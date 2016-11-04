#include <bits/stdc++.h>
#include <bits/stdc++.h>
const int POW = 20;
const int N = 5e5+100;
/*
 * p[i][j]: $i$的第$j$倍祖先
 * d[i]: $i$在树中的深度
 * edge[N]: 边集合
 * dfs(u, fa): 求出$p, d$
 * lca(a, b): 求出$(a, b)$的最近公共祖先
 */
int p[N][POW];
int d[N];
int id[N];
int left[N], right[N];
int w[N<<2];
int belong[N];
int leaf[N];
std::vector<int>edge[N];
int cnt = 0;

void dfs(int u, int fa){
  left[u] = cnt;
  id[u] = cnt;
  cnt++;
  d[u] = d[fa] + 1;
  p[u][0] = fa;
  for(int i = 1; i < POW; i++) p[u][i] = p[p[u][i - 1]][i - 1];
  int sz = edge[u].size();
  leaf[u] = (sz == 0);
  for(int i = 0; i < sz; i++) {
    int v = edge[u][i];
    if(v == fa) continue;
    dfs(v, u);
    leaf[u] += leaf[v];
  }
  right[u] = cnt;
}

int lca(int a, int b) {
  if(!b) return a;
  if(!a) return b;
  if(d[a] > d[b]) std::swap(a, b);
  if(d[a] < d[b]) {
    int del = d[b] - d[a];
    for(int i = 0; i < POW; i++) if(del & (1 << i)) b = p[b][i];
  }
  if(a != b) {
    for(int i = POW - 1; i >= 0; i--)
      if(p[a][i] != p[b][i])
        a = p[a][i], b = p[b][i];
    a = p[a][0], b = p[b][0];
  }
  return a;
}

int cal(int x, int l, int r, int a, int b) {
  if(a <= l && r <= b) {
    return w[x];
  }
  int mid = (l + r) >> 1;;
  if(b <= mid) return cal(x << 1, l, mid, a, b);
  else if(a > mid) return cal(x << 1 ^ 1, mid + 1, r, a, b);
  else return lca(cal(x << 1, l, mid, a, b), cal(x << 1 ^ 1, mid + 1, r, a, b));
}

void add(int x, int l, int r, int p, int c) {
  if(l == r) { w[x] = c; return ; }
  int mid = (l + r) >> 1;
  if(p <= mid) add(x << 1, l, mid, p, c);
  else add(x << 1 ^ 1, mid + 1, r, p, c);
  w[x] = lca(w[x << 1], w[x << 1 ^ 1]);
}

void del(int x, int l, int r, int p) {
  if(l == r) { w[x] = 0; return ; }
  int mid = (l + r) >> 1;
  if(p <= mid) del(x << 1, l, mid, p);
  else del(x << 1 ^ 1, mid + 1, r, p);
  w[x] = lca(w[x << 1], w[x << 1 ^ 1]);
}

void dfs2(int x, int from) {
  belong[x] = from;
  for(auto &v: edge[x]) dfs2(v, from);
}

int main() {
  freopen("gangsters.in", "r", stdin);
  freopen("gangsters.out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 2; i <= n; i++) {
    int v; scanf("%d", &v);
    edge[v].push_back(i);
  }
  for(auto &v: edge[1]) {
    dfs2(v, v);
  }
  dfs(1, 1);
  char op[5];

  int ans0 = 0;
  int tot = 0;
  while(m--) { 
    int x;
    scanf("%s%d", op, &x);
    int rt = belong[x];
    if(op[0] == '+') {
      tot--;
      int pre = cal(1, 0, cnt - 1, left[rt], right[rt] - 1);
      tot -= leaf[pre];
      add(1, 0, cnt - 1, id[x], x);
      int fa = cal(1, 0, cnt - 1, left[rt], right[rt] - 1);
      tot += leaf[fa];
      if(!pre) ans0++;
      printf("%d %d\n", ans0, tot);
    }
    else {
      tot++;
      int pre = cal(1, 0, cnt - 1, left[rt], right[rt] - 1);
      tot -= leaf[pre];
      del(1, 0, cnt - 1, id[x]);
      int fa = cal(1, 0, cnt - 1, left[rt], right[rt] - 1);
      tot += leaf[fa];
      if(pre && !fa) ans0--;
      printf("%d %d\n", ans0, tot);
    }
  }
  fclose(stdin);
  return 0;
}
