#include <bits/stdc++.h>

typedef long long ll;
const ll mod = 1e9 + 7;
int dp[2][420010];
int pls[420010];
int val[420010];

template <class T>
void add(T& a, T b) {
    a = (1ll*a + 1ll*b + 1ll*mod) % mod;
}

int main() {
    int a, b, k, t;
    std::cin >> a >> b >> k >> t;
    int O = 1e5 + 1000;
    memset(dp, 0, sizeof dp);
    int cur = 0, next = 1;
    dp[cur][O + a - b] = 1;
    for(int i = 0; i < t; i++) {
        memset(pls, 0, sizeof pls);
        memset(val, 0, sizeof val);
        memset(dp[next], 0, sizeof dp[next]);

        for(int j = 0; j <= 3e5; j++) if(dp[cur][j]) {
            int now = dp[cur][j];
            add(pls[j - 2 * k], now);
            add(pls[j + 1], -now);
            add(val[j + 1], (int)(1ll*now * (2 * k + 1) % mod));
        }
        int tot1 = 0;
        int ans1 = 0;
        for(int i = 0; i < 3e5; i++) {
            tot1 = (1ll*tot1 + 1ll*pls[i] + 1ll*mod) % mod;
            ans1 = (1ll*ans1 - 1ll*val[i] + 1ll*mod) % mod;
            add(ans1, tot1);
            add(dp[next][i], ans1);
        }
        memset(pls, 0, sizeof pls);
        memset(val, 0, sizeof val);
        for(int j = 3e5; j >= 0; j--) if(dp[cur][j]) {
            int now = dp[cur][j];
            add(pls[j + 2 * k], now);
            add(pls[j], -now);
            add(val[j], (int)(1ll*now * (2 * k) % mod));
        }
        tot1 = 0;
        ans1 = 0;
        for(int i = 3e5; i >= 0; i--) {
            tot1 = (1ll*tot1 + 1ll*pls[i] + 1ll*mod) % mod;
            ans1 = (1ll*ans1 - 1ll*val[i] + 1ll*mod) % mod;
            add(ans1, tot1);
            add(dp[next][i], ans1);
        }
        std::swap(next, cur);
    }
    int ans = 0;
    for(int i = O + 1; i < 3e5; i++)
        add(ans, dp[cur][i]);
    std::cout << ans << std::endl;
    return 0;
}
