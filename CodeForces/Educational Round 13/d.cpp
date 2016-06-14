#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll qpow(ll x, ll p) {
    ll ans = 1;
    while(p) {
        if(p & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return ans;
}

ll cal(ll a, ll b) {
    ll ans = 0;
    while(b) {
       if(b & 1LL) ans = (ans + a) % mod;
        a <<= 1;
        if(a >= mod) a %= mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll a, b, n, x;
    cin >> a >> b >> n >> x;
    if(a == 1) {
        cout << (cal(b, n) % mod + x) % mod;
    }
    else {
        ll a0 = (a * x % mod + b) % mod;
        if(n == 1) cout << a0;
        else {
            ll ans = qpow(a, n) * (x + b * qpow(a - 1, mod - 2) % mod) % mod - b * qpow(a - 1, mod - 2) % mod;
            ans = (ans % mod + mod) % mod;
            cout << ans << endl;
        }
    }
    return 0;
}
