#include <bits/stdc++.h>

using namespace std;
#define MP std::make_pair
#define PII pair<int, int>
const int N = 1e5+100, M = 3e5*3;
typedef long long LL;
const LL INF = 1e15;
int last[N];
int nt[M], c[M], to[M];
LL dis[N];
int vis[N], cnt, vis1[N];

void add(int u, int v, int w) {
  c[cnt] = w;
  to[cnt] = v;
  nt[cnt] = last[u];
  last[u] = cnt;
  cnt++;
}

int main() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  fill(last, last + n + 1, -1);
  for(int i = 0; i < m; i++) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    u--; v--;
    add(u, v, w);
    add(v, u, w);
  }
  fill(dis, dis + n + 1, INF);
  dis[0] = 0;
  for(int i = 0; i < k; i++) {
    int s, w; scanf("%d%d", &s, &w); s--;
    dis[s] = min(dis[s], 1LL * w);
    vis1[s] = true;
  }
  priority_queue<pair<pair<LL, int>, int> > Q;
  int ans = 0;
  for(int i = 0; i < n; i++) Q.push(MP(MP(-dis[i], vis1[i]), i));
  while(Q.size()) {
    int x = Q.top().second; Q.pop();
    if(vis[x]) continue;
    vis[x] = true;
    if(vis1[x]) ans++;
    for(int k = last[x]; k != -1; k = nt[k]) {
      int v = to[k];
      if(dis[x] + c[k] <= dis[v]) {
        dis[v] = dis[x] + c[k];
        vis1[v] = false;
        Q.push(MP(MP(-dis[v], 0), v));
      }
    }
  }
  printf("%d\n", k - ans);
  return 0;
}
