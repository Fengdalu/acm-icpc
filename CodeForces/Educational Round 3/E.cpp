#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define LL long long
#define ONES(x) __builtin_popcount(x)
#define MID(x, y) (((x) + (y)) >> 1)
#define cmax(x, y) x = max(x, y)
const int N = 200010;
const int M = 2 * N;
int fa[N], top[N], w[N], son[N], dep[N], sz[N], r[N];
int a[N], b[N];
LL c[N];
int ind[N];
int t[M], nt[M];
int cnt1, cnt2, cnt3;
int n, m;

struct node
{
    int l, r;
    int a, b;
    LL Max = 0;
}f[M];
int rt;

void dfs1(int x, int d)
{
    dep[x] = d;
    son[x] = 0;
    sz[x] = 1;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != fa[x])
    {
        fa[t[k]] = x;
        dfs1(t[k], d + 1);
        sz[x] += sz[t[k]];
        if(sz[t[k]] > sz[son[x]]) son[x] = t[k];
    }
}

void dfs2(int x, int tt)
{
    w[x] = ++cnt2;
    top[x] = tt;
    if(son[x]) dfs2(son[x], tt);
    for(int k = ind[x]; k != -1; k = nt[k]) if(t[k] != fa[x] && t[k] != son[x])
        dfs2(t[k], t[k]);
}

LL add(int a, int b)
{
    t[cnt1] = b;
    nt[cnt1] = ind[a];
    ind[a] = cnt1++;
}

void update(int x)
{
    f[x].Max = max(f[f[x].l].Max, f[f[x].r].Max);
}

int bt(int a, int b)
{
    int x = cnt3++;
    f[x].a = a; f[x].b = b;
    if(a < b)
    {
        int mid = MID(a, b);
        f[x].l = bt(a, mid);
        f[x].r = bt(mid + 1, b);
        update(x);
    }
    else
    {
        f[x].Max = 0;
    }
    return x;
}

// `在线段树上查询，不要直接调用`
LL query(int x, int a, int b)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].Max;
    int mid = MID(f[x].a, f[x].b);
    if(b <= mid) return query(f[x].l, a, b);
    else if(a > mid) return query(f[x].r, a, b);
    else return max(query(f[x].l, a, b), query(f[x].r, a, b));
}

//`单调修改`
void update(int x, int p, LL cc)
{
    if(f[x].a == f[x].b) { cmax(f[x].Max, cc); return; }
    int mid = MID(f[x].a, f[x].b);
    if(p <= mid) update(f[x].l, p, cc);
    else update(f[x].r, p, cc);
    update(x);
}

// `树上查询`
LL query(int x, int y)
{
    int fx = top[x], fy = top[y];
    LL Max = 0;
    while(fx != fy)
    {
        if(dep[fx] < dep[fy])
        {
            swap(x, y);
            swap(fx, fy);
        }
        cmax(Max, query(rt, w[fx], w[x]));
        x = fa[top[x]];
        fx = top[x];
    }
    if(dep[x] > dep[y]) swap(x, y);
    if(x == y) return Max;
    return max(Max, query(rt, w[son[x]], w[y]));
}

struct edge {
    int id;
    int a, b;
    LL c;
    LL p;
    bool flg;
}e[N];
int ff[N];
LL mst;

int find(int x) {
    if(ff[x] == x) return x;
    ff[x] = find(ff[x]);
    return ff[x];
}

void Union(int x, int y) {
    ff[find(x)] = find(y);
}

int cmp1(edge a, edge b) {
    return a.c < b.c;
}

int cmp2(edge a, edge b) {
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(false);
    memset(ind, -1, sizeof ind);
    cnt1 = cnt2 = cnt3 = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        e[i].id = i;
        cin >> e[i].a >> e[i].b >> e[i].c;
    }
    sort(e, e + m, cmp1);
    for(int i = 1; i <= n; i++) ff[i] = i;
    for(int i = 0; i < m; i++) if(find(e[i].a) != find(e[i].b)){
        add(e[i].a, e[i].b);
        add(e[i].b, e[i].a);
        mst += e[i].c;
        Union(e[i].a, e[i].b);
        e[i].flg = true;
    } else e[i].flg = false;
    int ROOT = 1;
    dfs1(ROOT, 0); dfs2(ROOT, 1); int rt = bt(1, cnt2);

    for(int i = 0; i < m; i++) if(e[i].flg) {
        if(fa[e[i].a] == e[i].b) {
            update(rt, w[e[i].a], e[i].c);
        }
        else update(rt, w[e[i].b], e[i].c);
    }

    for(int i = 0; i < m; i++) if(!e[i].flg) {
        e[i].p = query(e[i].a, e[i].b);
    }

    sort(e, e + m, cmp2);
    for(int i = 0; i < m; i++) {
        if(e[i].flg) printf("%I64d\n", mst);
        else printf("%I64d\n", mst - e[i].p + e[i].c);
    }
    return 0;
}
