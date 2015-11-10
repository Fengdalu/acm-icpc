#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

LL dp[500000];
int n;

int main()
{
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d", &n);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            int x; scanf("%d", &x);
            sum += x;
            for(int j = 100000; j >= x; j--) dp[j] |= (dp[j - x] << 1);
        }
        int cnt = (sum) / 2;
        int m = (n + 1) / 2, m1 = (n) / 2;
        for(int i = cnt; i > 0; i--)
        {
            bool flg = false;
            if((1LL << m) & dp[i]) flg = true;
            if((1LL << m1) & dp[i]) flg = true;
            if(flg) { printf("Case %d: %d %d\n", CAS, min(i, sum - i), max(i, sum - i)); break; }
        }
    }
    return 0;
}
