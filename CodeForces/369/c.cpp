#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200;

ll dp[N][N][N];
int pp[N][N];
int c[N];

void update(ll &a, ll b) {
    if(b == -1) return ;
    if(a == -1 || b < a) a = b;
}

int main() {
    int n, m, kk;
    scanf("%d%d%d", &n, &m, &kk);
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) scanf("%d", &pp[i][j]);
    }
    if(c[0] == 0) {
        for(int i = 1; i <= m; i++)
            dp[0][i][1] = pp[0][i];
    }
    else dp[0][c[0]][1] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++)
            for(int k = 0; k <= kk; k++) if(~dp[i][j][k]) {
                ll now = dp[i][j][k];
                if(c[i + 1] == 0) {
                    for(int p = 1; p <= m; p++)
                        update(dp[i + 1][p][k + (int)(p != j)], now + pp[i + 1][p]);
                }
                else update(dp[i + 1][c[i + 1]][k + (int)(j != c[i + 1])], now);
            }
    }
    ll ans = -1;
    for(int i = 1; i <= m; i++)
        update(ans, dp[n - 1][i][kk]);
    cout << ans << endl;
    return 0;
}
