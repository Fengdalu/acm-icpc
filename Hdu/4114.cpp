#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
using namespace std;
#define cmin(a, b) a = min(a, b)

const int maxn = 51;
const int inf = 0x3f3f3f;
int n, m, K;
int dis[maxn][maxn];
int mask[maxn];
int p[maxn], f[maxn], ft[maxn];
int dp[maxn][1 << 8][1 << 8];


int main() {
    int _;
    scanf("%d", &_);
    int __ = 1;
    while(_--) {
        scanf("%d%d%d", &n, &m, &K);
        memset(dis, 0x3f, sizeof dis);
        memset(mask, 0, sizeof mask);
        for(int i = 0; i < m; i++) {
            int a, b, d;
            scanf("%d%d%d", &a, &b, &d);
            a--; b--;
            dis[b][a] = dis[a][b] = d;
        }
        for(int i = 0; i < n; i++) dis[i][i] = 0;
        for(int i = 0; i < K; i++) {
            scanf("%d%d%d", &p[i], &f[i], &ft[i]); p[i]--;
            int x, cnt; scanf("%d", &cnt);
            while(cnt--) {
                scanf("%d", &x);
                mask[--x] |= (1 << i);
            }
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++) if(i != k)
                for(int j = 0; j < n; j++)
                    cmin(dis[i][j], dis[i][k] + dis[k][j]);

        int tot = (1 << K);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < tot; j++)
                for(int k = 0; k < tot; k++)
                    dp[i][j][k] = inf;
        dp[0][0][0] = 0;
        int ans = 2e9;
        for(int mk2 = 0; mk2 < tot; mk2++)
            for(int mk1 = 0; mk1 < tot; mk1++) {

                for(int i = 0; i < n; i++) {
                    int now = dp[i][mk1][mk2];
                    if(now == inf) { continue; }
                    if(mk1 == tot - 1)  cmin(ans, now + dis[i][0]);
                    for(int j = 0; j < n; j++) {
                        cmin(dp[j][mk1][mk2 | mask[i] | mask[j]], now + dis[i][j]);
                    }
                    for(int j = 0; j < K; j++) if((1 << j & mk1) == 0){
                        int v = p[j];
                        if(1 << j & mk2)
                            cmin(dp[v][mk1 | (1 << j)][mk2 | mask[v]], now + dis[i][v] + min(f[j], ft[j]));
                        else
                            cmin(dp[v][mk1 | (1 << j)][mk2 | mask[v]], now + dis[i][v] + f[j]);
                    }
                }
            }

        printf("Case #%d: %d\n", __++, ans);
    }
    return 0;
}
