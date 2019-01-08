#include <bits/stdc++.h>
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

class Articulation {
public:
  static const int SIZE = N; // 最大结点个数
  // keyE 为割边集 , keyV 为割点集
  std::vector<PII> keyE;
  // cc[p] 表示结点p在哪些双连通分量中
  std::vector<int> keyV, cc[SIZE];
  int cnt;
  // 对于旧版编译器 , 将上面 cc[SIZE] 改成 vector 的形式
  // 传入结点个数 n 及各结点的出边 e[] , 返回双连通分量的个数 cnt
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
