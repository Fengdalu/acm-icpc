#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define LL long long
#define N 200000
#define INF 1e30

int ind[N];
int t[2 * N], nt[2 * N];
int c[N];
LL pp[N];
int fa[N];
int cnt;

void init()
{
    pp[0] = 1;
    pp[1] = 1;
    for(LL i = 2; i < N; i++) pp[i] = (pp[i - 1] * i) % MOD;
}

void add(int a, int b)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt;
    cnt++;
}
int n;
int x, y;

int dfs1(int x)
{
    c[x] = 1;

    for(int k = ind[x]; k != -1; k = nt[k]) if(t[k] != fa[x]) fa[t[k]] = x;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(t[k] != fa[x])
        c[x] += dfs1(t[k]);
    return c[x];
}

LL dfs(int x)
{
    int p1 = -1, p2 = -1;
    int cc = c[x] - 1;

    for(int k = ind[x]; k != -1; k = nt[k]) if(t[k] != fa[x])
    if(c[t[k]] > 1)
    {
        if(p1 == -1) p1 = t[k];
        else if(p2 == -1) p2 = t[k];
        else return 0;
    }

    LL ans;
    if(p1 == -1 && p2 == -1) ans = pp[cc] % MOD;
    else if(p2 == -1) ans = 2LL * (pp[cc - c[p1]]) % MOD * dfs(p1) % MOD;
    else ans = 2LL * (pp[cc - c[p1] - c[p2]]) % MOD * dfs(p1) % MOD * dfs(p2) % MOD;
//    cout << x << " " << cc << " " << p1 << " " << p2 << " " << ans << endl;
    return ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    init();
    int CASE; scanf("%d", &CASE);
    for(int T = 1; T <= CASE; T++)
    {
        scanf("%d", &n);
        if(n == 1) { printf("Case #%d: 1\n", T); continue; }
        memset(ind, -1, sizeof ind);
        cnt = 0;
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        fa[1] = -1;
        dfs1(1);
//        for(int i = 1; i <= n; i++) cout << c[i] << " "; cout << endl;
        printf("Case #%d: %I64d\n", T, dfs(1) * 2LL % MOD);
    }
    return 0;
}
