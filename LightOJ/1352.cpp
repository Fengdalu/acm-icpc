#include <bits/stdc++.h>

typedef long long ll;
#define ONES(x) __builtin_popcount(x) // 1 数目

ll dp[64][2];
ll dp1[64][2];
ll cal(ll x) {
    static int num[70], cnt;
    cnt = 0;
    ll tmp = x;
    while(tmp) {
        num[cnt++] = tmp & 1;
        tmp >>= 1;
    }
    std::reverse(num, num + cnt);
    memset(dp1, 0, sizeof dp1);
    memset(dp, 0, sizeof dp);
    dp[0][1] = 1;
    dp1[0][1] = 1;
    for(int i = 0; i < cnt; i++) {
        for(int j = 0; j < 2; j++)
            if(dp1[i][j]) {
                int nt = num[i + 1];
                int up = (j == 1) ? nt : 1;
                ll now = dp[i][j];
                for(int p = 0; p <= up; p++) {
                    int g = (j == 1) && (p == up);
                    dp[i + 1][g] ^= ((now << 1) ^ p);
                    dp1[i + 1][g] ^= 1;
                }
            }
    }
    ll tot = 0;
    return dp[cnt - 1][0] ^ dp[cnt - 1][1];
}

ll cal1(ll up) {
    if(up == 0) return 0;
    __int128 q = 1;
    ll tot = 0;
    while(q < up) {
        tot = (tot << 1) ^ cal(q);
        q = (q << 1) ^ 1;
    }
    return (tot << 1) ^ cal(up);
}

int top(ll q) {
    for(int i = 63; i >= 0; i--) {
        if(q >> i & 1) return i;
    }
    return 0;
}

int main() {
    int _t; scanf("%d", &_t);
    int _cas = 1;
    while(_t--) {
        ll l, r;
        std::cin >> l >> r;
        int offset = top(r) - top(l - 1);
        printf("Case %d: %lld\n", _cas++, cal1(r) ^ cal1(l - 1) << offset);
    }
    return 0;
}

