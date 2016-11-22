#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

typedef long long ll;
typedef std::pair<int, int> pii;
const ll inf = 1e15;

const int N = 1e5+1000;
struct edge { int to, w;  edge(){}; edge(int to, int w): to(to), w(w){}; };
std::vector<edge> g[N];
ll y[N];
ll dp[N][2];
bool vis[N][2];
ll qa[N], qb[N];

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u].push_back(edge(v, w));
    g[v].push_back(edge(u, w));
  }
  for(int i = 1; i <= n; i++) y[i] = inf;
  for(int i = 0; i < k; i++) {
    int s, w;
    scanf("%d%d", &s, &w);
    y[s] = std::min(y[s], 1ll * w);
    qa[i] = s;
    qb[i] = w;
  }
  std::queue<pii> q;
  for(int i = 1; i <= n; i++) {
    dp[i][0] = dp[i][1] = inf;
  }
  dp[1][0] = 0;
  q.push(std::make_pair(1, 0));
  while(q.size()) {
    pii now = q.front(); q.pop();
    vis[now.first][now.second] = false;
    ll value = dp[now.first][now.second];

    for(auto &next : g[now.first]) {
      if(value + next.w < dp[next.to][now.second]) {
        dp[next.to][now.second] = value + next.w;
        if(!vis[next.to][now.second]) {
          vis[next.to][now.second] = true;
          q.push(std::make_pair(next.to, now.second));
        }
      }
    }

    if(now.second == 0) {
      for(auto &next : g[now.first]) {
        if(y[now.first] + next.w < dp[next.to][1]) {
          dp[next.to][1] = y[now.first] + next.w;
          if(!vis[next.to][1]) {
            vis[next.to][1] = true;
            q.push(std::make_pair(next.to, 1));
          }
        }
      }
    }
  }
  int ans = 0;

  for(int i = 0; i < k; i++) {
    ll v = qa[i];
    ll cur = std::min(dp[v][0], dp[v][1]);
    if(qb[i] >= cur) ans++;
  }

  printf("%d\n", ans);
  return 0;
}
