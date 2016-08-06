#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

void update(int &a, int b) {
    a = (a + b) % mod;
}

int dp[2][1010][4][4];

int main() {
    int _T;
    scanf("%d", &_T);
    int n, s;
    while(~scanf("%d%d", &n, &s)) {
        int x=0,y=1;
        memset(dp, 0, sizeof dp);
        dp[x][0][0][0] = 1;
        for(int i = 0; i < n; i++) {
            int w; scanf("%d", &w);
            memset(dp[y], 0, sizeof(dp[y]));
            for(int j = 0; j <= s; j++) for(int k = 0; k <= 2; k++) for(int p = 0; p <= 2; p++)
            if(dp[x][j][k][p]) {
                int now = dp[x][j][k][p];
                if(j + w <= s) update(dp[y][j + w][k][p], now);
                if(j + w <= s) update(dp[y][j + w][k + 1][p], now);
                update(dp[y][j][k][p], now);
                update(dp[y][j][k][p + 1], now);
            }
            swap(x, y);
        }
        int ans = 0;
        for(int i = 1; i <= s; i++) update(ans, dp[x][i][2][2]);
        update(ans, ans);
        update(ans, ans);
        printf("%d\n", ans);
    }
    return 0;
}
