#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
using namespace std;

typedef long long ll;

ll dp[2][60][5010];

int main() {
    int n, a;
    scanf("%d%d", &n, &a);
    int cur = 0;
    dp[cur][0][0] = 1;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        memset(dp[cur ^ 1], 0, sizeof dp[cur ^ 1]);
        for(int j = 0; j < n; j++)
            for(int k = 0; k < 5000 - x; k++) if(dp[cur][j][k]) {
                dp[cur ^ 1][j + 1][k + x] += dp[cur][j][k];
                dp[cur ^ 1][j][k] += dp[cur][j][k];
            }
        cur ^= 1;
    }
    //cur ^= 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[cur][i][i * a];
    }
    cout << ans << endl;
    return 0;
}
