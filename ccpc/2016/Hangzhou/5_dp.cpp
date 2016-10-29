#include <bits/stdc++.h>

#define cmax(x, y) x = std::max(x, y)
const int MOD = 1e5+9;
const int N = 1e7;
struct State{
    int a[9];
    int hash() {
        int hash = 0;
        for(int i = 0; i < 9; i++)
            hash = ((hash * 101) + a[i]) % MOD;
        return hash;
    }

    bool operator == (const State &s) const {
        for(int i = 0; i < 9; i++)
            if(s.a[i] != a[i]) return false;
        return true;
    }
};

template <typename T>
struct HashMap {
    int index[MOD];
    T states[N];
    int next[N];
    int tot;

    void init() {
        std::fill(index, index + MOD, -1);
        tot = 0;
    }

    int get(T state) {
        int base = state.hash();
        for(int k = index[base]; k != -1; k = next[k]) {
            if(states[k] == state) return k;
        }
        states[tot] = state;
        next[tot] = index[base];
        return index[base] = tot++;
    }
};

HashMap<State> f[2];
int dp[2][N];
static const int up[] = {16, 15, 14, 13, 12, 11, 10, 9, 8};
int main() {
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        State op;
        for(int i = 0; i < 9; i++)
            scanf("%d", &op.a[i]);
        for(int i = 0; i < 9; i++)
            op.a[i] = std::min(op.a[i], up[i]);
        memset(dp, 0, sizeof dp);
        int cur = 0, next = 1;
        f[cur].init();
        dp[cur][f[cur].get(op)] = 0;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9 - i - 1; j++) {
                int k = i + j + 1;
                std::fill(dp[next], dp[next] + f[next].tot + 1, 0);
                f[next].init();
                for(int p = 0; p < f[cur].tot; p++) {
                    State S = f[cur].states[p];
                    cmax(dp[next][f[next].get(S)], dp[cur][p]);
                    S.a[i]--; S.a[j]--; S.a[k]--;
                    if(S.a[i] >= 0 && S.a[j] >= 0 && S.a[k] >= 0)  {
                        cmax(dp[next][f[next].get(S)], dp[cur][p] + 1);
                    }
                    S.a[i]++; S.a[j]++; S.a[k]++;
                }
                std::swap(cur, next);
            }
        }
        printf("Case #%d :%d\n", cas, *std::max_element(dp[cur], dp[cur] + f[cur].tot + 1));
    }
    return 0;
}
