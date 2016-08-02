#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
struct BIT {
    int _[50010];
    int n;
    void init(int m) {
        n = m;
        memset(_, 0, sizeof(int) * (m + 2));
    }

    int lb(int x) { return x & (-x); }

    void insert(int a, int b) {
        while(a <= n) {
            _[a] += b;
            a += lb(a);
        }
    }

    int cal(int x) {
        int ans = 0;
        while(x) {
            ans += _[x];
            x -= lb(x);
        }
        return ans;
    }
}b;
int X[50050];
int a[50050];
int f[50050][2], g[50050][2];

int main() {
    int n;
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) X[i - 1] = a[i];
        sort(X, X + n);
        int cnt = unique(X, X + n) - X;
        for(int i = 1; i <= n; i++) a[i] = lower_bound(X, X + cnt, a[i]) - X + 1;
        b.init(cnt + 2);
        for(int i = 1; i <= n; i++) {
            f[i][0] = b.cal(a[i] - 1);
            f[i][1] = b.cal(cnt + 2) - b.cal(a[i]);
            b.insert(a[i], 1);
        }
        b.init(cnt + 2);
        for(int i = n; i > 0; i--) {
            g[i][0] = b.cal(a[i] - 1);
            g[i][1] = b.cal(cnt + 2) - b.cal(a[i]);
            b.insert(a[i], 1);
        }
        ll ans = 0;
        ll x = 0 , y = 0;
        for(int i = 1; i <= n; i++) x += f[i][0], y += f[i][1];
        ans = x * y;
        for(int i = 1; i <= n; i++) {
            ans -= 1ll * f[i][0] * g[i][0];
            ans -= 1ll * f[i][1] * f[i][0];
            ans -= 1ll * g[i][1] * g[i][0];
            ans -= 1ll * f[i][1] * g[i][1];
        }
        cout << ans << endl;
    }
    return 0;
}
