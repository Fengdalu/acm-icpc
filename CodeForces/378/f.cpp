#include <bits/stdc++.h>

typedef long long ll;
const ll inf = 1e10;
struct edge { int v, w; edge(int v=0, int w=0) : v(v), w(w) {} };
const int N = 2e5+100;
const int M = 2e5+100;
const int POW = 22;
int a[M], b[M], c[M], w[M];
int p[M];
int fa[N];
int pre[N][POW];
ll f[N][POW];
int deep[N];
std::vector<edge> g[N];

int cmp(int x, int y) { return w[x] < w[y]; }
int find(int x) { return (fa[x] == x ? x : fa[x] = find(fa[x])); }

void build(int x, int fa) {
    for(int i = 1; i < POW; i++) pre[x][i] = pre[pre[x][i - 1]][i - 1];
    for(int i = 1; i < POW; i++) f[x][i] = std::max(f[pre[x][i - 1]][i - 1], f[x][i - 1]);
    for(auto &now : g[x]) 
        if(now.v != fa) { 
            int v = now.v;
            deep[v] = deep[x] + 1;
            pre[v][0] = x;
            f[v][0] = now.w;
            build(now.v, x);
        }
}

int lca(int x, int y) {
    if(deep[x] < deep[y]) std::swap(x, y);
    int dt = deep[x] - deep[y];
    for(int i = 0; i < POW; i++)
        if(1 << i & dt) x = pre[x][i];
    if(x == y) return x;
    for(int i = POW - 1; i >= 0; i--)
        if(pre[x][i] != pre[y][i])
            x = pre[x][i], y = pre[y][i];
}

int cal(int p, int fa) {
    int dt = deep[p] - deep[fa];
    int ans = -inf;
    for(int i = POW - 1; i >= 0; i--)
        if(dt >> i & 1) {
            ans = std::max(ans, f[p][i]);
            ans = pre[p][i];
        }
    return ans;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) scanf("%d", w + i);
    for(int i = 0; i < m; i++) scanf("%d", c + i);
    for(int i = 0; i < m; i++) scanf("%d%d", a + i, b + i);
    for(int i = 0; i < m; i++) p[i] = i;
    for(int i = 1; i <= n; i++) fa[i] = i;
    std::sort(p, p + m, cmp);
    int mn = -inf;
    for(int i = 0; i < m; i++) {
        int u = a[p[i]], v = b[p[i]];
        ll cur = c[p[i]] - S / c[i];
        if(cur <= mn) {

        }
        if(find(u) == find(v)) continue;
        fa[find(u)] = find(v);
        g[u].push_back(edge(v, c[p[i]]));
        g[v].push_back(edge(u, c[p[i]]));
    }
    for(int i = 0; i < POW; i++) pre[1][i] = 1;
    for(int i = 0; i < POW; i++) f[1][i] = -inf;
    for(int i = 0; i < n; i++) {
    }
    build(1, 1);
}
