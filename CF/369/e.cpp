#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e6 + 3;

ll qpow(ll a, ll b) {
    ll tot = 1;
    while(b) {
        if(b & 1) tot = (tot * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return tot;
}

ll inv(ll a) {
    return qpow(a, mod - 2);
}

ll lrd(ll n) {
    ll ans = 0;
    for(ll k = 2; k <= n; k *= 2) {
        ans += n / k;
    }
    return ans;
}

int main() {
    // 1000002
    ll n, k;
    cin >> n >> k;
    if(n <= 63 && 1LL << n < k) {
        puts("1 1\n");
        return 0;
    }
    ll A = 1, B = 1;
    if(k > mod) A = 0;
    else {
        for(int i = 1; i < k; i++) {
            ll t = (qpow(2, n) - i + mod) % mod;
            A = A * t % mod;
        }
    }
    ll g = lrd(k - 1);
    g = qpow(2, g);
    A = (A * inv(g)) % mod;
    B = qpow(2, n % 1000002 * ((k - 1) % 1000002) % 1000002);
    B = (B * inv(g)) % mod;
    A = (B - A + mod) % mod;
    cout << A << " " << B << endl;
    return 0;
}
