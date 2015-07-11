#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 20000
#define M 40020

int t[M], nt[M], c[M], ind[N], cnt;
int sz[N], dp[N], tp[N], sn[N], w[N], fa[N];
int fr[N], to[N], wt[N];
int cc;
int rt;
int n;
int c1;
char buf[10];

struct node
{
    int l, r;
    int a, b;
    int m;
}f[2 * N];

int mt(int a, int b)
{
    #ifdef DEBUG
    cout << "MAKE TREE:" << a << " " << b << endl;
    #endif
    int tmp = ++c1;
    f[tmp].a = a; f[tmp].b = b;
    f[tmp].l = f[tmp].r = -1;
    if(a < b)
    {
        int mid = (a + b) / 2;
        f[tmp].l = mt(a, mid);
        f[tmp].r = mt(mid + 1, b);
    }
    return tmp;
}

void add(int a, int b, int C)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

void dfs(int x)
{
    sz[x] = 1; sn[x] = 0;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != fa[x])
    {
        fa[t[k]] = x;
        dp[t[k]] = dp[x] + 1;
        dfs(t[k]);
        sz[x] += sz[t[k]];
        if(sz[t[k]] > sz[sn[x]]) sn[x] = t[k];
    }
}

void bt(int x, int p)
{
    w[x] = ++cc; tp[x] = p;
    if(sn[x]) bt(sn[x], p);
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != fa[x] && t[k] != sn[x])
        bt(t[k], t[k]);
}

int qry(int x, int a, int b)
{
    #ifdef DEBUG
    cout << "query on: " << a << ", " << b << endl;
    #endif
    if(a <= f[x].a && f[x].b <= b) return f[x].m;
    else
    {
        int mid = (f[x].a + f[x].b) / 2;
        int m = 0;
        if(a <= mid) m = max(m, qry(f[x].l, a, b));
        if(b > mid) m = max(m, qry(f[x].r, a, b));
        return m;
    }
}

void ins(int x, int p, int m)
{
    #ifdef DEBUG
    cout << "insert on: " << f[x].a << ", " << f[x].b << endl;
    #endif
    if( f[x].a == f[x].b ) f[x].m = m;
    else
    {
        int mid = (f[x].a + f[x].b) / 2;
        if(p <= mid) ins(f[x].l, p, m);
        else ins(f[x].r, p, m);
        f[x].m = max(f[f[x].l].m, f[f[x].r].m);
    }
}

int cal(int v1, int v2)
{
    int f1 = tp[v1], f2 = tp[v2];
    int m = 0;
    while(f1 != f2)
    {
        if(dp[f1] < dp[f2]) { swap(f1, f2); swap(v1, v2); }
        m = max(m, qry(rt, w[f1], w[v1]));
        v1 = fa[f1]; f1 = tp[v1];
    }
    if(v1 == v2) return m;
    if(dp[v1] > dp[v2]) swap(v1, v2);
    return max(m, qry(rt, w[sn[v1]], w[v2]));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int I = 0; I < T; I++ )
    {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) ind[i] = -1;
        cnt = 0;
        memset(sz, 0, sizeof sz);
        memset(dp, 0, sizeof dp);
        memset(sn, 0, sizeof sn);
        cc = 0;
        c1 = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int a, b, t;
            scanf("%d%d%d", &a, &b, &t);
            add(a, b, t); add(b, a, t);
            fr[i] = a; to[i] = b; wt[i] = t;
        }
        dfs(1);
        bt(1, 1);
        rt = mt(1, n);

        #ifdef DEBUG
        for(int i = 1; i <= n; i++) cout << "NODE: " << i << " sn: " << sn[i] << ", sz: " << sz[i] << " top: " << tp[i] << " w " << w[i] <<  endl;
        #endif
        for(int i = 0; i < n - 1; i++)
        {
            if(fa[fr[i]] == to[i]) ins(rt, w[fr[i]], wt[i]);
            else ins(rt, w[to[i]], wt[i]);
        }
        while(true)
        {
            scanf("%s", buf);
            if(!strcmp(buf, "DONE")) break;
            int tmp1, tmp2; scanf("%d%d", &tmp1, &tmp2);
            if(!strcmp(buf, "QUERY")) printf("%d\n", cal(tmp1, tmp2));
            else
            {
                tmp1--;
                if(fa[fr[tmp1]] == to[tmp1]) ins(rt, w[fr[tmp1]], tmp2);
                else ins(rt, w[to[tmp1]], tmp2);
            }
        }
    }
    return 0;
}
