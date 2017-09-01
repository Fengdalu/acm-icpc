#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
int dp[19][1 << 18];
int w[1 << 18];
int a[18];
int n, K;

int cal(int x, int mask) {
    if(x == 0 && mask == 0) return 1;
    if(x == 0 || mask == 0) return 0;
    if(dp[x][mask] != -1) return dp[x][mask];

    int &ans = dp[x][mask];
    ans = 0;
    for(int i = 0; i < n; i++) if(1 << i & mask) {
        int cur = 0;
        for(int j = i; j < n; j++) if(1 << j & mask) {
            cur ^= (1 << j);
            if(w[cur] >= K) ans = (ans + cal(x - 1, mask ^ cur)) % MOD;
            else break;
        }
    }
//    cout << x <<" " << mask << " " << ans << endl;
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d%d", &n, &K);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    int ans = 0;


    for(int mask = 1; mask < (1 << n); mask++) {
        int &p = w[mask], f = -1;
        for(int j = 0; j < n; j++) if(1 << j & mask) {
            if(f == -1) p = a[j];
            else p = __gcd(p, a[j]);
            f = 1;
        }
    }
//    cal(2, (1 << n) - 1);
    for(int i = 0; i <= n; i++) {
        ans = (ans + 1LL* cal(i, (1 << n) - 1) * i % MOD) % MOD;
//        cout << cal(i, (1 << n) - 1) << endl;
    }
    printf("%d\n", ans);
    return 0;
}

/*
18 2
8 10 8 10 8 10 8 10 8 10 8 10 8 10 8 10 80 18
*/
