#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000007;
int dp[1010][1010];
int a[1010], b[1010];
void update(int &x, int y) {
    x = (1ll * x + y + mod) % mod;
}

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
        memset(dp, 0, sizeof dp);
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                update(dp[i][j], dp[i][j - 1]);
                update(dp[i][j], dp[i - 1][j]);
                if(a[i] == b[j]) update(dp[i][j], 1);
                else update(dp[i][j], -dp[i - 1][j - 1]);
            }
        cout << dp[n][m] << endl;
    }
    return 0;
}
