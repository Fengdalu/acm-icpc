#include <iostream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 20010
#define M 400010
#define POW 20

int ind[N], d[N];
int t[M], nt[M];
int f[N][POW];
int h[N];
int cnt;
int n, m;

void add(int a, int b)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

void add2(int a, int b)
{
    add(a, b);
    add(b, a);
}

void dfs(int x, int dep)
{
    d[x] = dep;
    for(int i = 1; i < POW; i++) f[x][i] = f[f[x][i - 1]][i - 1];
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != f[x][0])
    {
        f[t[k]][0] = x;
        dfs(t[k], dep + 1);
    }
}

int lca(int a, int b)
{
    if(d[b] > d[a]) swap(a, b);
    int t = d[a] - d[b];
    for(int i = 0; i < POW; i++) if(t & (1 << i)) a = f[a][i];

    if(a != b)
    {
        for(int i = POW - 1; i >= 0; i--)
        if(f[a][i] != f[b][i])
        {
            a = f[a][i];
            b = f[b][i];
        }
        a = f[a][0]; b = f[b][0];
    }
    return a;
}

int dfs1(int x)
{
    int tmp = 0;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(x == f[t[k]][0])
    {
        tmp += dfs1(t[k]);
    }
    for(int k = ind[x]; k != -1; k = nt[k])
    {
        int rt = lca(t[k], x);
        if(rt != t[k] && rt != x) tmp++;
        if(rt == t[k] && d[t[k]] < d[x]) tmp++;
    }
    h[x] = tmp;
    return tmp;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int _T; scanf("%d", &_T);

    for(int _i = 1; _i <= _T; _i++)
    {
        scanf("%d%d", &n, &m);
        cnt = 0;
        memset(ind, -1, sizeof ind);
        int x, y;
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d%d", &x, &y);
            add2(x, y);
        }
        f[1][0] = 1;
        dfs(1, 0);
        for(int i = 0; i < m - n + 1; i++)
        {
            scanf("%d%d", &x, &y);
            add2(x, y);
        }
        dfs1(1);
        int ans = h[2];
        for(int i = 3; i <= n; i++) ans = min(ans, h[i]);
        printf("Case #%d: %d\n", _i, ans);
    }
    return 0;
}