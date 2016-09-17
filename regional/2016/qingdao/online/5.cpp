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
    int _t; scanf("%d", &_t);
    while(_t--) {
        int x; scanf("%d", &x);
        if(x & 1) puts("Balanced");
        else puts("Bad");
    }
    return 0;
}

