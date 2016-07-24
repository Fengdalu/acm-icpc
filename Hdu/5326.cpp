#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 200
#define M 2000

int ind[N];
int f[N];
int fa[N];
int t[M], nt[M];
int cnt;
int ans;

void add(int a, int b)
{
    fa[b] = a;
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

void dfs(int x)
{
    f[x] = 0;
    for(int k = ind[x]; k != -1; k = nt[k])
        dfs(t[k]);
    for(int k = ind[x]; k != -1; k = nt[k])
        f[x] += f[t[k]] + 1;
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++) ind[i] = -1;
        cnt = 0;
        memset(fa, 0, sizeof fa);
        memset(f, 0, sizeof f);
        for(int i = 0; i < n - 1; i++)
        {
            int op, ed; scanf("%d%d", &op, &ed);
            add(op, ed);
        }
        ans = 0;
        for(int i = 1; i <= n; i++)
        if(fa[i] == 0) dfs(i);
        for(int i = 1; i <= n; i++) if(f[i] == m) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
