#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define LL long long
#define N 200
#define MOD 1000000007
LL p[N];

void init()
{
    p[0] = 1;
    for(int i = 1; i < N; i++) p[i] = (p[i - 1] * (LL)i) % MOD;
}

LL qpow(LL x, LL k)
{
    LL ans = 1;
    while(k)
    {
        if(k & 1) ans *= x;
        x *= x; k /= 2;
        ans %= MOD;
        x %= MOD;
    }
    return ans;
}

int f[200][200];
bool vis[200];
int c1[200], c2[200];

int main()
{
//    freopen("input.txt", "r", stdin);
    int n, m;
    init();
    while(~scanf("%d%d", &n, &m))
    {
        LL cnt = 0;
        bool flg = false;
        bool flg1 = false;
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &f[i][1]);
            if(f[i][1] != -1) for(int j = 2; j <= n; j++) scanf("%d", &f[i][j]);
            if(f[i][1] != -1)
            {
                memset(vis, 0, sizeof vis);
                for(int j = 1; j <= n; j++)
                if(vis[f[i][j]]) { flg1 = true; }
                else vis[f[i][j]] = true;
            }
            else { cnt++; flg = true; }
        }
        if(flg1) { printf("0\n"); continue; }
        if(flg) printf("%I64d\n", qpow(p[n], cnt - 1));
        else
        {
            for(int i = 1; i <= n; i++) c1[i] = i;
            for(int i = 1; i <= n; i++) c2[i] = i;
            for(int i = m - 1; i >= 0; i--)
            {
                swap(c1, c2);
                for(int j = 1; j <= n; j++)
                {
                    c1[j] = f[i][c2[j]];
                }
            //    for(int i = 1; i <= n; i++) cout << c1[i] << " "; cout << endl;
            }
            bool flg = true;
            for(int i = 1; i <= n; i++) if(c1[i] != i) { flg = false; }
            if(flg) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}

