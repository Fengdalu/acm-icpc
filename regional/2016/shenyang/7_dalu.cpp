#include <bits/stdc++.h>

typedef long long ll;

int buf[1<<5];
ll dp[1<<5][2][2][2];
ll cal(ll _) {
    int cnt = 0;
    while(_) {
        buf[cnt++] = _  % 10ll;
        _ /= 10ll;
    }
    std::reverse(buf, buf + cnt);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= buf[0]; i++) dp[0][i == buf[0]][i % 2][1] += 1;
    for(int i = 0; i < cnt; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                for(int p = 0; p < 2; p++) {
                    ll now = dp[i][j][k][p];
                    if(!now) continue;
                    int nt = buf[i + 1];
                    int up = (j) ? nt : 9;
                    for(int num = 0; num <= up; num++) {
                        int mode = (num & 1) == (k);
                        if(mode)
                            dp[i + 1][j && num == nt][num & 1][p ^ 1] += now;
                        else if(k ^ p)
                            dp[i + 1][j && num == nt][num & 1][1] += now;
                    }
                }
    ll tot = 0;
    for(int j = 0; j < 2; j++)
        for(int k = 0; k < 2; k++)
            for(int p = 0; p < 2; p++) if(k ^ p)
                tot += dp[cnt - 1][j][k][p];
    return tot;
}

ll cal1(ll p) {
    if(p == 0) return 0;
    __int128 _ = 9;
    ll tot = 0;
    while(_ < p) {
        tot += cal(_);
        _ = _  * 10 + 9;
    }
    return tot + cal(p);
}

int main() {
    static char buf[1<<10];
    int _t; scanf("%d", &_t);
    int _cas = 1;
    while(_t--) {
        ll l, r;
        std::cin >> l >> r;
        sprintf(buf, "Case #%d: %lld", _cas++, cal1(r) - cal1(l - 1));
        std::cout << buf << std::endl;
    }
    return 0;
}

