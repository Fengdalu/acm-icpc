#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 15;


LL c[N][N];
LL dp[1 << N];
LL add[N][1 << N];
int n;

void init()
{
    memset(add, 0, sizeof add);
    for(int i = 0; i < n; i++)
    {

        for(int j = 0; j < (1 << n); j++)
        {
            add[i][j] += c[i][i];
            for(int k = 0; k < n; k++)
            if(k != i)
            if(j & (1 << k))
            {
                add[i][j] += c[i][k];
            }
        }
    }
    //for(int i = 0; i < n; i++) { for(int j = 0; j < (1 << n); j++) cout << add[i][j] << " "; cout << endl; }
}

LL cal(int x)
{
    if(x == 0) return 0;
    if(dp[x] != -1) return dp[x];
    for(int i = 0; i < n; i++)
    if(x & (1 << i))
    {
        LL tmp = cal(x - (1 << i)) + add[i][x - (1 << i)];
        if(dp[x] == -1) dp[x] = tmp;
        dp[x] = min(dp[x], tmp);
    }
    return dp[x];
}

int main()
{
    //freopen("input.in", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int _C = 1; _C <= _T; _C++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%lld", &c[i][j]);
        init();
        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n", _C ,cal((1 << n) - 1));
    }
}
