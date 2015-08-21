#include <iostream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 10010
#define POW 20

int ind[N], d[N];
int t[N], nt[N];
int f[N][POW];
int cnt;

void add(int a, int b)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

void dfs(int x, int dep)
{
    d[x] = dep;
    for(int i = 1; i < POW; i++) f[x][i] = f[f[x][i - 1]][i - 1];
    for(int k = ind[x]; k != -1; k = nt[k]) dfs(t[k], dep + 1);
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

int main()
{
//    freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        int rt = -1;
        memset(ind, -1, sizeof ind);
        cnt = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int x, y; scanf("%d%d", &x, &y);
            f[y][0] = x;
            add(x, y);
            if(rt == -1 || rt == y) rt = x;
        }
        for(int i = 1; i < POW; i++) f[rt][i] = rt;
        dfs(rt, 1);
        int x, y; scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    return 0;
}