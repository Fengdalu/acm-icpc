#include <cstdio>
#include <cstring>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
ll dp[10010];
ll fact[100010];

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

void update(ll &a, ll b) {
    a = (a + b) % mod;
}

ll inv(ll a) {
    return qpow(a, mod - 2);
}

ll tri(ll a, ll b) {
    if(b < a) return 0;
    return fact[a] * inv(fact[a - b]) * inv(b);
}



int main() {
    fact[0] = 1;
    for(int i = 1; i < 10010; i++) fact[i] = (fact[i - 1] * i) % mod;
    dp[1] = 1;
    dp[0] = 1;
    for(ll i = 2; i <= 100; i++) {
        for(ll j = 1; j < i; j++)
            update(dp[i], );
    }
    for(int i = 0; i < 10; i++) cout << dp[i] * fact[i] % mod << " "; cout << endl;
    cout << "ed" << endl;
    int _T; scanf("%d", &_T);
    while(_T) {
        int n, x; scanf("%d%d", &n, &x);
        cout << qpow(dp[n] * fact[n] % mod, x) << endl;
    }
    return 0;
}
