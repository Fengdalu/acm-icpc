#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
#define M (2 * N)
#define LL long long

int fa[N], top[N], w[N], son[N], dep[N], sz[N], r[N];
int a[N], b[N];
int ind[N];
int t[M], nt[M];
int cnt1, cnt2, cnt3;
int n, m;

struct node
{
    int l, r;
    int c;
    int lc, rc;
    int cnt;
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

int bt(int a, int b)
{
    int x = cnt3++;
    if(a < b)
    {
        int mid = (a + b) / 2;
        f[x].l = bt(a, mid);
        f[x].r = bt(mid + 1, b);
    }
    return x;
}

node merge(node a, node b)
{
    node p;
    if(a.c == b.c) p.c = a.c; else p.c = -1;
    p.cnt = a.cnt + b.cnt;
    if(a.rc == b.lc) p.cnt--;
    p.lc = a.lc; p.rc = b.rc;
}

void deal(node &p, int c)
{
    p.c = p.lc = p.rc = c;
    p.cnt = 1;
}

void down(node &p)
{
    if(p.c != -1)
    {
        deal(f[p.l], p.c);
        deal(f[p.r],p.c);
    }
}

void insert(int x, int L, int R, int a, int b, int c)
{
    if(L <= a && b <= R) deal(f[x], c);
    else
    {
        down(f[x]);
        int mid = (L + R) / 2;
        if(b <= mid) insert(f[x].l, L, mid, a, b, c);
        if(a > mid) insert(f[x].r, mid + 1, R, a, b, c);
        else { insert(f[x].l, L, mid, a, b, c); insert(f[x].r, mid + 1, R, a, b, c); }
        f[x] = merge(f[f[x].l], f[f[x].r]);
    }
}

node query(int x, int L, int R, int a, int b)
{
    if(L <= a && b <= R) return f[x];
    else
    {
        down(f[x]);
        int mid = (L + R) / 2;
        if(b <= mid) return query(f[x].l, L, mid, a, b);
        if(a > mid) return query(f[x].r, mid + 1, R, a, b);
        else { return merge(query(f[x].l, L, mid, a, b), query(f[x].r, mid + 1, R, a, b)); }
    }
}

void insert(int x, int y)
{
    int fx = top[x], fy = top[y];
    LL sum = 0;
    while(fx != fy)
    {
        if(dep[fx] < dep[fy])
        {
            swap(x, y);
            swap(fx, fy);
        }
        insert(rt, w[fx], w[x]);
        x = fa[top[x]];
        fx = top[x];
    }
    if(dep[x] > dep[y]) swap(x, y);
    insert(rt, w[x], w[y]);
}

 insert(int x, int y)
{
    int fx = top[x], fy = top[y];
    LL sum = 0;
    while(fx != fy)
    {
        if(dep[fx] < dep[fy])
        {
            swap(x, y);
            swap(fx, fy);
        }
        insert(rt, w[fx], w[x]);
        x = fa[top[x]];
        fx = top[x];
    }
    if(dep[x] > dep[y]) swap(x, y);
    insert(rt, w[x], w[y]);
}

int c[N];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    cnt1 = cnt2 = cnt3 = 0;
    dfs1(1, 0); dfs2(1, 1); rt = bt(1, cnt2);
    for()
    return 0;
}
