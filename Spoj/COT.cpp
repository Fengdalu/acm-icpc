#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
#define PB(x) push_back(x)
#define SZ size()
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
struct E {
    int l, r;
    int sum;
}e[10000000];
int rt[100010];
int X[100010];
int w[100010];
int fa[100010][22];
int dep[100010];
int q[100010];
int root, tot;
vector<int>g[100010];

void build(int &rt, int l, int r) {
    rt = tot++;
    e[rt].sum = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(e[rt].l, l, mid);
    build(e[rt].r, mid + 1, r);
}

int lca(int u, int v) {
    if(dep[v] > dep[u]) swap(u, v);
    int k = 0;
    int tmp = dep[u] - dep[v];
    for(int i = 0; i < 20; i++) if(1 << i & tmp) {
        u = fa[u][i];
    }
    if(u == v) return u;
    for(int i = 20; i >= 0; i--)
        if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

void update(int &rt, int l, int r, int w, int fa) {
    rt = tot++;
    e[rt].l = e[fa].l;
    e[rt].r = e[fa].r;
    e[rt].sum = e[fa].sum + 1;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    if(w <= mid) update(e[rt].l, l, mid, w, e[fa].l);
    else update(e[rt].r, mid + 1, r, w, e[fa].r);
}

int query(int a, int b, int c, int l, int r, int k, int nd) {
    int mid = (l + r) >> 1;
    int sum = e[e[a].l].sum + e[e[b].l].sum - e[e[c].l].sum * 2 + (int)(nd <= mid);
    if(l == r) return l;
    if(k <= sum) return query(e[a].l, e[b].l, e[c].l, l, mid, k, nd);
    else return query(e[a].r, e[b].r, e[c].r, mid + 1, r, k - sum, (nd <= mid ? 1e9 : nd));
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
        w[i] = X[i];
    }
    sort(X, X + n);
    int cnt = unique(X, X + n) - X;
    for(int i = 0; i < n; i++) w[i] = lower_bound(X, X + cnt, w[i]) - X;
    for(int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        g[a].PB(b); g[b].PB(a);
    }
    int root = 0;
    build(root, 0, cnt - 1);
    fa[0][0] = 0;
    int aa = 0, bb = 0;
    q[aa] = 0;
    while(aa <= bb) {
        int u = q[aa]; aa++;
        if(u == 0)
            update(rt[u], 0, cnt - 1, w[u], root);
        else
            update(rt[u], 0, cnt - 1, w[u], rt[fa[u][0]]);
        for(int i = 0; i < g[u].SZ; i++) {
            int v = g[u][i];
            if(v == fa[u][0]) continue;
            fa[v][0] = u;
            for(int i = 0; i < 20; i++) fa[v][i + 1] = fa[fa[v][i]][i];
            dep[v] = dep[u] + 1;
            q[++bb] = v;
        }
    }
    while(m--) {
        int u, v, k;
        scanf("%d%d%d", &u, &v, &k);
        u--; v--;
        printf("%d\n", X[query(rt[u], rt[v], rt[lca(u, v)], 0, cnt - 1, k, w[lca(u, v)])]);
    }
    return 0;
}
