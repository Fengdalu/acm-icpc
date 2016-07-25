#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
#define ONES(x) __builtin_popcount(x)
#define MOD 0x3f3f3f3f
#define cmin(x, y) x = min(x, y)
typedef long long ll;

int x[120], y[120];
bool f[20][20];
int cnt;
int ans;
int n, m;
int dp[1 << 20][20][3];

int main() {
    while(~scanf("%d%d", &n, &m)) {
        if(n == 0) {
            printf("0\n");
            continue;
        }
        for(int i = 0; i < m; i++) scanf("%d%d", &x[i], &y[i]);
        for(int i = 0; i < m; i++) x[i]--, y[i]--;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                f[i][j] = 0;

        for(int i = 0; i < m; i++) f[x[i]][y[i]] = 1;
        for(int i = 0; i < 1 << (n + n); i++)
            for(int j = 0; j < n + n; j++)
                for(int k = 0; k < 3; k++)
                    dp[i][j][k] = n + 1;

        dp[1][0][0] = 0;
        for(int mk = 0; mk < 1 << (n + n); mk++) {
            for(int i = 0; i < n + n; i++)
                if(1 << (i) & mk) {
                    for(int k = 0; k < 3; k++) {
                        int now = dp[mk][i][k];
                        if(now != n + 1) {
                            for(int j = 0; j < n + n; j++)
                                if(1 << j & ~mk) {
                                    if(k == 0 && j > n - 1) {
                                        int add = f[j - n][i];
                                        if(add) {
                                            int &next = dp[1 << j ^ mk][j][2];
                                            cmin(next, now + add);
                                        }
                                        else {
                                            int &next = dp[1 << j ^ mk][j][1];
                                            cmin(next, now);
                                        }
                                    }
                                    if(k == 1 && j < n) {
                                        int add = f[i - n][j];
                                        int &next = dp[1 << j ^ mk][j][0];
                                        cmin(next, now + add);
                                    }
                                    if(k == 2 && j < n) {
                                        int &next = dp[1 << j ^ mk][j][0];
                                        cmin(next, now);
                                    }
                                }
                        }
                    }
                }
        }
        int tot = (1 << (n + n)); tot--;
        int ans = n + 1;
        for(int i = n; i < n + n; i++)
            for(int j = 1; j < 3; j++) {
                if(j == 1)
                    cmin(ans, dp[tot][i][j] + (int)f[i - n][0]);
                else
                    cmin(ans, dp[tot][i][j]);
            }
        cout << ans << endl;
    }
    return 0;
}
