#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define N 2000
#define LL long long
#define MOD 1000000007

LL inv[N], num[N];

void init()
{
    num[0] = num[1] = 1LL;
    for(int i = 2; i < N; i++) num[i] = (num[i - 1] * (LL)i) % MOD;
    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = ((LL)(MOD - MOD / i) * inv[MOD % i]) % MOD;
    for(int i = 2; i < N; i++) inv[i] = (inv[i - 1] * inv[i]) % MOD;
}

LL C(int n, int k)
{
    return ((((LL)num[n] * inv[n - k]) % MOD) * inv[k]) % MOD;
}

int main()
{
    init();
    int s = 0, c, n; scanf("%d", &n);
    LL f = 1;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &c); s += c;
        f = (f * C(s - 1, c - 1)) % MOD;
    }
    printf("%I64d\n", f);
    return 0;
}
