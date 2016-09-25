#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Maxn 44
#define PB push_back
#define SZ size()
typedef long long LL;
const LL MOD = 1000000007;

vector<int> g[Maxn];
int g1[Maxn][Maxn];
vector<int> team[Maxn];
int dp[1<<21];
LL all, gao[Maxn][Maxn];
int n, m, ncnt, now, cur;
int group[Maxn], deg[Maxn], belong[Maxn];

void calc(int n) {
    int i, j;
    for(i = 0; i <= n; i++) gao[i][0] = 1;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            gao[i][j] = (gao[i - 1][j] + gao[i - 1][j - 1]) % MOD;
        }
    }
}

void dfs(int u) {
    belong[u] = ncnt;
    team[ncnt].PB(u);
    for(int i = 1; i <= n; i++) {
        if(g1[u][i] && !belong[i]) {
            dfs(i);
        }
    }
}

// dp[status] 当前图中结点01表示, 初始化只剩一个点dp[1<<j]=1
// deg[] 结点度数
// g[][] vector存边
// group[] 将当前块结点映射到group的0~now位置
// now当前块节点数
// 各个连通块求dp值, 乘上组合数C[n][now], 没处理一块n-=now
int doit(int status) {
    if(dp[status] != -1) return dp[status];
    LL sum = 0;
    int i, j, u, v;
    for(i = 0; i < now; i++) {
        u = group[i];
        if(deg[u] == 0) {
            deg[u] = -1;
            for(j = 0; j < g[u].SZ; j++) {
                v = g[u][j];
                deg[v]--;
            }
            sum += doit(status ^ (1<<i));
            for(j = 0; j < g[u].SZ; j++) {
                v = g[u][j];
                deg[v]++;
            }
            deg[u] = 0;
        }
    }
    return (dp[status] = sum % MOD);
}

int main() {
    int i, j, u, v, w;
    calc(42);
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 1; i <= n; i++) {
            g[i].clear();
            deg[i] = 0;
            belong[i] = 0;
            for(j = 1; j <= n; j++) {
                g1[i][j] = 0;
            }
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            g1[u][v] = g1[v][u] = 1;
            deg[v]++;
        }
        ncnt = 0;
        for(i = 1; i <= n; i++) {
            if(deg[i] == 0 && belong[i] == 0) {
                ncnt++;
                team[ncnt].clear();
                dfs(i);
            }
        }
        all = 1;
        for(i = 1; i <= ncnt; i++) {
            now = team[i].SZ;
            if(now > 2) {
                for(j = 0; j < team[i].SZ; j++) {
                    group[j] = team[i][j];
                }
                for(j = 0; j < (1<<now); j++) dp[j] = -1;
                for(j = 0; j < now; j++) dp[(1<<j)] = 1;
                LL tp = doit((1<<now) - 1);
                all = (all * tp) % MOD;
            }
            all = (all * gao[n][now]) % MOD;
            n -= now;
        }
        printf("%I64d\n", all);
    }
    return 0;
}
