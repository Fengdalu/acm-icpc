#include <bits/stdc++.h>

#define mp std::make_pair
#define pii std::pair<int, int>

typedef long long ll;
std::map< std::pair<pii, pii>, ll>f;

template< typename T>
const T sign(T x) {
    if(x >= 0) return 1;
    return -1;
}


void update(ll &t, ll x) {
    if(x == 0) return;
    if(t == 0) t = x;
    t = std::min(t, x);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int x = 0, y = 0, dx = 1, dy = 1;
    ll tot = 1;
    while(true)  {
        if(x + dx == n + 1 || x + dx == -1) dx *= -1;
        if(y + dy == m + 1 || y + dy == -1) dy *= -1;

        if(x == 0 || x == n || y == 0 || y == m) {
            if(f[mp(mp(x, y), mp(dx, dy))]) break;
            f[mp(mp(x, y), mp(dx, dy))] = tot;
        }

        int ax = 0, ay = 0;
        if(dx > 0) ax = n - x; else ax = -x;
        if(dy > 0) ay = m - y; else ay = -y;
        int o = std::min(abs(ax), abs(ay));
        ax = sign(ax) * abs(o);
        ay = sign(ay) * abs(o);
        tot += 1ll * o;
        x += ax;
        y += ay;
    }
    int q; scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        ll a, b;
        scanf("%I64d%I64d", &a, &b);
        ll ans = 0;

        if(f[mp(mp(0, b - a), mp(1, 1))])
            update(ans, 1ll * f[mp(mp(0, b - a), mp(1, 1))] - 1 + a);

        if(f[mp(mp(0, b + a), mp(1, -1))])
            update(ans, 1ll * f[mp(mp(0, b + a), mp(1, -1))] - 1 + a);

        if(f[mp(mp(n, b - (n - a)), mp(-1, 1))])
            update(ans, 1ll * f[mp(mp(n, b - (n - a)), mp(-1, 1))] - 1 + (n - a));

        if(f[mp(mp(n, b + (n - a)), mp(-1, -1))])
            update(ans, 1ll * f[mp(mp(n, b + (n - a)), mp(-1, -1))] - 1 + (n - a));

        if(f[mp(mp(a - b, 0), mp(1, 1))])
            update(ans, 1ll * f[mp(mp(a - b, 0), mp(1, 1))] - 1 + b);

        if(f[mp(mp(a + b, 0), mp(-1, 1))])
            update(ans, 1ll * f[mp(mp(a + b, 0), mp(-1, 1))] - 1 + b);

        if(f[mp(mp(a - (m - b), m), mp(1, -1))])
            update(ans, 1ll * f[mp(mp((a - (m - b)), m), mp(1, -1))] - 1 + (m - b));

        if(f[mp(mp(a + (m - b), m), mp(-1, -1))])
            update(ans, 1ll * f[mp(mp(a + (m - b), m), mp(-1, -1))] - 1 + (m - b));
        if(a == b) ans = a;
        if(ans == 0) puts("-1");
        else printf("%I64d\n", ans);
    }
    return 0;
}
