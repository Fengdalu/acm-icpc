#include <bits/stdc++.h>
const int N = 305;
int n;
int a[N];
long long v[N];
long long dp[N][N];
bool vis[N][N];
int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b); }

long long cal(int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l >= r) return 0;
    long long &now = dp[l][r];
    if(l == r - 1) {
        if(gcd(a[l], a[r]) != 1) now = v[l] + v[r], vis[l][r] = true;
        else now = 0;
        return now;
    }
    for(int i = l; i <= r; i++) {
        now = std::max(cal(l, i) + cal(i + 1, r), now);
        vis[l][r] |= vis[l][i] && vis[i + 1][r];
    }
    if(cal(l + 1, r - 1) != 0 && vis[l + 1][r - 1] && gcd(a[l], a[r]) != 1) now = std::max(now, cal(l + 1, r - 1) + v[l] + v[r]), vis[l][r] = true;
    return now;
}

void run()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for(int i = 1, x; i <= n; i++) {scanf("%d",&x); v[i] = x;}
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            dp[i][j] = -1;
            vis[i][j] = false;
        }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            ans = std::max(ans, cal(i, j));
    std::cout << ans << std::endl;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) run();
    return 0;
}
