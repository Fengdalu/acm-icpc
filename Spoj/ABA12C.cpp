#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
int dp[105];
int w[105];

void update(int &x, int y) {
    if(x == -1) x = y;
    else x = min(x, y);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int j = 1; j <= k; j++) scanf("%d", w + j);
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) if(~w[j])
                for(int p = k - j; p >= 0; p--) if(~dp[p])
                    update(dp[p + j], dp[p] + w[j]);
        }
        printf("%d\n", dp[k]);
    }
    return 0;
}
