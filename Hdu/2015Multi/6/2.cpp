#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MP make_pair
#define AA first
#define BB second

typedef long long ll;
const long long mod=110119;
long long inv[mod];
long long fac[mod];
long long ifac[mod];
void init()
{
    inv[0]=fac[0]=ifac[0]=1;
    inv[1]=fac[1]=ifac[1]=1;
    for(int i=2;i<mod;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        ifac[i]=ifac[i-1]*inv[i]%mod;
    }
}
long long C(long long n,long long m)
{
    if(m>n)return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
long long lucas(long long n,long long m)
{
    if(m>n)return 0;
    if(n==0)return 1;
    return lucas(n/mod,m/mod)*C(n%mod,m%mod)%mod;
}

pair<ll, ll> p[200];
ll dp[200];

bool check(ll n, ll m) {
    if(2ll * n - m < 0) return false;
    if(2ll * m - n < 0) return false;
    if((2ll * n - m) % 3 != 0) return false;
    if((2ll * m - n) % 3 != 0) return false;
    return true;
}

pair<ll, ll> cal(ll n, ll m) {
    return pair<ll, ll>((2ll * n - m) / 3, (2ll * m - n) / 3);
}

ll tri(ll n, ll m) {
    return lucas(n, m);
}
pair<ll, ll> q[200];

int main() {
    init();
    ll n, m, r;
    int cas = 1;
    while(~scanf("%lld%lld%lld", &n, &m, &r)) {
        n--; m--;
        int cnt = 0;
        for(int i = 0; i < r; i++) {
            ll x, y; scanf("%lld%lld", &x, &y);
            x--; y--;
            if(!check(x, y)) continue;
            q[cnt++] = cal(x, y);
        }
        if(!check(n, m)) { cout << "Case #" << cas++ << ": 0" << endl; continue; }
        auto p = cal(n, m);
        n = p.AA; m = p.BB;
        q[cnt++] = MP(n, m);
        sort(q, q + cnt);
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < cnt; i++) {
            dp[i] = tri(q[i].AA + q[i].BB, q[i].BB);
            for(int j = 0; j < i; j++) {
                if(q[j].BB > q[i].BB) continue;
                dp[i] -= dp[j] * tri(q[i].AA - q[j].AA + q[i].BB - q[j].BB
                        , q[i].BB - q[j].BB) % mod;
                dp[i] = (dp[i]) % mod;
                dp[i] = (dp[i] + mod) % mod;
            }
        }
        cout << "Case #" << cas++ << ": " << dp[cnt - 1] % mod << endl;
    }
    return 0;
}
