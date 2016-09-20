#include <bits/stdc++.h>

const int N = 101;
std::bitset<1<<7> dp[N][N];
int a[N][N];
int main() {
    int n, m;
    int K;
    while(~scanf("%d%d%d", &n, &m, &K)) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) dp[i][j].reset();
        dp[1][1].reset();
        dp[1][1][0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                dp[i][j] |= dp[i][j - 1] | dp[i - 1][j];
                dp[i][j] |= dp[i][j] << a[i][j];
            }
        int ans = 0;
        for(int i = 0; i <= K; i++)  if(dp[n][m][i]) ans = std::max(ans, i);
        printf("%d\n", ans);
    }
    return 0;
}

