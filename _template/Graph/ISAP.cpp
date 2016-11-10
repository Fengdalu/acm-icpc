/*
 * 用于边数较多的情况, 调用$ ISAP(int st, int ed, int n) $, $ n $要稍大
 */

#include <bits/stdc++.h>
const int Maxn = 1000;
const int Maxm = Maxn * Maxn;
struct node {
  int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
void adde(int u, int v, int c, int c1) {
  e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
  e[tot].u = v; e[tot].v = u; e[tot].c = c1; e[tot].next = last[v]; last[v] = tot++;
}

int dist[Maxn], cur[Maxn], gap[Maxn], pre[Maxn];
int ISAP(int s, int t, int n) {
  int i, j, u, v, det;
  int maxflow = 0;
  memset(dist, 0, sizeof(dist[0]) * (n + 3));
  memset(gap, 0, sizeof(gap[0]) * (n + 3));
  for (i = 0; i < n; i ++ )
    cur[i] = last[i];
  u = s;
  gap[0] = n;
  pre[s] = -1;
  while (dist[s] <= n) {
    bool flag = false;
    for (j = cur[u]; j != -1; j = e[j].next) {
      v = e[j].v;
      if (e[j].c > 0 && dist[u] == dist[v] + 1) {
        flag = true;
        pre[v] = u;
        cur[u] = j;
        u = v;
        break;
      }
    }
    if (flag) {
      if (u == t) {
        int det = INF;
        for (i = u; i != s; i = pre[i])
          det = min(det, e[cur[pre[i]]].c);
        for (i = u; i != s; i = pre[i]) {
          e[cur[pre[i]]].c -= det;
          e[cur[pre[i]] ^ 1].c += det;
        }
        maxflow += det;
        u = s;
      }
    }
    else {
      int mind = n;
      for (j = last[u]; j != -1; j = e[j].next ) {
        v = e[j].v;
        if (e[j].c > 0 && dist[v] < mind) {
          mind = dist[v];
          cur[u] = j;
        }
      }
      if (( -- gap[dist[u]]) == 0) break;
      gap[dist[u] = mind + 1] ++ ;
      if (u != s) u = pre[u];
    }
  }
  return maxflow;
}
