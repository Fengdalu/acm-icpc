#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define N 40000
#define M (2 * N)
#define INF (1 << 30)

struct node
{
    int l, r;
    int a, b;
    int sum, m;
}f[3 * N];
int rt;
int ind[N], c[N];
int t[M], nt[M];
int fa[N], top[N], son[N], w[N], dep[N], sz[N];
int cnt1, cnt, cnt2;
int op1, op2;
int n;
char buf[20];

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
    w[x] = ++cnt1;
    top[x] = tt;
    if(son[x] != 0) dfs2(son[x], tt);
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != son[x] && t[k] != fa[x]) dfs2(t[k], t[k]);
}

void add(int a, int b)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

void update(int x)
{
    f[x].m = max(f[f[x].l].m, f[f[x].r].m);
    f[x].sum = f[f[x].l].sum + f[f[x].r].sum;
}

void insert(int x, int p, int cc)
{
    if(f[x].a == f[x].b) f[x].sum = f[x].m = cc;
    else
    {
        int mid = (f[x].a + f[x].b) >> 1;
        if(p <= mid) insert(f[x].l, p, cc);
        else insert(f[x].r, p, cc);
        update(x);
    }
}

int sum(int x, int a, int b)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].sum;
    else
    {
        int s = 0;
        int mid = (f[x].a + f[x].b) >> 1;
        if(a <= mid) s += sum(f[x].l, a, b);
        if(b > mid) s += sum(f[x].r, a, b);
        return s;
    }
}

int mm(int x, int a, int b)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].m;
    else
    {
        int s = -INF;
        int mid = (f[x].a + f[x].b) >> 1;
        if(a <= mid)  s = max(s, mm(f[x].l, a, b));
        if(b > mid) s = max(s, mm(f[x].r, a, b));
        return s;
    }
}

int sum(int x, int y)
{
    int ans = 0;
    int fx = top[x], fy = top[y];
    while(fx != fy)
    {
        if(dep[fx] < dep[fy])
        {
            swap(x, y);
            swap(fx, fy);
        }
        ans += sum(rt, w[fx], w[x]);
        x = fa[fx];
        fx = top[x];
    }
    if(dep[x] > dep[y])
    {
        swap(x, y);
    }
    return ans + sum(rt, w[x], w[y]);
}

int mm(int x, int y)
{
    int ans = -INF;
    int fx = top[x], fy = top[y];
    while(fx != fy)
    {
        if(dep[fx] < dep[fy])
        {
            swap(x, y);
            swap(fx, fy);
        }
        ans = max(ans, mm(rt, w[fx], w[x]));
        x = fa[fx];
        fx = top[x];
    }
    if(dep[x] > dep[y])
    {
        swap(x, y);
    }
    return max( ans, mm(rt, w[x], w[y]));
}

int bt(int a, int b)
{
    int x = cnt2++;
    f[x].a = a; f[x].b = b;
    if(a < b)
    {
        int mid = (a + b) / 2;
        f[x].l = bt(a, mid);
        f[x].r = bt(mid + 1, b);
        update(x);
    }
    else
    {
        f[x].sum = f[x].m = 0;
    }
    return x;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    memset(son, 0, sizeof son);
    memset(top, 0, sizeof top);
    memset(fa, 0, sizeof fa);
    scanf("%d", &n);
    cnt1 = cnt = cnt2 = 0;
    memset(ind, -1, sizeof ind);
    for(int i = 1; i < n; i++)
    {
        int x, y; scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);

    fa[1] = 0;
    sz[0] = 0;

    dfs1(1, 0);
    dfs2(1, 1);
//    cout << "SZ "; for(int i = 1; i <= n; i++) cout << sz[i] << " "; cout << endl;
//    cout << "SN "; for(int i = 1; i <= n; i++) cout << son[i] << " "; cout << endl;
//    cout << "TP "; for(int i = 1; i <= n; i++) cout << top[i] << " "; cout << endl;
//    cout << "WW "; for(int i = 1; i <= n; i++) cout << w[i] << " "; cout << endl;

    int rt = bt(1, cnt1);
    for(int i = 1; i <= n; i++) insert(rt, w[i], c[i]);
    int Q; scanf("%d", &Q);
    for(int i = 0; i < Q; i++)
    {
        scanf("%s %d %d", buf, &op1, &op2);
        if(!strcmp(buf, "QMAX")) printf("%d\n", mm(op1, op2));
        if(!strcmp(buf, "QSUM")) printf("%d\n", sum(op1, op2));
        if(!strcmp(buf, "CHANGE")) insert(rt, w[op1], op2);
    }
    return 0;
}