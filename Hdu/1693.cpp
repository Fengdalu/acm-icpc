#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
const int MOD = 1e4+7;
const int STATE = 1e6;
const int N = 13;
typedef long long ll;

struct HashMap {
    ll head[MOD];
    ll state[STATE];
    int nt[STATE];
    int tot;

    void init() {
        tot = 0;
        memset(head, -1, sizeof head);
    }

    ll get(int st) {
        for(int k = head[st % MOD]; k != -1; k = nt[k]) {
            if(state[k] == st) return k;
        }
        state[tot] = st;
        nt[tot] = head[st % MOD];
        head[st % MOD] = tot++;
        if(tot >= STATE) exit(2);
        return tot - 1;
    }
} hm[2];

ll dp[2][STATE];
int s[N][N];

inline void solve() {
    static int _t = 1;
    memset(dp, 0, sizeof dp);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &s[i][j]);

    int cur = 0;
    dp[cur][0] = 1;
    hm[cur].init();
    hm[cur ^ 1].init();
    hm[cur].get(0);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++) {
            hm[cur ^ 1].init();
            memset(dp[cur ^ 1], 0, sizeof (dp[cur ^ 1]));
            for(int p = 0; p < hm[cur].tot; p++) {
                ll g = hm[cur].state[p];
                ll now = dp[cur][p];
                if(now == 0) continue;
                if(j != m) {
                    if(s[i][j + 1]) {
                        if(1 << j & g) if(1 << (j + 1) & g) {
                            dp[cur ^ 1][hm[cur ^ 1].get(g ^ (1 << j) ^ (1 << (j + 1)))] += now;
                        }
                        if(1 << j & ~g) if(1 << (j + 1) & ~g) {
                            dp[cur ^ 1][hm[cur ^ 1].get(g ^ (1 << j) ^ (1 << (j + 1)))] += now;
                        }
                        if(1 << j & g) if(1 << (j + 1) & ~g) {
                            int mask = (g ^ (1 << j));
                            dp[cur ^ 1][hm[cur ^ 1].get(mask ^ (1 << j))] += now;
                            dp[cur ^ 1][hm[cur ^ 1].get(mask ^ (1 << (j + 1)))] += now;
                        }
                        if(1 << j & ~g) if(1 << (j + 1) & g) {
                            int mask = (g ^ (1 << (j + 1)));
                            dp[cur ^ 1][hm[cur ^ 1].get(mask ^ (1 << j))] += now;
                            dp[cur ^ 1][hm[cur ^ 1].get(mask ^ (1 << (j + 1)))] += now;
                        }
                    }
                    else {
                        if((1 << j) & g) continue;
                        if((1 << (j + 1)) & g) continue;
                        dp[cur ^ 1][hm[cur ^ 1].get(g)] += now;
                    }
                }
                else {
                    if(g & (1 << m)) continue;
                    int mask = (g << 1) & ((1 << (m + 1)) - 1);
                    dp[cur ^ 1][hm[cur ^ 1].get(mask)] += now;
                }
            }
            cur ^= 1;
        }
    printf("Case %d: There are %I64d ways to eat the trees.\n", _t++, dp[cur][hm[cur].get(0)]);
}


int main() {
    int _t; scanf("%d", &_t);
    while(_t--) solve();
    return 0;
}

