#include <bits/stdc++.h>
using namespace std;

int dp[110][3];
int a[110];
const int inf = 1e9;
inline void cmin(int &a, int b) { a = min(a, b); }

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        if(true)  {
            if(i == 0) dp[i][0] = 1;
            else {
                int &now = dp[i][0];
                now = inf;
                if(dp[i - 1][0] != -1) cmin(now, dp[i - 1][0]);
                if(dp[i - 1][1] != -1) cmin(now, dp[i - 1][1]);
                if(dp[i - 1][2] != -1) cmin(now, dp[i - 1][2]);
                dp[i][0] += 1;
            }
       }
       if(a[i] == 1 || a[i] == 3) {
            if(i == 0) dp[i][1] = 0;
            else {
                int &now = dp[i][1];
                now = inf;
                if(~dp[i - 1][0]) cmin(now, dp[i - 1][0]);
                if(~dp[i - 1][2]) cmin(now, dp[i - 1][2]);
            }
        }
        if(a[i] == 2 || a[i] == 3) {
            if(i == 0) dp[i][2] = 0;
            else {
                int &now = dp[i][2];
                now = inf;
                if(~dp[i - 1][0]) cmin(now, dp[i - 1][0]);
                if(~dp[i - 1][1]) cmin(now, dp[i - 1][1]);
            }
        }
    }
    int ans = 1e9;
    if(~dp[n - 1][0]) cmin(ans, dp[n - 1][0]);
    if(~dp[n - 1][1]) cmin(ans, dp[n - 1][1]);
    if(~dp[n - 1][2]) cmin(ans, dp[n - 1][2]);
    cout << ans << endl;
    return 0;
}
