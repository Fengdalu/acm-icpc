#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long

int n;
int dp[16][1 << 16];
int c[20][20];
int cal(int p, int m)
{
    if(p == -1) return 0;
    if(dp[p][m] != -1) return dp[p][m];
    for(int i = 0; i < n; i++)
    if(m & (1 << i))
        dp[p][m] = max(dp[p][m], cal(p - 1, m - (1 << i)) + c[p][i]);
    return dp[p][m];
}

int main()
{
    int T; scanf("%d", &T);
    for(int ii = 1; ii <= T; ii++)
    {
        scanf("%d", &n);
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", &c[i][j]);
        printf("Case %d: %d\n", ii, cal(n - 1, (1 << n) - 1));
    }
    return 0;
}
