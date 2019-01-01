#include <bits/stdc++.h>

typedef long long ll;

ll dp[41][41];

int main() {
    dp[0][0] = 1;
    for(int i = 1; i <= 40; i++) {
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
    printf("%lld %lld\n", dp[20][10], dp[40][20]);
    return 0;
}
