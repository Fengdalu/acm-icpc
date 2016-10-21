/*
 * dp[u][i] 表示结点 u 已经和要连通的结点集合 ( 2^k 表示 ) i 连通的最小花费 ,
 * 初始化将 k 个点和 n 个点 dp[u][1<<i] 初始化为最短路 ,
 * , dp[u][0]=0, 加入队列
 * 利用 spfa 求出 dp 数组
 * 状态转移分三部分 :
 *  1) dp[u][su] 利用 dp[u][sub] + dp[u][su^sub] 更新 , sub 为 su 子集
 *  2) dp[u][su] 更新相邻的 dp[v][sv]
 *  3) 将 k 中不属于 su 的点与u连接 , 利用 u, k 的最短路
 */

// hdu 4085
// 求斯坦纳森林, 再森林合并为全集
#include <bits/stdc++.h>
#define MOD 0x3f3f3f3f
typedef std::pair<int, int> PII;
#define MP std::make_pair
#define PB push_back
#define cmin(x, y) x = std::min(x, y)
#define SZ size()
#define AA first
#define BB second
using namespace std;
const int Maxn = 55;
const int Maxk = 14;
const int MSta = 1 << 15;
int dp[Maxn][MSta];
vector<PII> g[Maxn];
int gg[Maxn][Maxn];
int mp1[Maxn], mp2[Maxn];
int n, m, K;
vector<int> split[Maxk];
int gao[MSta];
int has (int sta) {
    int i, a = 0, b = 0, u;
    for (i = 0; i < 2 * K; i++) {
        if ((1<<i) & sta) {
            u = mp1[i];
            if (u <= K) a++;
            else b++;
        }
    }
    if (a == b) return true;
    else return false;
}
int ans;
queue<PII> que;
int inque[Maxn][MSta];
int doit() {
    int i, j, k, u, v, w, su, sv, sub, vv, tp;
    int kk = 2 * K;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < (1<< kk); j++) dp[i][j] = MOD, inque[i][j] = 0;
        dp[i][0] = 0; inque[i][0] = 0;
    }
    while(!que.empty()) que.pop();
    memset(mp2, 0, sizeof(mp2));
    for(i = 1, j = 0; i <= K; i++, j++)mp1[j] = i, mp2[i] = 1<<j;
    for(i = n - K + 1; i <= n; i++, j++)mp1[j] = i, mp2[i] = 1<<j;
    for(i = 0; i < kk; i++) {
        for(u = 1; u <= n; u++) {
            cmin(dp[u][1<<i], gg[u][mp1[i]]);
            inque[u][1<<i] = 1;
            que.push(MP(u, 1<<i));
        }
    }
    while(!que.empty()) {
        u = que.front().AA; su = que.front().BB; que.pop();
        sub = su;
        tp = dp[u][su];
        do {
            sv = sub ^ su;
            cmin(tp, dp[u][sub] + dp[u][sv]);
            sub = (sub - 1) & su;
        }while(sub != su);
        if(tp < dp[u][su]) dp[u][su] = tp;
        for(j = 0; j < g[u].SZ; j++) {
            v = g[u][j].AA; w = g[u][j].BB;
            if(su & mp2[v]) continue;
            sv = su | mp2[v];
            if(dp[v][sv] > dp[u][su] + w) {
                dp[v][sv] = dp[u][su] + w;
                if(!inque[v][sv]) {
                    inque[v][sv] = 1;
                    que.push(MP(v, sv));
                }
            }
        }
        for(j = 0; j < kk; j++) {
            if(su & (1<<j)) continue;
            sv = su | (1<<j);
            if(dp[u][sv] > dp[u][su] + gg[u][mp1[j]]) {
                dp[u][sv] = dp[u][su] + gg[u][mp1[j]];
                if(!inque[u][sv]) {
                    inque[u][sv] = 1;
                    que.push(MP(u, sv));
                }
            }
        }
        inque[u][su] = 0;
    }

    for(i = 0; i <= kk; i++) split[i].clear();
    for(i = 0; i < (1<<kk); i++) {
        split[__builtin_popcount(i)].PB(i);
        gao[i] = MOD;
        if(has(i)) {
            for(j = 1; j <= n; j++) {
                cmin(gao[i], dp[j][i]);
            }
        }
    }
    for(i = 1; i <= kk; i++) {
        for(j = 0; j <split[i].SZ; j++) {
            su = split[i][j];
            for(sub = su - 1 & su; sub; sub = sub - 1 & su) {
                sv = su ^ sub;
                cmin(gao[su], gao[sub] + gao[sv]);
                sub = (sub - 1) & su;
            }
        }
    }
    return gao[(1<<kk) - 1];
}
int main() {
    int i,j,k,u,v,w;
    int te;
    scanf ("%d", &te);
    for (int ca = 1; ca <= te; ca ++) {
        scanf ("%d%d%d", &n, &m, &K);
        for (i = 1; i <= n; i++) g[i].clear();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) gg[i][j] = MOD;
            gg[i][i] = 0;
        }
        for (i = 0; i < m; i++) {
            scanf ("%d%d%d", &u, &v, &w);
            cmin (gg[u][v], w);
            cmin (gg[v][u], w);
        }
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                if (gg[i][j] < MOD) {
                    g[i].PB (MP (j, gg[i][j]) );
                    g[j].PB (MP (i, gg[i][j]) );
                }
            }
        }
        for (k = 1; k <= n; k++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    cmin (gg[i][j], gg[i][k] + gg[k][j]);
                }
            }
        }
        ans = 0;
        ans = doit();
        if(ans >= MOD) printf("No solution\n");
        else printf ("%d\n", ans);
    }
    return 0;
}
