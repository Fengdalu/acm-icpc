#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007LL
#define LL long long

LL pow(LL a, LL b)
{
    LL ans = 1LL;
    while(b)
    {
        if(b & 1LL) ans *= a;
        a *= a;
        ans %= MOD;
        a %= MOD;
        b >>= 1LL;
    }
    return ans;
}

int main()
{
    int T; LL n; scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d", &n);
        LL a = n / 2;
        LL b = n - a;
        LL ans = pow(2, a) * pow(2, b - 1) + MOD - 1;
        ans = ans % MOD;
        printf("%I64d\n", ans);
    }
    return 0;
}
