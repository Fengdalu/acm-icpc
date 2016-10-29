#include <bits/stdc++.h>

const int N = 1e3+10;
const int M = N * N;
struct Graph {
    std::stack<int> s;
    int ind[N], low[N], dfn[N], vis[N], color[N];
    int to[M], nt[M];
    int ncnt;
    int cnt;
    int num;

    void init(int n) {
        std::fill(ind, ind + n + 1, -1);
        std::fill(vis, vis + n + 1, 0);
        std::fill(dfn, dfn + n + 1, 0);
        std::fill(low, low + n + 1, 0);
        cnt = 0;
        ncnt = 0;
        num = 0;
    }

    void add(int i, int j) {
        cnt++;
        to[cnt] = j;
        nt[cnt] = ind[i];
        ind[i] = cnt;
    }

    void tarjan(int x) {
        if(dfn[x] != 0) return;
        low[x] = dfn[x] = ++num;
        vis[x] = true;
        s.push(x);
        for(int k = ind[x]; k != -1; k = nt[k]) {
            tarjan(to[k]);
            if(vis[to[k]]) low[x] = std::min(low[x], low[to[k]]);
        }
        if(dfn[x] == low[x]) {
            ncnt++;
            while(true) {
                int p = s.top();
                s.pop();
                color[p] = ncnt;
                vis[p] = false;
                if(p == x) break;
            }
        }
    }
} G;

double x[N], y[N], r[N];
int w[N];
int c[N];
int in[N];
int n;
std::vector<int> g[N];

double sqr(double x) { return x * x; }
double dis(double x1, double y1, double x2, double y2) {
    return sqr(x1 - x2) + sqr(y1 - y2);
}

int main() {
    int _t; scanf("%d", &_t);
    for(int cas = 1; cas <= _t; cas++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%lf%lf%lf%d", x + i, y + i, r + i, c + i);
        G.init(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(sqr(r[i]) >= dis(x[i], y[i], x[j], y[j]))
                    G.add(i, j);
            }
        for(int i = 0; i < n; i++)
            if(!G.vis[i]) G.tarjan(i);
        for(int i = 1; i <= G.ncnt; i++) g[i].clear();
        std::fill(w, w + G.ncnt + 1, 1e9);
        for(int i = 0; i < n; i++) {
            w[G.color[i]] = std::min(w[G.color[i]], c[i]);
        }
        std::fill(in, in + G.ncnt + 1, 0);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                int u = G.color[i], v = G.color[j];
                if(u == v)  continue;
                if(sqr(r[i]) >= dis(x[i], y[i], x[j], y[j]))
                    in[v]++;
            }
        long long tot = 0;
        for(int i = 1; i <= G.ncnt; i++)
            if(in[i] == 0) tot += w[i];
        printf("Case #%d: %lld\n", cas, tot);
    }
    return 0;
}
