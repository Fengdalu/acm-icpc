#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
typedef long long ll;
const int N = 1000100;
const int M = 1000100;
const ll inf = 1e18;
int n, m;
int ind[N];
ll dis[N];
bool vis[N];
int to[M], nt[M], w[M];
int cnt;

void add(int a, int b, double c) {
    to[cnt] = b;
    w[cnt] = c;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

int op[M], ed[M], wt[M];

void spfa(int op) {
    std::fill(dis, dis + n + 1, inf);
    std::fill(vis, vis + n + 1, 0);
    std::deque<int>q;
    dis[op] = 0;
    q.push_back(op);
    double tot = 0;
    while(q.size()) {
        int u = q.front(); q.pop_front();
        vis[u] = false;
        for(int k = ind[u]; k != -1; k = nt[k]) {
            int v = to[k];
            if(dis[v] < dis[u] + w[k]) continue;
            if(vis[v]) tot -= dis[v];
            dis[v] = dis[u] + w[k];
            tot += dis[v];
            if(vis[v]) continue;
            vis[v] = true;
            if(q.size() && dis[v] > dis[q.front()]) q.push_front(v);
            else q.push_back(v);
            q.push_back(v);
        }
    }

}
int main() {
    int _t; scanf("%d", &_t);
    while(_t--) {
        scanf("%d%d", &n, &m);
        cnt = 0; std::fill(ind, ind + n + 1, -1);
        for(int i = 0; i < m; i++) {
            scanf("%d%d%d", op + i, ed + i, wt + i);
            add(op[i], ed[i], wt[i]);
        }
        spfa(1);
        ll ans = 0;
        for(int i = 2; i <= n; i++) ans += 1ll * dis[i];
        cnt = 0; std::fill(ind, ind + n + 1, -1);
        for(int i = 0; i < m; i++) {
            add(ed[i], op[i], wt[i]);
        }
        spfa(1);
        for(int i = 2; i <= n; i++) ans += 1ll * dis[i];
        std::cout << ans + dis[1] << std::endl;
    }
    return 0;
}

