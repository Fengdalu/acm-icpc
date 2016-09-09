#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
const int MASK = (1<<20);
const int STATE = 2e6;
const int N = 13;
typedef long long ll;

struct HashMap {
    ll head[MASK];
    ll state[STATE];
    int nt[STATE];
    int tot;

    void init() {
        tot = 0;
        memset(head, -1, sizeof head);
    }

    ll get(int st) {
        for(int k = head[st&(MASK-1)]; k != -1; k = nt[k]) {
            if(state[k] == st) return k;
        }
        state[tot] = st;
        nt[tot] = head[st&(MASK-1)];
        head[st&(MASK-1)] = tot++;
        if(tot >= STATE) exit(2);
        return tot - 1;
    }
} hm[2];

ll dp[2][STATE];
char s[N][N+N+N];

inline int en(std::vector<int> &f) {
    int tot = 0;
    for(int i = f.size() - 1; i != -1; i--) {
        tot = (tot << 2) + f[i];
    }
    return tot;
}

inline void solve() {
    static int _t = 1;
    memset(dp, 0, sizeof dp);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", s[i]);

    int cur = 0, next = 1;
    hm[cur].init(); hm[next].init();
    hm[cur].get(0);
    dp[0][hm[cur].get(0)] = 1;
    int endx, endy;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '.') {
                endx = i;
                endy = j + 1;
            }
        }

    // row 1, col 0
    bool flag = true;
    for(int i = 1; i <= n; i++) if(flag)
        for(int j = 0; j <= m; j++) if(flag){
            if(i == endx && j == endy)  {
                flag = false;
                break;
            }
            memset(dp[next], 0, sizeof dp[next]);
            hm[next].init();
            for(int p = 0; p < hm[cur].tot; p++) {
                ll state = hm[cur].state[p];
                std::vector<int> f(m + 1);
                ll now = dp[cur][p];
                //std::cout << i << " " << j << " " << now << ": ";
                for(int k = 0; k < m + 1; k++) {
                    f[k] = state & 3;
                    //std::cout << f[i] << " ";
                    state >>= 2;
                }
                //std::cout << std::endl;
                if(j != m) {
                    int left = f[j], up = f[j + 1];
                    if(s[i][j] == '.') {
                        if(left == 1 && up == 2) {
                            if(i == endx && j + 1 == endy) {
                                f[j] = 0;
                                f[j + 1] = 0;
                                dp[next][hm[next].get(en(f))] += now;
                            }
                        }
                        else if(left == 2 && up == 1) {
                            f[j] = 0;
                            f[j + 1] = 0;
                            dp[next][hm[next].get(en(f))] += now;
                        }
                        else if(left == 1 && up == 1) {
                            f[j] = f[j + 1] = 0;
                            int k = j + 2;
                            int tot = 1;
                            while(true) {
                                if(f[k] == 1) tot++;
                                else if(f[k] == 2)tot--;
                                if(tot == 0) break;
                                k++;
                            }
                            f[k] = 1;
                            dp[next][hm[next].get(en(f))] += now;
                        }
                        else if(left == 2 && up == 2) {
                            f[j] = f[j + 1] = 0;
                            int k = j - 1;
                            int tot = -1;
                            while(true) {
                                if(f[k] == 1) tot++;
                                else if(f[k] == 2)tot--;
                                if(tot == 0) break;
                                k--;
                            }
                            f[k] = 2;
                            dp[next][hm[next].get(en(f))] += now;
                        }
                        else if(((left == 0) && (up != 0)) || ((left != 0) && (up == 0))) {
                            dp[next][hm[next].get(en(f))] += now;
                            std::swap(f[j], f[j + 1]);
                            dp[next][hm[next].get(en(f))] += now;
                        }
                        else if(left == 0 && up == 0) {
                            f[j] = 1; f[j + 1] = 2;
                            dp[next][hm[next].get(en(f))] += now;
                        }
                    }
                    else {
                        if(left == 0 && up == 0) {
                            dp[next][hm[next].get(en(f))] += now;
                        }
                    }
                }
                else {
                    if(f[m] == 0) {
                        for(int i = m; i >= 1; i--) f[i] = f[i - 1];
                        f[0] = 0;
                        dp[next][hm[next].get(en(f))] += now;
                    }
                }
            }
            std::swap(next, cur);
        }
    printf("%lld\n", dp[cur][hm[cur].get(0)]);
}

int main() {
    solve();
    return 0;
}

