#include <bits/stdc++.h>

typedef long long ll;
const int N = 2e5+10;
int n;
int a[N];
bool vis[N];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    std::sort(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int k = a[i];
        ll tot = 0;
        int p = i;
        while(true) {
            if(p == n) break;
            int L = p;
            int R = std::lower_bound(a + p, a + n, k + a[i]) - a;
            tot += 1ll * k * std::max(0, R - L);
            k = a[R] - a[R] % a[i];
            p = R;
        }
        ans = std::max(ans, tot);
    }
    printf("%lld\n", ans);
    return 0;
}
