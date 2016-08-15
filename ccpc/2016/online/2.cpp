#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;

typedef long long ll;
const int N = 2010;
int vis[N], prime[N], cnt, n;
bitset<400> a[500];
const ll mod = 1e9 + 7;

void init() {
    cnt = 0;
    for(int i = 2; i < N; i++) {
        if(!vis[i]) prime[cnt++] = i;
        for(int j = 0; i * prime[j] < N && j < cnt; j++) {
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
int gauss(int eq, int var) {
    int line = 0, ret = 0;
    for(int i = 0; i < var; i++) {
        int target = line;
        while(target < eq && a[target][i] == 0) target++;
        if(target == eq) { ret++; continue; }
        swap(a[target], a[line]);
        for(int j = 0; j < eq; j++) if(j != line && a[j][i]) a[j] ^= a[line];
        line++;
    }
    return ret;
}

ll qpow(ll a, ll b) {
    ll _ = 1;
    while(b) {
        if(b & 1) _ = (_ * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return _;
}

int main() {
    init(); int cas = 1;
    int _T; scanf("%d", &_T);
    while(_T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            ll x; scanf("%lld", &x);
            for(int j = 0; j < cnt; j++) {
                int flag = false;
                ll t = x, k = prime[j]; while(t % k == 0) flag ^= 1, t /= k;
                a[j][i] = flag;
            }
        }
        printf("Case #%d:\n%lld\n", cas++, (qpow(2ll, gauss(cnt, n)) - 1 + mod) % mod);
    }
    return 0;
}
