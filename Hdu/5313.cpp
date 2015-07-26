#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;
#define N 10010
#define M 200010
#define LL long long

int a[N], b[N];
int ind[N], cnt;
int nt[M], t[M];
int vis[N];
bitset<10010>b1, b2, f;

int W, B;
int cnt1;

void add(int a, int b)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt;
    cnt++;
}

int n, m;

void dfs(int x)
{
    if(vis[x]) W++; else B++;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(vis[t[k]] == -1)
    {
        vis[t[k]] = !vis[x];
        dfs(t[k]);
    }
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) ind[i] = -1;
        cnt1 = cnt = 0;
        for(int i = 0; i < m; i++)
        {
            int op, ed;
            scanf("%d%d", &op, &ed); add(op, ed); add(ed, op);
        }
        for(int i = 1; i <= n; i++) vis[i] = -1;
        for(int i = 1; i <= n; i++) if(vis[i] == -1)
        {
            W = B = 0;
            vis[i] = 0;
            dfs(i);
            a[cnt1] = W; b[cnt1] = B; cnt1++;
        }
        f.reset();
        f[0] = 1;
        for(int i = 0; i < cnt1; i++)
        {
            f = (f << a[i]) | (f << b[i]);
        }
        LL ans = 0;

        for(int i = 0; i <= f.size(); i++) if(f[i]) ans = max(ans, (LL)(n - i) * i);
        printf("%I64d\n", ans - m);
    }
    return 0;
}
