#include <bits/stdc++.h>
#define cmin(x, y) x = std::min(x, y)

using namespace std;

const int INF = 0xff3f3f;
const int Maxn = 1000000, Maxn1 = 5000;
const int Maxm = 5e6;
const int POW = 13;
struct node {
  int u, v, c, next;
}e[Maxm];
int d[Maxn1];
int a[Maxn1], tot1, last1[Maxn1], to[Maxn1*2], nt[Maxn1*3];
int p[Maxn1][POW], id[Maxn1][POW], tot2;

int tot, last[Maxn];
void adde(int u, int v, int c, int c1=0) {
  assert(tot < Maxm);
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

void dfs(int x) {
    for(int i = 0; i < POW - 1; i++) p[x][i + 1] = p[p[x][i]][i];
    for(int k = last1[x]; k != -1; k = nt[k]) {
        int v = to[k];
        if(v == p[x][0]) continue;
        d[v] = d[x] + 1;
        p[v][0] = x;
        dfs(v);
    }
}

void add1(int u, int v) {
    to[tot1] = v;
    nt[tot1] = last1[u];
    last1[u] = tot1;
    tot1++;
}

int main() {
//    freopen("a.in", "r", stdin);
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        tot1 = tot2 = tot = 0;
        memset(last, -1, sizeof last);
        memset(last1, -1, sizeof last1);
        for(int i = 0; i < n; i++) scanf("%d", a + i + 1);
        for(int i = 0; i < n - 1; i++) {
            int u, v; scanf("%d%d", &u, &v);
            add1(u, v);
            add1(v, u);
        }
        for(int i = 0; i < POW; i++) p[1][i] = 1;
        dfs(1);

        int op = ++tot2, ed = ++tot2;
        // for(int i = 1; i <= n; i++) adde(op, id1[i], a[i]);
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < POW; j++) id[i][j] = ++tot2;
        for(int i = 1; i <= n; i++) {
            adde(op, id[i][0], a[i]);
            for(int j = 0; j < POW - 1; j++) {
                adde(id[i][j], id[i][j + 1], INF);
                adde(id[p[i][j]][j], id[i][j + 1], INF);
            }
        }

        for(int i = 0; i < m; i++) {
            int cur = ++tot2;
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if(d[u] < d[v]) swap(u, v);
            int g = d[u] - d[v];
            for(int i = 0; i < POW; i++) if(g >> i & 1) {
                adde(id[u][i], cur, INF);
                u = p[u][i];
            }
            for(int i = POW - 1; i >= 0; i--) {
                if(p[u][i] != p[v][i]) {
                    adde(id[u][i], cur, INF);
                    adde(id[v][i], cur, INF);
                    u = p[u][i];
                    v = p[v][i];
                }
            }
            adde(id[u][0], cur, INF);
            adde(id[v][0], cur, INF);
//            assert(p[u][0] == p[v][0]);
            u = p[u][0];
            adde(id[u][0], cur, INF);
            adde(cur, ed, w);
//            printf("node: %d\n", p[v][0]);
        }
        assert(tot2 < Maxn);
        printf("%d\n", ISAP(op, ed, tot2 + 1));
    }
    return 0;
}

/**************************************************************
    Problem: 1470
    User: ceva
    Language: C++
    Result: Runtime Error
****************************************************************/
