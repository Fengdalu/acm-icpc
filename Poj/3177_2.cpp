#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define PB push_back
typedef std::pair<int, int> PII;
class Articulation {
public:
  static const int SIZE = 100005; // 最大结点个数
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
vector<int> G[100005];
vector<PII> E;
int fa[100005], f[100005];

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            G[u].push_back(v);
            G[v].push_back(u);
            if(u > v) swap(u, v);
            E.PB(MP(u, v));
        }
        for(int i = 0; i < n; i++) {
            sort(G[i].begin(), G[i].end());
            G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
        }
        sol.run(n, G);
        sort(sol.keyE.begin(), sol.keyE.end());
        set<PII> s;
        sol.keyE.erase(unique(sol.keyE.begin(), sol.keyE.end()), sol.keyE.end());
        for(int i = 0; i < sol.keyE.size(); i++) {
            int u = sol.keyE[i].AA, v = sol.keyE[i].BB;
            if(u > v) swap(u, v);
            s.insert(MP(u, v));
        }
        for(int i = 0; i < n; i++) fa[i] = i;
        for(int i = 0; i < E.SZ; i++) {
            PII cur = E[i];
            if(s.find(cur) != s.end()) continue;
//            printf("add: %d %d\n", cur.AA + 1, cur.BB + 1);
            fa[find(cur.AA)] = find(cur.BB);
        }
        vector<PII> &cur = sol.keyE;
        for(int i = 0; i < cur.SZ; i++) {
            int u = cur[i].AA, v = cur[i].BB;
            if(find(u) == find(v)) continue;
            f[find(u)]++; f[find(v)]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) if(f[i] == 1) ans++;
        printf("%d\n", (ans + 1) / 2);
    }
    return 0;
}

