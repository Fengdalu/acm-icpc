#include <bits/stdc++.h>

typedef long long ll;
const int N = 5e5+100;
const int POW = 20;
struct node {int v, w;};
ll f[N][POW];
ll fa[N][POW];
int X[N];
int d[N];
int add[N];
int ans[N];
std::vector<node> g[N];

void dfs(int u, int pre) {
  for(int i = 0; i < POW - 1; i++)
    fa[u][i + 1] = fa[fa[u][i]][i];
  for(int i = 0; i < POW - 1; i++)
    f[u][i + 1] = f[fa[u][i]][i] + f[u][i];


  for(auto &next: g[u]) {
    int v = next.v;
    if(v == pre) continue;
    f[v][0] = next.w;
    fa[v][0] = u;
    d[v] = d[u] + 1;
    dfs(v, u);
  }
}

ll cal(int u, int l) {
  for(int i = POW - 1; i >= 0; i--) {
    if((1 << i) <= l) {
      return f[u][i] + cal(fa[u][i], l - (1 << i));
    }
  }
  return 0;
}

int get(int u, int l) {
  for(int i = POW - 1; i >= 0; i--) {
    if((1 << i) <= l)
      return get(fa[u][i], l - (1 << i));
  }
  return u;
}

int dfs1(int u, int fa) {
  int p = 0;
  for(auto &next: g[u]) {
    int v = next.v;
    if(v == fa) continue;
    p += dfs1(v, u);
  }
  ans[u] = p;
  return p + add[u];
}

int main() {
    freopen("car.in", "r", stdin);
  int T;  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", X + i);
    for(int i = 0; i < n; i++) std::vector<node>().swap(g[i]);
    for(int i = 0; i < n - 1; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      a--; b--;
      g[a].push_back(node{b, c});
      g[b].push_back(node{a, c});
    }
    for(int i = 0; i < n; i++) memset(f[i], 0, sizeof f[i]);
    d[0] = 0;
    dfs(0, 0);
    for(int i = 0; i < n; i++) add[i] = 0;
    for(int i = 0; i < n; i++) {
      int l = 0, r = d[i];
      while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(cal(i, mid) <= X[i]) l = mid;
        else r = mid - 1;
      }
      add[i]++;
      add[get(i, l)]--;
    }
    dfs1(0, 0);
    for(int i = 0; i < n; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
