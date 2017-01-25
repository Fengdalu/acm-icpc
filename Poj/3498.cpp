#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

const int Maxn = 1000;
const int Maxm = Maxn * Maxn;
const int N = 105;
const int INF = 1e9+7;
int n, ni[N], mi[N];
double x[N], y[N], d;
struct node {
  int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];

double SQ(int x) { return x * x; }
double dis(double x, double y, double a, double b) {
    return sqrt(SQ(x - a) + SQ(y - b));
}

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
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        scanf("%d%lf", &n, &d);
        for(int i = 0; i < n; i++)
            scanf("%lf%lf%d%d", x + i, y + i, ni + i, mi + i);
        vector<int> ans;
        for(int ed = 0; ed < n; ed++) {
            int op = 2 * n, sum = 0;
            tot = 0;
            for(int i = 0; i < 2 * n + 1; i++) last[i] = -1;
            for(int i = 0; i < n; i++) {
                adde(i, i + n, mi[i], 0);
                adde(op, i, ni[i], 0);
                sum += ni[i];
            }
            for(int i = 0; i < n; i++)
                for(int j = i + 1; j < n; j++) {
                    if(dis(x[i], y[i], x[j], y[j]) <= d) {
                        adde(i + n, j, INF, 0);
                        adde(j + n, i, INF, 0);
                    }
                }
            if(ISAP(op, ed, 2 * n + 1) == sum) ans.push_back(ed);
        }
        if(ans.size() == 0) puts("-1");
        else {
            int sz = ans.size();
            for(int i = 0; i < sz; i++) {
                if(i == 0) printf("%d", ans[i]);
                else printf(" %d", ans[i]);
            }
            puts("");
        }
    }
    return 0;
}
