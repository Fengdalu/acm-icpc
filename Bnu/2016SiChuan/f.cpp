#include <bits/stdc++.h>

const int N = 1e5+200;
const int M = N*2;
const int POW = 20;
typedef struct  {
    int last[N];
    int to[M], nt[M];
    int cnt;
    void init() { std::fill(last, last + N, -1); cnt = 0;  }
    void add(int u, int v) { to[cnt] = v; nt[cnt] = last[u]; last[u] = cnt++;  }
} Graph;
Graph G;

std::vector<int> T[N];
int op[N], ed[N];
int fa[N];
int n, m, q;
int p[N][POW];
int d[N];
int cut[N], cnt;
int dis[500][N];
int vis[N];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void dfs(int u, int fa){
    d[u] = d[fa] + 1;
    p[u][0] = fa;
    for(int i = 1; i < POW; i++) p[u][i] = p[p[u][i - 1]][i - 1];
    int sz = T[u].size();
    for(int i = 0; i < sz; i++){
        int v = T[u][i];
        if(v == fa) continue;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if(d[a] > d[b]) a ^= b, b ^= a, a ^= b;
    if(d[a] < d[b]) {
        int del = d[b] - d[a];
        for(int i = 0; i < POW; i++) if(del & (1 << i)) b = p[b][i];
    }
    if(a != b) {
        for(int i = POW - 1; i >= 0; i--)
            if(p[a][i] != p[b][i])
                a = p[a][i], b = p[b][i];
        a = p[a][0], b = p[b][0];
    }
    return a;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i < m; i++) scanf("%d%d", op + i, ed + i);
    for(int i = 1; i <= n; i++) fa[i] = i;
    cnt = 0;
    G.init();
    for(int i = 0; i < m; i++) {
        int u = op[i], v = ed[i];
        G.add(u, v);
        G.add(v, u);
        if(find(u) != find(v)) {
            T[u].push_back(v);
            T[v].push_back(u);
            fa[find(u)] = find(v);
        }
        else {
            cut[cnt++] = u;
            cut[cnt++] = v;
        }
    }
    dfs(1, -1);
    std::sort(cut, cut + cnt);
    cnt = std::unique(cut, cut + cnt) - cut;
    for(int i = 0; i < cnt; i++) {
        std::fill(vis, vis + n + 1, 0);
        int op = cut[i];
        int *f = dis[i];
        f[op] = 0;
        std::queue<int> q;
        q.push(op); vis[op] = true;
        while(q.size()) {
            int x = q.front(); q.pop();
            for(int k = G.last[x]; k != -1; k = G.nt[k]) {
                int v = G.to[k];
                if(vis[v]) continue;
                f[v] = f[x] + 1;
                q.push(v);
                vis[v] = true;
            }
        }
    }
    while(q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int ans = d[u] + d[v] - d[lca(u, v)] * 2;
        for(int i = 0 ; i < cnt; i++) {
            ans = std::min(ans, dis[i][u] + dis[i][v]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

