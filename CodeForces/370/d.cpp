#include <bits/stdc++.h>

typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 500010;
ll dp[2][N];

template <class T>
void add(T& a, T b) {
    a = (a + b) % mod;
}

int main() {
    int a, b, k, t;
    std::cin >> a >> b >> k >> t;
    int nil = 2e5 + 2000;
    memset(dp, 0, sizeof dp);
    int cur = 0, next = 1;
    dp[cur][nil + a - b] = 1;
    dp[cur][nil + a - b + 1] = mod - 1;
    for(int i = 0; i < 2 * t; i++) {
        ll tot = 0;
        memset(dp[next], 0, sizeof dp[next]);
        for(int j = 0; j < N; j++) {
            add(tot, dp[cur][j]);
            //if(dp[cur][j]) std::cout << dp[cur][j] << ":" << j <<" ";
            if(tot == 0) continue;
            add(dp[next][j - k], tot);
            add(dp[next][j + k + 1], mod - tot);
        }
        //std::cout << std::endl;
        std::swap(next, cur);
    }
    ll ans = 0;
    ll tot = 0;
    for(int i = 0; i < N; i++) {
        add(tot, dp[cur][i]);
        if(i > nil) add(ans, tot);
    }
    std::cout << ans << std::endl;
    return 0;
}
