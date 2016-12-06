#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define PB push_back
#define OP begin()
#define ED end()
#define cmin(a, b) a = min(a, b)
typedef std::pair<int, int> PII;
const int N = 50010, M = 1000200, POW = 20, INF = 0x3f3f3f3f;

vector<int> g[N];
vector<PII> e;
int cut[N], vis[N], p[N][POW], d[N], f[N], c[M];

class Articulation {
public:
  static const int SIZE = N; // 最大结点个数
  std::vector<PII> keyE;               // keyE为割边集，keyV为割点集
  std::vector<int> keyV, cc[SIZE];      // cc[p]表示结点p在哪些双连通分量中
  int cnt;  // 对于旧版编译器，将上面cc[SIZE]改成vector的形式
  // 传入结点个数n及各结点的出边e[]，返回双连通分量的个数cnt
  int run(int n, const std::vector<int> G[]){
    memset(dfn, use = 0, sizeof(dfn[0]) * n);
    memset(low, cnt = 0, sizeof(low[0]) * n);
    keyE.clear();
    fill_n(cc, n, keyV = std::vector<int>());
    for(int i = 0; i < n; ++i) {
      if(!dfn[i]) dfs(i, 1, G);
    }
    return cnt;
  }
private:
  int dfn[SIZE], low[SIZE], dot[SIZE], use;
  void dfs(int x, int dep, const std::vector<int> G[]){
    int src = 0, out = 1 < dep;
    dot[use++] = x;
    dfn[x] = low[x] = dep;
    for (int i = 0; i < G[x].size(); i++) {
      int y = G[x][i];
      if (!dfn[y]){
        dfs(y, dep + 1, G);
        low[x] = std::min(low[x], low[y]);
        if (low[y] > dfn[x]) keyE.push_back(PII(x, y));
        if (low[y] >= dfn[x]){
          if (++out == 2) keyV.push_back(x);
          while (dot[--use] != y) cc[dot[use]].push_back(cnt);
          cc[x].push_back(cnt);
          cc[y].push_back(cnt++);
        }
      } else if (dfn[y] != dfn[x] - 1 || src++){
        low[x] = std::min(low[x], dfn[y]);
      }
    }
  }
} ;
Articulation sol;

void dfs(int x) {
    vis[x] = true;
    for(int i = 0; i + 1 < POW; i++) p[x][i + 1] = p[p[x][i]][i];
    for(auto &v: g[x]) {
        if(vis[v]) continue;
        p[v][0] = x;
        d[v] = d[x] + 1;
        f[v] += f[x];
        dfs(v);
    }
}

int lca(int a, int b) {
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

int main() {
    // freopen("a.in", "r", stdin);
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0 && m == 0) break;
        for(int i = 0; i < n; i++) g[i] = vector<int>();
        e = vector<PII>(m);
        for(int i = 0; i < m; i++) {
            int u, v; scanf("%d%d", &u, &v); u--; v--;
            g[u].PB(v); g[v].PB(u);
            e[i] = MP(u, v);
        }
        int cnt = sol.run(n, g);
        for(int i = 0; i < max(n, cnt); i++) g[i] = vector<int> ();
        fill(f, f + cnt, 0);
        fill(cut, cut + cnt, 0);
        for(auto &x: sol.keyV) {
//            printf("%d: ", x + 1);
            g[cnt] = vector<int>();
            vector<int> &cur = sol.cc[x];
            sort(cur.OP, cur.ED);
            cur.erase(unique(cur.OP, cur.ED), cur.ED);
            for(auto &v: cur) {
//                printf("%d ", v);
                g[cnt].PB(v);
                g[v].PB(cnt);
            }
//            puts("");
            f[cnt] = 1;
            cut[cnt] = 1;
            cnt++;
        }
        assert(cnt < N);
        for(int i = 0; i < m; i++) {
            c[i] = -1;
            int u = e[i].AA, v = e[i].BB;
            for(auto &x: sol.cc[u]) for(auto &y: sol.cc[v]) {
                if(x == y) c[i] = x;
            }
//            printf("%d %d %d\n", u + 1, v + 1, c[i]);
        }
        fill(vis, vis + cnt, 0);
        for(int i = 0; i < cnt; i++) if(vis[i] == 0) {
            for(int j = 0; j < POW; j++) p[i][j] = i;
            dfs(i);
        }
        int q; scanf("%d", &q);
        while(q--) {
            int a, b; scanf("%d%d", &a, &b); a--; b--;
            a = c[a]; b = c[b];
            int p = lca(a, b);
            printf("%d\n", (d[a] + d[b] - 2 * d[p]) >> 1);
        }
    }
    return 0;
}

