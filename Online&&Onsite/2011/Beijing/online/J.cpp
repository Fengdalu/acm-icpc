#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 10
#define ONES(x) __builtin_popcount(x)

int B[N][N];
int V[N][N];
int P[N];
int frd[(1 << N)];
int Get[N][(1 << N)];
int dp[N][(1 << N)];
int n, m;

void init()
{
    memset(frd, 0, sizeof frd);
    memset(Get, 0, sizeof Get);
    for(int i = 0; i < n; i++) for(int j = 0; j < i; j++)
    for(int k = 0; k < (1 << n); k++) if((1 << i) & k) if((1 << j) & k) frd[k] += B[i][j];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < (1 << n); j++)
        {
            Get[i][j] = 0;
            for(int k = 0; k < n; k++)
            if((1 << k) & j) Get[i][j] += V[k][i];
        }
}

int dfs(int x, int m2)
{
    if(x == m) return 0;
    if(dp[x][m2] != -1) return dp[x][m2];
    int add = Get[x][m2] + frd[m2] - ONES(m2) * P[x];

    int ans = -1e8;
    for(int i = 0; i < (1 << n); i++)
    if((i & (m2)) == i)
    {
        ans = max(ans, dfs(x + 1, i));
    }

    dp[x][m2] = ans + add;
    dp[x][m2] = max(dp[x][m2], 0);
    return dp[x][m2];
}

int main()
{
    //freopen("J.txt", "r", stdin);
    while(~scanf("%d%d", &n, &m))
    {
        if(n == 0 && m == 0) break;
        for(int i = 0; i < m; i++) scanf("%d", &P[i]);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &V[i][j]);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", &B[i][j]);
        init();
        int ans = 0;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < (1 << n); i++) ans = max(ans, dfs(0, i));
        if(ans == 0) printf("STAY HOME\n");
        else printf("%d\n", ans);
    }
    return 0;
}