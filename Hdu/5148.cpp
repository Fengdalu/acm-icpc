#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 3000
#define M 6000
#define LL long long

const long long INF = 200000 * 10000000LL;

using namespace std;

LL f[N][55];
int ind[N];
int t[M], nt[M];
LL c[M];
int cnt;
int T, n, K;

void add(int a, int b, LL cc)
{
    cnt++;
    t[cnt] = b;
    c[cnt] = cc;
    nt[cnt] = ind[a];
    ind[a] = cnt;
}


LL find(int x, int pre)
{
    for(int k = ind[x]; k != -1; k = nt[k])
    {
        if(t[k] == pre) continue;
        find(t[k], x);
        int v = t[k];
        for(int i = K; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
                f[x][i] = min(f[x][i], f[x][i - j] + f[v][j] + (j) * (K - j) * c[k] * 2);
        }
    }
    return f[x][K];
}

int main()
{
   scanf("%d", &T);
   for(int ii = 0; ii < T; ii++)
   {
        scanf("%d%d", &n, &K);
        for(int i = 1; i <= n; i++) ind[i] = -1;
        cnt = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
        }
        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= K; j++)
                f[i][j] = INF;
       for(int i = 1; i <= n; i++) f[i][0] = f[i][1] = 0;
       printf("%I64d\n", find(1, -1));
   }
   return 0;
}
