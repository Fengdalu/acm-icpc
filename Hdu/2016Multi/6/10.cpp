#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
ll dfs(ll p, ll q, ll b) {
    ll t = log2(p - q + 1);
    ll w = (1LL << t) - 1;
    ll g = (1LL << t);
    if(w == p - q) {
        return t + b;
    }
    ll target = max(0ll, p - w - g);
    return t + min(1ll * dfs(p - w, q, b + 1), max(b, q - target) + 1);
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        ll p, q; scanf("%lld%lld", &p, &q);
        if(q >= p) printf("%lld\n", q - p);
        else {
            int x = 1;
            ll tot = dfs(p, q, 0);
            printf("%lld\n", tot);
       }
    }
    return 0;
}
