#include <bits/stdc++.h>

typedef long long ll;
ll c[10000], w[10000];
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll qpow(ll x, ll y) {
    ll t = 1;
    while(y) {
        if(y & 1) t *= x;
        x *= x;
        y >>= 1;
    }
    return t;
}

const int N = 100100;
int vis[N];
int p[N];
ll sqr(ll x) { return x * x; }
int main() {
    int cnt = 0;
    for(int i = 2; i < N; i++) {
        if(!vis[i]) p[cnt++] = i;
        for(int j = 0; j < cnt && p[j] * i < N; j++)
            vis[p[j] * i] = true;
    }
    int n;
    scanf("%d", &n);
    ll st = 2;
    for(ll k = 1; k <= n; k++) {
        ll nxt = sqr(k + 1);
        ll left = k / gcd(sqr(k + 1), k);
        ll tot = 1;
        ll add = 1;
        for(ll j = cnt; j < cnt && p[j] <= left; j++) if(left % p[j] == 0) {
            int cc = 0;
            while(left % p[j] == 0) {
                left /= j;
                cc++;
            }
            if(cc & 1) tot *= j;
            add *= j;
        }
        if(left) tot *= left;
        add *= left;
        tot *= sqr(k + 1) / gcd(sqr(k + 1), k);
        printf("%lld\n", (tot - st / k));
        //std::cout << nxt << std::endl;
        //std::cout << add << std::endl;
        //st = sqrt(tot * k);
        st = (k + 1) * add;
    }
    return 0;
}
