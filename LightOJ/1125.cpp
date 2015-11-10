#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 25;

LL ans[N][202][N];
LL f[202][N];
LL g[202][N];
LL a[202];
LL b[202];
int n, Q;

void cal(LL mod)
{
    for(int i = 0; i < n; i++) a[i]= (b[i] % mod + mod) % mod;
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    f[0][0] = 1;

    for(int i = 0; i < n; i++)
    {
        swap(f, g);
        for(int j = 0; j <= n; j++)
           for(int k = 0; k < mod; k++)
                f[j][k] = 0;

        for(int j = 0; j <= n; j++)
           for(int k = 0; k < mod; k++)
                f[j][k] += g[j][k];
        //f[0][0] = 1;
        for(int j = 0; j <= n; j++)
           for(int k = 0; k < mod; k++)
           {
               f[j + 1][(k + a[i]) % mod] += g[j][k];
           }
    }
}


int main()
{
    //freopen("input.in", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int _C = 1; _C <= _T; _C++)
    {
        scanf("%d%d", &n, &Q);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &b[i]);
        }

        for(int i = 1; i <= 20; i++)
        {
            cal(i);
            for(int j = 0; j <= n; j++)
               for(int k = 0; k < i; k++)
                    ans[i][j][k] = f[j][k];
        }
        printf("Case %d:\n", _C);
        while(Q--)
        {
            int D, M; scanf("%d%d", &D, &M);
            printf("%lld\n", ans[D][M][0]);
        }
    }
    return 0;
}
