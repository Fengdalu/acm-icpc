#include <bits/stdc++.h>

typedef long long ll;
const int N = 800;
const ll inf = 1e18;
ll dp[N][N];
int a[N];

template <typename T>
void update(T &a, T b) {
    a = std::min(a, b);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    dp[0][0] = a[0];
    dp[0][1] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            ll now = dp[i][j];
            update(dp[i + 1][j], now + a[i + 1]);
            update(dp[i + 1][j], now);
            update(dp[i + 1][j + 1], now);
        }
    ll *f = dp[n];
    /*
    for(int i = 0; i < n; i++)
        f[i + 1] = std::max(f[i], f[i + 1]);
        */
    for(int i = 0; i <= n; i++) printf("%lld ", f[i]); puts("");
    while(m--) {
        int x; scanf("%d", &x);
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r) / 2;
            if(f[mid] >= x) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
