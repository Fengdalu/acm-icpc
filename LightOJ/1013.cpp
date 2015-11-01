#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 50
LL f1[N][N], f2[N][N][N + N];
char a[N + 10], b[N + 10];
int n, m;

int main()
{
//    freopen("1013.in", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%s%s", a + 1, b + 1);
        n = strlen(a + 1); m = strlen(b + 1);
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                f1[i][j] = max(max(f1[i - 1][j], f1[i][j - 1]), f1[i - 1][j - 1] + (a[i] == b[j] ? 1 : 0));
            }

        for(int i = 0; i <= n; i++) f2[i][0][i] = 1;
        for(int i = 0; i <= m; i++) f2[0][i][i] = 1;

        for(int k = 1; k <= n + m; k++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                {
                    f2[i][j][k] = f2[i - 1][j][k - 1] + f2[i][j - 1][k - 1];
                    if(a[i] == b[j]) f2[i][j][k] = f2[i - 1][j - 1][k - 1];
                }
        LL ans1 = n + m - f1[n][m];
        LL ans2 = f2[n][m][ans1];
        printf("Case %d: %lld %lld\n", CAS, ans1, ans2);
    }
    return 0;
}

