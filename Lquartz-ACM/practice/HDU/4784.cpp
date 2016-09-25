#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 555
#define Maxm 111111
struct node {
    int u, v, c, t, next;
}e[Maxm];
int tot, last[Maxn];
int N, M, B, K, R, T;
int dp[230][Maxn][5];
int p[Maxn];
int ok[Maxn];
void adde(int u, int v, int t, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].t = t; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
}
int main() {
    int i, j, b, t, tt, bb, k, u, v, w, tp;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d%d%d%d%d%d", &N, &M, &B, &K, &R, &T);
        for(k = 0; k < K; k++) {
            for(i = 1; i <= N; i++) {
                scanf("%d", &p[k * N + i]);
            }
        }
        memset(ok, 0, sizeof(ok));
        for(i = 0; i < K; i++) ok[i * N + 1] = ok[i * N + N] = 1;
        for(i = 0; i <= K * N; i++) last[i] = -1;
        tot = 0;
        for(i = 0; i < M; i++) {
            scanf("%d%d%d%d", &u, &v, &t, &w);
            if(u != N) adde(u, v, t, w);
            if(ok[u] || ok[v]) continue;
            for(k = 1; k < K; k++) {
                adde(k * N + u, k * N + v, t, w);
            }
        }
        for(k = 0; k < K; k++) {
            for(i = 2; i <= N - 1; i++) {
                u = k * N + i;
                v = ((k + 1) % K) * N + i;
                adde(u, v, 1, 0);
            }
        }
        for(i = 0; i < T + 20; i++) {
            for(j = 0; j < K * N + 20; j++) {
                for(b = 0; b <= B; b++) dp[i][j][b] = -MOD;
            }
        }
        dp[0][1][0] = R;
        for(t = 0; t < T; t++) {
            for(i = 1; i <= K * N; i++) {
                for(j = last[i]; j != -1; j = e[j].next) {
                    tt = t + e[j].t;
                    if(tt > T) continue;
                    v = e[j].v;
                    for(b = 0; b <= B; b++) {
                        tp = dp[t][i][b] - e[j].c;
                        if(tp < 0) continue;
                        cmax(dp[tt][v][b], tp);
                    }
                    if(ok[i]) continue;
                    for(b = 0; b < B; b++) {
                        tp = dp[t][i][b] - e[j].c - p[i];
                        if(tp < 0) continue;
                        cmax(dp[tt][v][b + 1], tp);
                    }
                    for(b = 1; b <= B; b++) {
                        tp = dp[t][i][b] - e[j].c + p[i];
                        if(tp < 0) continue;
                        cmax(dp[tt][v][b - 1], tp);
                    }
                }
            }
        }
        int ans = -MOD;
        for(i = 1; i <= T; i++) {
            for(b = 0; b <= B; b++) {
                cmax(ans, dp[i][N][b]);
            }
        }
        printf("Case #%d: ", ca);
        if(ans >= 0) printf("%d\n", ans);
        else printf("Forever Alone\n");
    }
    return 0;
}
