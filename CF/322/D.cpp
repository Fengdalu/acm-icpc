#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 1e12
#define N 20
#define LL long long

LL f[N][N];
LL dp[N][(1 << 19)];
LL c[N];
LL cc[N];
int n, m, K;

int main()
{
    while(true)
    {
        scanf("%d%d%d", &n, &m, &K);
        for(int i = 1; i <= n; i++) scanf("%I64d", &c[i]);
        for(int j = 0; j < (1 << (n + 1)); j++)
        {
            cc[j] = 0;
            for(int i = 1; i <= n; i++)
                if(((1 << i) & j) != 0)
                cc[j] += c[i];
        }
        memset(f, 0, sizeof f);
        for(int i = 0; i < K; i++)
        {
            LL x, y, z; scanf("%d%d%I64d", &x, &y, &z);
            f[x][y] = z;
        }

        for(int i = 1; i <= n; i++) for(int j = 0; j < 1 << (n + 1); j++) dp[i][j] = 0;
        dp[1][2] = 0;

        for(int j = 0; j < (1 << (n + 1)); j++)
        {
            for(int i = 1; i <= n; i++)
            if(((1 << i) & j) != 0)
            {
                for(int k = 1; k <= n; k++)
                if(((1 << k) & j) == 0)
                    dp[k][(1 << k) | j] = max(dp[i][j] + f[i][k], dp[k][(1 << k) | j]);
            }
        }

        LL ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < (1 << (n + 1)); j++)
            if((((1 << i) & j) != 0) && __builtin_popcount(j) == m)
            {
                cout << i << " " << j <<endl;
                ans = max(ans, dp[i][j] + cc[j]);
            }
        printf("%I64d\n", ans);
        break;
    }
    return 0;
}
