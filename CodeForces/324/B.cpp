#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define PB(x) push_back(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define u32 unsigned int
#define MOD 1000000007

LL qpow(LL x, LL p)
{
    LL ans = 1LL;
    while(p)
    {
        if(p & 1) ans *= x;
        p /= 2; x *= x;
        ans %= MOD; x %= MOD;
    }
    return ans;
}

int main()
{
    LL n; cin >> n;
    cout << ((qpow(27LL, n) - qpow(7LL, n)) % MOD + MOD) % MOD;
}
