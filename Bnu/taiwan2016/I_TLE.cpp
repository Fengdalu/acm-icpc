#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

typedef long long ll;
ll dp[20][10][2];

ll sub(ll *T, int L, int R) {
    if(R < L) return 0;
    return T[R+1] - T[L];
}

ll cal(ll up, int mk) {
    static int q[20];
    static ll S[2][20];
    ll UP = up;
    int CNT = 0;
    while(up) {
        q[CNT++] = up % 10;
        up /= 10;
    }
    std::reverse(q, q + CNT);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= q[0]; i++) {
        dp[0][i][(i == q[0])] = 1;
    }
    if(CNT == 1) {
        if(mk == 1) return q[0];
        return 0;
    }
    for(int i = 0; i < CNT - 1; i++) {
        int cur = q[i + 1];
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k < 2; k++) {
                ll *F = S[k];
                std::fill(F, F + 10, 0);
                for(int p = 0; p <= 9; p++)
                    F[p + 1] = F[p] + dp[i][p][k];
            }
        }
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k < 2; k++) {
                if(k == 1 && j > cur) continue;
                if(mk == 0) {
                    if(!k) {
                        dp[i + 1][j][k] = sub(S[0], j, 9);
                        if(j < cur) dp[i + 1][j][k] += sub(S[1], j, 9);
                    }
                    else if(j == cur) dp[i + 1][j][k] += sub(S[1], j, 9);
                }
                else if(mk == 1) {
                    if(!k) {
                        dp[i + 1][j][k] = sub(S[0], 0, j);
                        if(j < cur) dp[i + 1][j][k] += sub(S[1], 0, j);
                    }
                    else if(j == cur) {
                        dp[i + 1][j][k] = sub(S[1], 0, j);
                    }
                }
                else if(mk == 2) {
                    if(!k) {
                        dp[i + 1][j][k] = sub(S[0], j, j);
                        if(j < cur) dp[i + 1][j][k] += sub(S[1], j, j);
                    }
                    else if(j == cur) dp[i + 1][j][k] += sub(S[1], j, j);
                }
            }
        }
    }
    ll tot = 0;
    for(int i = 0; i <= 9; i++)
        for(int j = 0; j < 2; j++)
            tot += dp[CNT - 1][i][j];
    return tot;
}

ll cal(ll L) {
    const ll PRE[] = {9, 90, 375, 1200, 3279, 7998, 17865, 37170, 72920, 136126, 243532, 419890, 700900, 1136950, 1797808, 2778436, 4206115, 6249090};
    if(L == 0) return 0;
    ll c = 9;
    ll tot = 0;
    int cnt = 0;
    while(c < L) {
        tot += PRE[cnt++];
        if(c == (1e18 - 1)) break;
        c = c * 10ll + 9ll;
    }
    for(int j = 0; j < 2; j++)  tot += cal(L, j);
    tot -= cal(L, 2);
    return tot;
}

int main() {
    int m; scanf("%d", &m);
    while(m--) {
        ll L, R;
        scanf("%lld%lld", &L, &R);
        printf("%lld\n", cal(R) - cal(L - 1));
    }
    return 0;
}
