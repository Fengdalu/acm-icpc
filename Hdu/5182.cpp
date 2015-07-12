#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 2000
#define MOD 1000000007

int dp[N][N];
LL f[N][N];
int pos[N][N];
char a[N], b[N];
int tmp[N];

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%s%s", a, b);
        int n = strlen(a), m = strlen(b);
        memset(dp, 0, sizeof dp); memset(f, 0, sizeof f);
        memset(pos, 0, sizeof pos);
        memset(tmp, 0, sizeof tmp);

        for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(a[i - 1] == b[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }

        for(int i = 1; i <= m; i++) {
            tmp[b[i - 1] - 'a'] = i;
            for(int j = 0; j < 26; j++)
            {
                pos[i][j] = tmp[j];
            }
        }


        //cout << pos[2][1] << endl;
        //for(int i = 1; i <= m; i++) {for(int j = 0; j < 26; j++)
        //if(pos[i][j]) cout << ('a' + j) << ": " << pos[i][j] << " "; cout <<endl; }

        int mm = -1;
        for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++)
        {
            if(!dp[i][j]) { f[i][j] = 1; continue; }
            if(dp[i - 1][j] == dp[i][j]) f[i][j] = (f[i][j] + f[i - 1][j]) % MOD;
            int p = pos[j][a[i - 1] - 'a'];
            if(p != 0 && dp[i - 1][p - 1] + 1 == dp[i][j]) f[i][j] = (f[i][j] + f[i - 1][p - 1]) % MOD;
        }

        //for(int i = 1; i <= n; i++) {for(int j = 1; j <= m; j++)
        //cout << f[i][j] << " "; cout <<endl; }
        printf("%I64d\n", f[n][m]);
    }
    return 0;
}
