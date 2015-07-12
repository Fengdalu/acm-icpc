//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define LL long long
#define N 50030
#define M 100020
#define mem memset

inline int getint() { static int x; scanf("%d", &x); return x; }
int sz[N], dep[N], son[N], fa[N], top[N], w[N];
int t[M], nt[M], cnt1;
int ind[N], cnt, cnt2;
int n, m, p;
int rt;
int a[N];
char tmp[10];
struct node
{
    int l, r;
    int a, b;
    int c;
}f[M];

int mt(int a, int b)
{
    int tmp = ++cnt2;
    f[tmp].a = a; f[tmp].b = b; f[tmp].c = 0;
    if(a < b)
    {
        int mid = (a + b) / 2;
        f[tmp].l = mt(a, mid);
        f[tmp].r = mt(mid + 1, b);
    }
    return tmp;
}

void adde(int op, int ed)
{
    t[cnt] = ed;
    nt[cnt] = ind[op];
    ind[op] = cnt;
    cnt++;
}

void dfs(int x)
{
    son[x] = 0; sz[x] = 1;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != fa[x])
    {
        fa[t[k]] = x;
        dep[t[k]] = dep[x] + 1;
        dfs(t[k]); sz[x] += sz[t[k]];
        if(sz[son[x]] < sz[t[k]]) son[x] = t[k];
    }
}

void add(int x, int c)
{
    f[x].c += c;
}

void pd(int x)
{
    f[f[x].l].c += f[x].c;
    f[f[x].r].c += f[x].c;
    f[x].c = 0;
}


void ins(int x, int a, int b, int c)
{
    //cout << "RANGE: "<< f[x].a << " " << f[x].b << endl;
    if(a <= f[x].a && f[x].b <= b) add(x, c);
    else
    {
        pd(x);
        int mid = (f[x].a + f[x].b) / 2;
        if(a <= mid) ins(f[x].l, a, b, c);
        if(b > mid) ins(f[x].r, a, b, c);
    }
}

int qry(int x, int p)
{
    if(f[x].a == f[x].b) return f[x].c;
    else
    {
        pd(x); int mid = (f[x].a + f[x].b) / 2;
        if(p <= mid) return qry(f[x].l, p);
        else return qry(f[x].r, p);
    }
}

void bt(int x, int p)
{
    w[x] = ++cnt1;  top[x] = p;
    if(son[x]) bt(son[x], p);
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != son[x] && t[k] != fa[x]) bt(t[k], t[k]);
}

void ins(int v1, int v2, int c)
{
    int f1 = top[v1], f2 = top[v2];
    while(f1 != f2)
    {
        //cout << "fathers: " << f1 << " " << f2 << endl;
        if(dep[f1] < dep[f2]) { swap(f1, f2); swap(v1, v2); }
        ins(rt, w[f1], w[v1], c);
        v1 = fa[f1]; f1 = top[v1];
    }
    if(dep[v1] > dep[v2]) swap(v1, v2);
    ins(rt, w[v1], w[v2], c);
}

int main()
{
    while(~scanf("%d%d%d", &n, &m, &p))
    {
        for(int i = 1; i <= n; i++) a[i] = getint();
        for(int i = 1; i <= n; i++) ind[i] = -1; cnt = 0;
        for(int i = 0; i < m; i++)
        {
            int op = getint(), ed = getint();
            adde(op, ed); adde(ed, op);
        }
        mem(sz, 0, sizeof sz);
        mem(dep, 0, sizeof dep);
        mem(son, 0, sizeof son);
        dfs(1); cnt1 = 0; bt(1, 1);

        cnt2 = 1;
        rt = mt(0, n);
        for(int i = 1; i <= n; i++) ins(i, i, a[i]);
        for(int i = 0; i < p; i++)
        {
            scanf("%s", tmp);
            //cout << tmp << endl;
            int op, ed, pt;
            if(!strcmp(tmp, "I")) { op = getint(); ed = getint(); pt = getint(); ins(op, ed, pt); }
            if(!strcmp(tmp, "D")) { op = getint(); ed = getint(); pt = getint(); ins(op, ed, -pt); }
            if(!strcmp(tmp, "Q")) { op = getint(); printf("%d\n", qry(rt, w[op])); }
        }
    }
    return 0;
}
