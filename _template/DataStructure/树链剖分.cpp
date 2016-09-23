/*
* $siz[v]$表示以$v$为根的子树的节点数
* $dep[v]$表示$v$的深度
* $top[v]$表示$v$所在的重链的顶端节点
* $fa[v]$表示$v$的父亲
* $son[v]$表示与$v$在同一重链上的$v$的儿子节点
* $w[v]$表示$v$与其父亲节点的连边在线段树中的位置
* 初始需要调用$cnt1 = cnt2 = cnt3 = 0; dfs1(ROOT, 0); dfs2(ROOT, 1); bt(1, cnt2); $
* 模板为边带权值，点带权值需要修改$query(x, y)$
* $update(x, p, c)$的$p$为线段树中的编号，更新$x$需要调用$w[x]$
*/
const int N = 1e5;
const int M = 2 * N;
typedef long long ll;
#define MID(x, y) (((x) + (y)) >> 1)
#include <bits/stdc++.h>

int fa[N], top[N], w[N], son[N], dep[N], sz[N], r[N];
int a[N], b[N];
ll c[N];
int ind[N];
int t[M], nt[M];
int cnt1, cnt2, cnt3;
int n, m;

struct node
{
    int l, r;
    int a, b;
    ll sum;
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

void add(int a, int b)
{
    t[cnt1] = b;
    nt[cnt1] = ind[a];
    ind[a] = cnt1++;
}

void update(int x)
{
    f[x].sum = f[f[x].l].sum + f[f[x].r].sum;
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
        f[x].sum = 0;
    }
    else
    {
        f[x].sum = 0;
    }
    return x;
}

// 在线段树上查询，不要直接调用
ll query(int x, int a, int b)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].sum;
    int mid = MID(f[x].a, f[x].b);
    ll ans = 0;
    if(a <= mid) ans += query(f[x].l, a, b);
    if(b > mid) ans += query(f[x].r, a, b);
    return ans;
}

// 单调修改
void update(int x, int p, int cc)
{
    if(f[x].a == f[x].b) { f[x].sum = cc; return; }
    int mid = MID(f[x].a, f[x].b);
    if(p <= mid) update(f[x].l, p, cc);
    else update(f[x].r, p, cc);
    update(x);
}

// 树上查询
ll query(int x, int y)
{
    int fx = top[x], fy = top[y];
    ll sum = 0;
    while(fx != fy)
    {
        if(dep[fx] < dep[fy])
        {
            std::swap(x, y);
            std::swap(fx, fy);
        }
        sum += query(rt, w[fx], w[x]);
        x = fa[top[x]];
        fx = top[x];
    }
    if(dep[x] > dep[y]) std::swap(x, y);
    if(x == y) return sum;
    return sum + query(rt, w[son[x]], w[y]);
}

