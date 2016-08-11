#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string a[100010], b[100010];
char buf[100100];
int n;
ll dp[100010][2];
ll c[100010];

void update(ll &a, ll b) {
    if(b == -1) return;
    if(a == -1 || a > b) a = b;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld", &c[i]);
    for(int i = 0; i < n; i++) {
        scanf("%s", buf);
        a[i] = string(buf);
        int len = strlen(buf);
        reverse(buf, buf + len);
        b[i] = string(buf);
    }

    for(int i = 0; i < 100010; i++) dp[i][0] = dp[i][1] = -1;
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for(int i = 1; i < n; i++) {
        if(dp[i - 1][0] != -1) {
            if(a[i - 1] <= a[i]) update(dp[i][0], 1ll * dp[i - 1][0]);
            if(a[i - 1] <= b[i]) update(dp[i][1], 1ll * dp[i - 1][0] + c[i]);
        }
        if(dp[i - 1][1] != -1) {
            if(b[i - 1] <= a[i]) update(dp[i][0], dp[i - 1][1]);
            if(b[i - 1] <= b[i]) update(dp[i][1], dp[i - 1][1] + c[i]);
        }
        if(dp[i][0] == -1 && dp[i][1] == -1) {
            puts("-1\n"); return 0;
        }
    }

    ll ans = -1;
    update(ans, dp[n - 1][0]);
    update(ans, dp[n - 1][1]);
    cout << ans << endl;
    return 0;
}
