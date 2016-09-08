#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
const int MOD = 1e4+7;
const int STATE = 1e5;
const int N = 12;
typedef long long ll;

struct HashMap {
    int nt[N];
    ll head[MOD];
    ll state[STATE];
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
        return tot - 1;
    }
}hm[2];

inline int get(std::vector<int>& f) {
    int g = 0;
    for(int i = f.size() - 1; i != -1; i--) {
        g = g * 3 + f[i];
    }
    return g;
}

ll dp[N][N][15000];
int s[N][N];

inline void solve() {
    static int _t = 1;
    memset(dp, 0, sizeof dp);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &s[i][j]);

    dp[1][0][0] = 1;
    int cur = 0;
    hm[cur].init();
    hm[cur ^ 1].init();
    hm[cur].get(0);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++) {
            hm[cur ^ 1].init();
            for(int p = 0; p < hm[cur].tot; p++) {
                ll g = hm[cur].state[p];
                ll now = dp[i][j][p];
                if(now == 0) continue;
                if(j != m) {
                    if(s[i][j + 1]) {
                        //for(int i = 0; i <= m; i++) std::cout << ((g >> i) & 1) << " "; std::cout << std::endl;
                        if(1 << j & g) if(1 << (j + 1) & g) {
                            dp[i][j + 1][hm[cur ^ 1].get(g ^ (1 << j) ^ (1 << (j + 1)))] += now;
                        }
                        if(1 << j & ~g) if(1 << (j + 1) & ~g) {
                            dp[i][j + 1][hm[cur ^ 1].get(g ^ (1 << j) ^ (1 << (j + 1)))] += now;
                        }
                        if(1 << j & g) if(1 << (j + 1) & ~g) {
                            int mask = (g ^ (1 << j));
                            dp[i][j + 1][hm[cur ^ 1].get(mask ^ (1 << j))] += now;
                            dp[i][j + 1][hm[cur ^ 1].get(mask ^ (1 << (j + 1)))] += now;
                        }
                        if(1 << j & ~g) if(1 << (j + 1) & g) {
                            int mask = (g ^ (1 << (j + 1)));
                            dp[i][j + 1][hm[cur ^ 1].get(mask ^ (1 << j))] += now;
                            dp[i][j + 1][hm[cur ^ 1].get(mask ^ (1 << (j + 1)))] += now;
                        }
                    }
                    else {
                        if((1 << j) & g) continue;
                        if((1 << (j + 1)) & g) continue;
                        dp[i][j + 1][hm[cur ^ 1].get(g)] += now;
                    }
                }
                else {
                    if(g & (1 << m)) continue;
                    int mask = (g << 1) & ((1 << (m + 1)) - 1);
                    dp[i + 1][0][hm[cur ^ 1].get(mask)] += now;
                }
            }
            cur ^= 1;
        }
    std::cout << "Case " << _t++ << ": There are " << dp[n + 1][0][hm[cur].get(0)] << " ways to eat the trees." <<  std::endl;
    //std::cout << dp[n + 1][0][0] << std::endl;
}


int main() {
    int _t; scanf("%d", &_t);
    while(_t--) solve();
    return 0;
}

