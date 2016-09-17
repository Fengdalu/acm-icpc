#include <bits/stdc++.h>

typedef long long ll;
int mpow(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}

ll q[1000000];
int main() {
    int cnt = 0;
    ll limit = 1e9+1;
    for(int i = 0; i < 31; i++) {
        ll a = mpow(2, i);
        for(int j = 0; j < 30; j++) {
            ll b = a * mpow(3, j);
            if(b > limit) break;
            for(int k = 0; k < 31; k++) {
                ll c = b * mpow(5, k);
                if(c > limit) break;
                for(int p = 0; p < 31; p++) {
                    ll d = c * mpow(7, p);
                    if(d > limit) break;
                    q[cnt++] = d;
                }
            }
        }
    }

    std::sort(q, q + cnt);
    int _t; scanf("%d", &_t);
    while(_t--) {
        int x; scanf("%d", &x);
        printf("%d\n", (int)*std::lower_bound(q, q + cnt, x));
    }
    return 0;
}
