#include <bits/stdc++.h>

typedef long long ll;
int r[1000100];
int c[1000100];
inline void solve() {
    static char buf[10];
    int n, q;
    ll rt = 0, ct = 0;
    ll rr = 0, cc = 0;
    scanf("%d%d", &n, &q);
    while(q--) {
        int x;
        scanf("%s%d", buf, &x);
        if(buf[0] == 'R') {
            if(r[x]) { printf("0\n"); continue; }
            ll ans = 1ll * (1 + n) * (n) / 2 + x * n - rt - rr * x;
            ct += x;
            printf("%lld\n", ans);
            r[x] = true;
            cc++;
        }
        if(buf[0] == 'C') {
            if(c[x]) { printf("0\n"); continue; }
            ll ans = 1ll * (1 + n) * (n) / 2 + x * n - ct - cc * x;
            rt += x;
            printf("%lld\n", ans);
            c[x] = true;
            rr++;
        }
    }
}

int main() {
    freopen("adjustment.in", "r", stdin);
    freopen("adjustment.out", "w", stdout);
    solve(); return 0;
}
