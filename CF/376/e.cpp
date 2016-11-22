#include <bits/stdc++.h>

const int N = 2e5+10;
typedef long long ll;
ll f[N], dp[N];
int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%I64d", f + 1 + i);
        f[i + 1] += f[i];
    }
    dp[n] = 0;
    ll mx = -2e9;
    for(int i = n - 1; i >= 1; i--) {
        mx = std::max(mx, f[i + 1] - dp[i + 1]);
        dp[i] = mx;
    }
    printf("%I64d\n", dp[1]);
    return 0;
}
