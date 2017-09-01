#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
int dp[1 << 18];
int w[1 << 18];
int a[18];
int n, K;

int cal(int mask) {
//    cout << "cal " << mask << endl;
    if(mask == 0) return 0;
    if(dp[mask] != -1) return dp[mask];
    int ans = 0;
    int cc = 0;
    for(int i = 0; i < n; i++) if(1 << i & mask) {
        int cur = 0;
        int g = a[i];
        for(int j = i; j < n; j++) if(1 << j & mask) {
            cur ^= (1 << j);
            g = __gcd(g, a[j]);
            if(g >= K) {
                ans = (ans + cal(mask ^ cur) + 1) % MOD;
                cc++;
            }
        }
    }
//    cout << mask << " " << cc << endl;
    return dp[mask] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d%d", &n, &K);
    for(int i = 0; i < n; i++) scanf("%d", a + i);

    printf("%d\n", cal((1 << n) - 1));
//    cout << dp[13] << endl;
//    cout << dp[7] << endl;
    return 0;
}

/*
18 2
8 10 8 10 8 10 8 10 8 10 8 10 8 10 8 10 80 18
*/
