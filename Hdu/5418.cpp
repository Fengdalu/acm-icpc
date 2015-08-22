#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f
#define N 100

int f[N][N];
int dp[N][(1 << 18)];
int n, m;

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j] = INF;
        for(int i = 1; i <= n; i++) f[i][i] = 0;
        for(int i = 0; i < m; i++)
        {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            f[x][y] = min(f[x][y], z);
            f[y][x] = min(f[y][x], z);
        }
        for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++)
            f[i][j] = min(f[i][k] + f[k][j], f[i][j]);

        for(int i = 1; i <= n; i++) for(int j = 0; j < 1 << (n + 1); j++) dp[i][j] = INF;
        dp[1][2] = 0;

        for(int j = 0; j < (1 << (n + 1)); j++)
        {
            for(int i = 1; i <= n; i++)
            if(((1 << i) & j) != 0)
            {
                for(int k = 1; k <= n; k++)
                    dp[k][(1 << k) | j] = min(dp[i][j] + f[i][k], dp[k][(1 << k) | j]);
            }
        }
        int ans = INF;
        for(int i = 1; i <= n; i++) { ans = min(ans, dp[i][(1 << (n + 1)) - 2] + f[i][1]); }
        printf("%d\n", ans);
    }
    return 0;
}
