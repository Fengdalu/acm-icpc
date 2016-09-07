#include <bits/stdc++.h>

typedef long long ll;
const int O = 2000;
int num[20];
ll dp[20][5000][2];
int cnt;

ll cal1(ll x, ll balance) {
    memset(dp, 0, sizeof dp);
    dp[0][O][1] = 1;
    for(int i = 0; i < cnt - 1; i++)
        for(int j = 0; j < 5000; j++)
            for(int k = 0; k < 2; k++) {
                ll now = dp[i][j][k];
                if(!now)  continue;
                int r = (k == 1) ? num[i + 1] : 9;
                for(int p = (i == 0) ? 1 : 0;  p <= r; p++) {
                    int sum = j;
                    if(i + 1 < balance) sum += (balance - i - 1) * p;
                    else if(i + 1 > balance) sum -= (i + 1 - balance) * p;
                    dp[i + 1][sum][k == 1 && (p == num[i + 1])] += now;
                }
            }
    return dp[cnt - 1][O][1] + dp[cnt - 1][O][0];
}

ll cal(ll x) {
    cnt = 1;
    for(ll tmp = x; tmp; tmp /= 10) {
        num[cnt++] = tmp % 10;
    }
    std::reverse(num + 1, num + cnt);
    ll ans = 0;
    for(int i = 1; i < cnt; i++) {
        ans += cal1(x, i);
    }
    return ans;
}

ll f(ll x) {
    ll p = 9;
    ll tot = 0;
    while(p < x) {
        tot += cal(p);
        p = p * 10 + 9ll;
    }
    return cal(x) + tot;
}

inline void solve() {
    ll a, b;
    std::cin >> a >> b;
    std::cout << f(b) - f(a - 1) + (a == 0) << std::endl;
}


int main() {
    int _t; scanf("%d", &_t);
    while(_t--) solve();
    return 0;
}
