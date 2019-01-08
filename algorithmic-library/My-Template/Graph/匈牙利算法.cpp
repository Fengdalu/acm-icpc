/*
 * $kuangbin$模板 ,
 * 边方向为$u$到$v$ ,
 * $uN$为$u$类节点个数 ,
 * $vN$为$v$类节点个数
 */
#include <bits/stdc++.h>
const int MAXN=1000;
int uN, vN;
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u) {
  int v;
  for(v = 0; v < vN; v++)
    if(g[u][v] && !used[v]) {
      used[v] = true;
      if(linker[v] == -1 || dfs(linker[v])) {
        linker[v] = u;
        return true;
      }
    }
  return false;
}

int hungary() {
  int res = 0;
  int u;
  memset(linker, -1, sizeof(linker));
  for(u = 0; u < uN; u++)
  {
    memset(used, 0, sizeof(used));
    if(dfs(u)) res++;
  }
  return res;
}

