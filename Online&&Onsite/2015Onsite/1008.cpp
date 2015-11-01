#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 3015
#define LL long long

const LL INF = 1e9 + 7;
LL dp[N];
LL dpp[N];
LL v[N], c[N];
LL f[N];
int n;

int main()
{
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n - 1; i++) scanf("%d", &f[i]);

        for(int i = 1; i < n - 1; i++)
        {
            v[i] = i;
            c[i] = f[i + 1] - f[1];
        }
        for(int i = 0; i <= n; i++) dp[i] = -INF;
        dp[0] = 0;
        for(int i = 1; i < n - 1; i++)
            for(int j = v[i]; j <= n; j++)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + c[i]);
            }

        LL ans = 0;
        for(int i = 1; i <= n - 1; i++)
        {
            ans = max(ans, f[i] + (i) * f[1] + dp[n - i - 1] + (n - i - 1) * f[1]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}