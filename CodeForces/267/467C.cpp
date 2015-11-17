#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
LL c[5010];
LL sum[5010];
LL dp[5010][5010];
int n, m, k;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) scanf("%I64d", &c[i]);
    memset(dp, 0, sizeof dp);
    memset(sum, 0, sizeof sum);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + c[i];
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        for(int j = 1; j <= k; j++)
        {
            if(i + 1 - m > 0) cmax(dp[i][j], dp[i - m][j - 1] + sum[i] - sum[i - m] );
            cmax(dp[i][j], dp[i - 1][j]);
        }
    }
    LL ans = 0;
    //for(int i = 1; i <= n; i++) cout << c[i] << " "; cout << endl;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= k; j++) cmax(ans, dp[i][j]);
    //for(int i = 1; i <= n; i++) { for(int j = 0; j <= k; j++) cout << dp[i][j] << " "; cout << endl; }

    printf("%I64d\n", ans);
    return 0;
}
