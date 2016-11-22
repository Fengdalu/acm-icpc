#include <bits/stdc++.h>

typedef long long ll;
const int N = 800;
const ll inf = 1e18;

ll dp[N][N];
ll a[N];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%I64d", a + i);
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= n - i; j++) {
            dp[i][j] = std::min(0ll, dp[i + 1][j] + a[i]);
            if(j - 1 >= 0) dp[i][j] = std::max(dp[i + 1][j - 1], std::min(0ll, dp[i + 1][j] + a[i]));
        }
    }
    ll *f = dp[0];
    while(m--) {
        ll b; scanf("%I64d", &b);
        printf("%d\n", std::lower_bound(f, f + n + 1, -b) - f);
    }
    return 0;
}
