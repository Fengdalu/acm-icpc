#include <bits/stdc++.h>

using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define SZ size()
#define PII pair<int, int>
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
typedef long long LL;

const LL inf = 0x3f3f3f3f3f;
const int N = 1e5+10, M = 3e5*3;
int vis[N], vis1[N], last[N], nt[M], to[M], c[M], cnt;
LL dis[N];

void add(int a, int b, int _c) {
  to[cnt] = b;
  c[cnt] = _c;
  nt[cnt] = last[a];
  last[a] = cnt++;
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  fill(last, last + n + 1, -1);
  cnt = 0;
  for(int i = 0; i < m; i++) {
    int u, v, c; scanf("%d%d%d", &u, &v, &c);
    add(u, v, c); add(v, u, c);
  }
  fill(dis, dis + n + 1, inf);
  dis[1] = 0;
  for(int i = 0; i < k; i++) {
    int s, y; scanf("%d%d", &s, &y);
    cmin(dis[s], 1LL * y); vis[s] = true;
  }
  priority_queue< pair<LL, int> > Q;
  for(int i = 1; i <= n; i++) Q.push(MP(-dis[i], i));
  int ans = 0;
  while(Q.SZ) {
    int x = Q.top().second; Q.pop();
    if(vis1[x]) continue;
    if(vis[x]) ans++;
    vis1[x] = true;
    for(int k = last[x]; k != -1; k = nt[k]) {
      int v = to[k];
      if(dis[x] + c[k] <= dis[v]) {
        dis[v] = dis[x] + c[k];
        vis[v] = false;
        Q.push(MP(-dis[v], v));
      }
    }
  }
  printf("%d\n", k - ans);
  return 0;
}
