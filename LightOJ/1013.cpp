#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 31
LL f1[N][N], f2[N][N][N + N];
char a[N + 10], b[N + 10];
int n, m;

int main()
{
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        a[0] = ' ';
        b[0] = ' ';
        scanf("%s%s", a + 1, b + 1);
        n = strlen(a); m = strlen(b);
        n--; m--;
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 && j == 0) f1[i][j] = 0;
                else if(i == 0) f1[i][j] = f1[i][j - 1];
                else if(j == 0) f1[i][j] = f1[i - 1][j];
                else if(a[i] != b[j]) f1[i][j] = max(f1[i - 1][j], f1[i][j - 1]);
                else f1[i][j] = max(1 + f1[i - 1][j - 1], max(f1[i - 1][j], f1[i][j - 1]));
            }

        for(int k = 0; k <= n + m; k++)
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= m; j++)
                        if(i + j < k) f2[i][j][k] = 0;
                        else if(i == 0 || j == 0) f2[i][j][k] = 1;
                        else
                        {
                            if(a[i] != b[j]) f2[i][j][k] = (f2[i - 1][j][k - 1] + f2[i][j - 1][k - 1]);
                            else f2[i][j][k] = f2[i - 1][j - 1][k - 1];
                        }
        int ans1 = n + m - f1[n][m];
        int ans2 = f2[n][m][ans1];
        printf("Case %d: %d %d\n", CAS, ans1, ans2);
    }
}

