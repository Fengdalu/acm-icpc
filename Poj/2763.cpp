#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 100011
#define M 200020

int c[N], fr[N], to[N];
int n, q, s;
int ind[N];
int cnt, cnt1, cnt2;
int t[M], nt[M];
int rt;

void add(int op, int ed)
{
    t[cnt] = ed;
    nt[cnt] = ind[op];
    ind[op] = cnt++;
}

int sz[N], dep[N], son[N], top[N];
int w[N], fa[N];

void dfs(int x)
{
    sz[x] = 1; son[x] = 0;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != fa[x])
    {
        fa[t[k]] = x;
        dep[t[k]] = dep[x] + 1;
        dfs(t[k]); sz[x] += sz[t[k]];
        if(sz[son[x]] < sz[t[k]]) son[x] = t[k];
    }
}

void bt(int x, int p)
{
    top[x] = p; w[x] = ++cnt1;
    if(son[x]) bt(son[x], p);
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != son[x] && t[k] != fa[x]) bt(t[k], t[k]);

}

struct node
{
    int a, b; int l, r; int sum;
}f[2 * N];
int mt(int a, int b)
{
    int tmp = ++cnt2;
    f[tmp].a = a; f[tmp].b = b;
    f[tmp].sum = 0;
    if(a < b)
    {
        int mid = (a + b) / 2;
        f[tmp].l = mt(a, mid);
        f[tmp].r = mt(mid + 1, b);
        f[tmp].sum = f[f[tmp].l].sum + f[f[tmp].r].sum;
    }
    return tmp;
}

int cal(int x, int a, int b)
{
    if(a <= f[x].a && f[x].b <= b) return f[x].sum;
    else
    {
        int sum = 0, mid = (f[x].a + f[x].b) / 2;
        if(a <= mid) sum += cal(f[x].l, a, b);
        if(b > mid) sum += cal(f[x].r, a, b);
        return sum;
    }
}

void ins(int x, int p, int c)
{
    // cout << "ins " << f[x].a << " " << f[x].b << endl;
    if(f[x].a == f[x].b) f[x].sum = c;
    else
    {
        int mid = (f[x].a + f[x].b) / 2;
        if(p <= mid) ins(f[x].l, p, c);
        else ins(f[x].r, p, c);
        f[x].sum = f[f[x].l].sum + f[f[x].r].sum;
    }
}

int cal(int v1, int v2)
{
    int f1 = top[v1], f2 = top[v2], sum = 0;
    while(f1 != f2)
    {
        if(dep[f1] < dep[f2]) { swap(f1, f2); swap(v1, v2); }
        sum += cal(rt, w[f1], w[v1]);
        v1 = fa[f1]; f1 = top[v1];
    }
    if(v1 == v2) return sum;
    if(dep[v1] > dep[v2]) swap(v1, v2);
    //cout << "FINAL ON: " << v1 << " " << v2 << endl;
    return sum + cal(rt, w[son[v1]], w[v2]);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    memset(sz, 0, sizeof sz);
    memset(top, 0, sizeof top);
    memset(son, 0, sizeof son);
    memset(dep, 0, sizeof dep);
    scanf("%d%d%d", &n, &q, &s);
    for(int i = 0; i < n - 1; i++) scanf("%d%d%d", &fr[i], &to[i], &c[i]);
    for(int i = 1; i <= n; i++) ind[i] = -1;
    cnt = 0;
    for(int i = 0; i < n - 1; i++) { add(fr[i], to[i]); add(to[i], fr[i]); }
    dfs(1); cnt1 = 0; bt(1, 1);
    cnt2 = 0;
    rt = mt(0, n);

    for(int i = 0; i < n - 1; i++)
    if(fa[fr[i]] == to[i]) ins(rt, w[fr[i]], c[i]);
    else ins(rt, w[to[i]], c[i]);
    //cout << "INSERT END" << endl;



    for(int i = 0; i < q; i++)
    {
        int op; scanf("%d", &op);
        if(!op) { int u; scanf("%d", &u); printf("%d\n", cal(s, u)); s = u; }
        else
        {
            int u, v;
            scanf("%d%d", &u, &v); u--;
            if(fa[fr[u]] == to[u]) ins(rt, w[fr[u]], v);
            else ins(rt, w[to[u]], v);
        }
    }
    return 0;
}
