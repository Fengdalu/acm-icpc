#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
typedef long long ll;
ll dp[70][70][70];
const ll mod = 1e9 + 7;
ll two[10000];
ll tri[1000][1000];
ll fact[1000];

ll qpow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

int main() {
    two[0] = 1;
    for(int i = 1; i < 10000; i++)  two[i] = two[i - 1] * 2ll % mod;
    tri[0][0] = 1;
    fact[0] = 1;
    for(int i = 1; i < 1000; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
    for(int i = 1; i < 1000; i++) {
        tri[i][0] = 1;
        for(int j = 1; j < 1000; j++) tri[i][j] = (tri[i - 1][j] + tri[i - 1][j - 1]) % mod;
        tri[i][i] = 1;
    }
    dp[0][1][1] = 1;
    for(int i = 1; i < 70; i++)
        for(int j = i + 1; j < 70; j++)
            for(int k = 1; k <= j - i; k++) {
                for(int p = 1; p + k <= j - i + 2; p++) {
                    dp[i][j][k] += dp[i - 1][j - k][p] * qpow(fact[k], mod - 2) % mod * qpow(two[p] - 1 + mod, k) % mod  * (two[k * (k - 1) / 2]) % mod;
                    dp[i][j][k] %= mod;
                }
            }
    int _T;
    scanf("%d", &_T);
    while(_T--) {
        int n, k; scanf("%d%d", &n, &k);
        ll ans = 0;
        for(int i = 0; i < k; i++)
            for(int j = 1; j <= n; j++)
                for(int k = 0; k < 70; k++) {
                    int t = n - j;
                    ans += fact[j - 1] * tri[n - 1][j - 1] % mod * dp[i][j][k] % mod * two[t * (t - 1) / 2] % mod;
                    ll q = fact[j - 1] * tri[n - 1][j - 1] % mod * dp[i][j][k] % mod * two[t * (t - 1) / 2] % mod;
                    ans %= mod;
                }
        cout << ans << endl;
    }
    return 0;
}
