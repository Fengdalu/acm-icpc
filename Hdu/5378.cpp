#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>
using namespace std;
#define N 1010
#define PB(x) push_back(x)
#define MOD 1000000007
#define LL long long
int ind[N], sz[N], fa[N];
LL dp[N][N];

LL inv[N];
LL fac[N];

vector<int>G[N];
int n, k;

int dfs(int x)
{
    sz[x] = 1;
    for(int k = 0; k < G[x].size(); k++) fa[G[x][k]] = x;
    for(int k = 0; k < G[x].size(); k++) if(G[x][k] != fa[x]) sz[x] += dfs(G[x][k]);
    return sz[x];
}

int main()
{
//    freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    fac[1] = 1;
    for(int i = 2; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    for(int ii = 1; ii <= T; ii++)
    {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 0; i < n - 1; i++)
        {
            int x, y; scanf("%d%d", &x, &y);
            G[x].PB(y); G[y].PB(x);
        }
        memset(sz, 0, sizeof sz);
        for(int i = 1; i <= n; i++) fa[i] = -1;
        assert(n == dfs(1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= i; j++)
            {
                dp[i][j] = 0;
                if(j) dp[i][j] += inv[sz[i]] * dp[i - 1][j - 1] % MOD;
                dp[i][j] += (sz[i] - 1) * inv[sz[i]] % MOD * dp[i - 1][j] % MOD;
            }
        printf("Case #%d: %I64d\n", ii, dp[n][k] * fac[n] % MOD);
    }
    return 0;
}
