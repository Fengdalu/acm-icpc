#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 4500
#define LL long long
#define MOD 1000000007

LL f[N][N];
LL s[N];
LL ans[N];
LL pp[N];

LL c[N], inv[N];


void iii()
{
    pp[0] = 1;
    for(int i = 1; i < N; i++) { pp[i] = pp[i - 1] * 2LL; if(pp[i] >= MOD) pp[i] %= MOD; }
    c[1] = 1;
    for(int i = 2; i < N; i++) c[i] = (c[i - 1] * i) % MOD;
    inv[0] = 1;
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    for(int i = 2; i < N; i++) inv[i] = (inv[i] * inv[i - 1]) % MOD;
}

LL C(int n, int m)
{
    if(m == 0) return 1;
    return (c[n] * inv[n - m]) % MOD * inv[m] % MOD;
}

LL qpow(LL k)
{
    return pp[k];
}


void init()
{
    memset(f, 0, sizeof f);
    f[1][0] = 1;
    f[1][1] = 1;
    for(int i = 2; i < N; i++)
    {
        f[i][0] = 1;
        f[i][1] = 1;
        for(int j = 2; j <= i; j++)
        {
            f[i][j] = f[i - 1][j] * j + f[i - 1][j - 1];
            if(f[i][j] >= MOD) f[i][j] %= MOD;
        }
    }


    memset(s, 0, sizeof s);
    for(int i = 1; i < N; i++)
        for(int j = 1; j <= i; j++)
        {
            s[i] += f[i][j];
            if(s[i] >= MOD) s[i] %= MOD;
        }

    s[0] = 1;
    for(int i = 1; i < N; i++)
        for(int j = 1; j <= i; j++)
        {
            ans[i] += C(i, j) * s[i - j];
            if(ans[i] >= MOD) ans[i] %= MOD;
        }

}


int main()
{
    iii();
    init();
//    cout << s[0] * C(6, 6) << endl;
    int n; scanf("%d", &n);
    printf("%I64d\n", ans[n]);
    return 0;
}
