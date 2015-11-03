#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 16

LL dp[N][1 << N][N];
LL pp[N];
char s[2 * N];
LL b, K;
int n;

LL cas(int x, int mask, int mod)
{
    if(x == -1) return 0;
    if(dp[x][mask][mod] != -1) return dp[x][mask][mod];

    dp[x][mask][mod] = 0;
    for(int i = 0; i < n; i++)
    if(mask & (1 << i))
    {
        if()
    }
}

int main()
{
   int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d%d", &b, &K);
        scanf("%s", s);
        int n = strlen(s);
        memset(dp, -1, sizeof dp);
        pp[0] = 1;
        for(int i = 0; i <= n; i++) pp[i] = pp[i - 1] * (LL)b;
        printf( "Case %d: %d\n", CAS, cal(n - 1, (1 << n) - 1, 0) );
    }
    return 0;
}
