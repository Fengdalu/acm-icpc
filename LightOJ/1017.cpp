#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 120
int dp[N][N];
int n, w, k;
int y[N];
int c[N];

int main()
{
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d%d%d", &n, &w, &k);
        for(int i = 1; i <= n; i++)
        {
            int x; scanf("%d%d", &x, &y[i]);
        }
        sort(y + 1, y + n + 1);
        for(int i = 1; i <= n; i++)
            c[i] = (y + i + 1) - lower_bound(y + 1, y + i + 1, y[i] - w);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - c[i]][j - 1] + c[i]);
        }
        printf("Case %d: %d\n", CAS, dp[n][k]);
    }
    return 0;
}
