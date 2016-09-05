#include <bits/stdc++.h>
using namespace std;

template < class T >
void cmax(T &a, T b) {
    a = max(a, b);
}

int dp[2][2000];
int a[2000];
int b[2000];
void solve() {
    int n, m;
    if(scanf("%d%d", &n, &m) == -1) exit(0);
    if(n == 0 && m == 0) exit(0);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    vector<pair<int, int> >f(n);
    for(int i = 0; i < n; i++) f[i].first = b[i], f[i].second = a[i];
    sort(f.begin(), f.end(), greater< pair<int, int> >());
    int cur = 0;
    memset(dp, -1, sizeof dp);
    dp[cur][0] = 0;
    for(int i = 0; i < n; i++) {
        cur ^= 1;
        memset(dp[cur], -1, sizeof dp[cur]);
        for(int j = 0; j <= n; j++) if(~dp[cur ^ 1][j]) {
            int now = dp[cur ^ 1][j];
            cmax(dp[cur][j], now);
            cmax(dp[cur][j + 1], now + max(0, f[i].second - f[i].first * j));
        }
    }
    printf("%d\n", *max_element(dp[cur], dp[cur] + m + 1));
}

int main() {
    while(true) solve();
    return 0;
}
