#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
LL aa[59][59];
LL a[59][59];
LL dp[59][59];
int main()
{
    int _T;
    scanf("%d", &_T);
    int n,m;
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        LL ans = 99999999999999999LL;
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%I64d",&aa[i][j]);
        int N = n + m - 1;
        for(LL l = 0; l <= N * 30; l++)
        {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    a[i][j] = N * aa[i][j] - l;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    a[i][j] *= a[i][j];
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                {
                    if(i == 0)
                    {
                        if(j == 0) dp[i][j] = a[i][j];
                        else dp[i][j] = dp[i][j - 1] + a[i][j];
                    }
                    else if(j == 0) dp[i][j] = dp[i - 1][j] + a[i][j];
                    else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
                }
            ans = min(ans, dp[n - 1][m - 1]);
        }

        printf("Case #%d: %I64d\n",CAS,ans / N);
    }
    return 0;
}