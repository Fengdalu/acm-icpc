#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define AA first
#define BB second
typedef long long LL;
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define MEM(a) memset(a, 0, sizeof a)

LL a, MOD;

LL mul(LL a, LL b)
{
    LL ans = 0;
    while(b)
    {
        if(b & 1) ans += a;
        if(ans >= MOD) ans -= MOD;
        a <<= 1;
        if(a >= MOD) a -= MOD;
        b >>= 1;
    }
    return ans;
}
LL pow(LL a, LL b) 
{
    LL ans = 1;
    while(b)
    {
        if(b & 1) ans = mul(ans, a);
        if(ans >= MOD) ans -= MOD;
        a = mul(a, a); if(a >= MOD) a -= MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> a >> MOD)
    {
        LL p = -2;
	if(a == 1) { cout << 1 % MOD << endl; continue; }
        while(p < 0) p += MOD;
        cout << (pow(2LL, a) + p) % MOD << endl;
    }
    return 0;
}

