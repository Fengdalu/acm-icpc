#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100010;

int dp[N];
int n, m;

int main()
{
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d%d", &n, &m);
        int sum = 0;
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++)
        {
            int t; scanf("%d", &t);
            sum += t;
            sum %= m;
            dp[sum]++;
        }
        LL ans = 0;
        for(int i = 0; i < m; i++) ans += (LL)(dp[i] - 1) * (LL)dp[i] / 2;
        printf("Case %d: %lld\n", CAS, ans + dp[0]);
    }
    return 0;
}
