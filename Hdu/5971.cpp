#include <bits/stdc++.h>

int main() {
  int n, m, x, y;
  while(~scanf("%d%d%d%d", &n, &m, &x, &y)) {
    std::vector< std::vector<int> > g(n);
    std::vector< std::pair<int, int> > edges(m);
    std::vector<int> color(n, -1);
    while(m--) {
      int u, v; scanf("%d%d", &u, &v);
      u--; v--;
      g[v].push_back(u); 
      g[u].push_back(v);
      edges[m] = std::make_pair(u, v);
    }
    for(int i = 0; i < x; i++) { 
      int cur; 
      scanf("%d", &cur); color[--cur] = 0; 
    }

    for(int i = 0; i < y; i++) { 
      int cur; 
      scanf("%d", &cur); color[--cur] = 1; 
    }
    std::vector<bool> vis(n, 0);

    for(int i = 0; i < n; i++) 
      if(!vis[i] && color[i] != -1) {
        std::queue<int> q;
        q.push(i);
        vis[i] = true;
        while(q.size()) {
          int now = q.front(); q.pop();
          for(auto &v: g[now]) {
            if(vis[v]) continue;
            if(color[v] == -1) color[v] = !color[now];
            if(!vis[v]) {
              vis[v] = true;
              q.push(v);
            }
          }
        }
      }

    bool flag = true; 
    for(int i = 0; i < n; i++) 
      if(!vis[i] && color[i] == -1) {
        std::queue<int> q;
        q.push(i);
        vis[i] = true;
        if(g[i].size() == 0) flag = false;
        color[i] = 0;
        while(q.size()) {
          int now = q.front(); q.pop();
          for(auto &v: g[now]) {
            if(vis[v]) continue;
            color[v] = !color[now];
            if(!vis[v]) {
              vis[v] = true;
              q.push(v);
            }
          }
        }
      }

    for(auto &e: edges) {
      int u = e.first, v = e.second;
      if(color[u] == color[v])
        flag = false;
    }

    if(flag) puts("YES");
    else puts("NO");
  }
  return 0;
}
