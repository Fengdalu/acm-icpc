#include <bits/stdc++.h>


int dis[20];
int p[20];
int vis[20];
int main() {
    int n, m;
    while(~scanf("%d", &n)) {
        std::vector<int>g[11], w[11];
        for(int i = 0; i < n; i++) {
            int m;
            scanf("%d%d", &m, p + i);
            for(int j = 0; j < m; j++) {
                int s, l; scanf("%d%d", &s, &l);
                g[i].push_back(s);
                w[i].push_back(l);
            }
        }
        std::fill(dis, dis + n, 100000000);
        std::fill(vis, vis + n, 0);
        dis[0] = 0;
        std::queue<int> q;
        q.push(0);
        while(q.size()) {
            int t = q.front(); q.pop(); vis[t] = false;
            for(int j = 0; j < g[t].size(); j++) {
                int v = g[t][j], c = w[t][j];
                if(dis[v] > dis[t] + c) {
                    dis[v] = dis[t] + c;
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        int ans = 100000000;
        for(int i = 0; i < n; i++) if(p[i]) ans = std::min(ans, dis[i]);
        std::cout << ans << std::endl;
    }
    return 0;
}
