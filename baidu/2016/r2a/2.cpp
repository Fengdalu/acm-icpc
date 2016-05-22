#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define ONES(x) __builtin_popcount(x)

const int maxn = 17;
int dp[17][1 << 17][17];
int n;
int a[maxn], b[maxn];
int pos[maxn];
void cmax(int &a, int b) {
    a = max(a, b);
}
int main() {
    int T;
    scanf("%d", &T);
    for(int ii = 1; ii <= T; ii++) {
        scanf("%d", &n);
        memset(pos, -1, sizeof pos);
        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &a[i], &b[i]);
            if(b[i] != -1) pos[b[i]] = i;
        }
        for(int k = 0; k < (1 << n); k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dp[i][k][j] = -2e9;

        int INF = -2e9;
        if(pos[0] == -1) {
            for(int i = 0; i < n; i++) if(b[i] == -1) dp[0][1 << i][i] = 0;
        }
        else
            dp[0][1 << pos[0]][pos[0]] = 0;
        for(int i = 0; i < n; i++) {
            for(int mask = 0; mask < (1 << n); mask++) if(ONES(mask) == i + 1) {
                    int tot = ONES(mask);
                    int l = 0, r = n;
                    for(int j = l; j < r; j++) if(1 << j & mask) {
                        if(dp[i][mask][j] == INF) continue;
                        int l = 0, r = n;
                        if(pos[i + 1] != -1) { l = pos[i + 1]; r = l + 1; }
                        for(int k = l; k < r; k++) if((1 << k & mask) == 0) {
                            cmax(dp[i + 1][(1 << k) | mask][k], dp[i][mask][j] + a[k] * a[j]);
                        }
                    }
            }
        }
        int ans = -2e9;
        for(int i = 0; i < n; i++)
            cmax(ans, dp[n - 1][(1 << n) - 1][i]);
        cout << "Case #" << ii << ":" << endl;
        cout << ans << endl;
    }
    return 0;
}
