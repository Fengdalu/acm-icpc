/*
 *
 * 求出n!分解中，素因子x的个数
 */

typedef long long ll;
ll lrd(ll n, ll x) {
    ll ans = 0;
    for(ll k = x; k <= n; k *= x) {
        ans += n / k;
    }
    return ans;
}
