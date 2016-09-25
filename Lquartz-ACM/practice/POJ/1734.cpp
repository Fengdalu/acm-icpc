#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 111
#define Maxm 111111
#define MOD 100000007
int g[Maxn][Maxn], f[Maxn][Maxn], pre[Maxn][Maxn];
int path[Maxn], len;
int n, m;

//g[][] 边
//f[][] 最短路
//pre[][] 记录路径
int MinCircle() {
    int i, j, k, p;
    int mc = MOD;
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= n; ++j) {
            f[i][j] = g[i][j];
            
            if(g[i][j] < MOD && i != j) {
                pre[i][j] = j; //记录初始长度为1的路径
            }
            else {
                pre[i][j] = -1;
            }
        }
    }
    for(k = 1; k <= n; ++k) {
        for(i = 1; i < k ; ++i) {
            for(j = i + 1; j < k; ++j) {
                int tp = g[k][i] + f[i][j] + g[j][k];
                if(tp < mc) { //更新最小环和路径
                    mc = tp;
                    for(p = i, len = 0; p != -1; p = pre[p][j], len++) {
                        path[len] = p;
                    }
                    path[len++] = k;
                }
            } 
        }
        for(i = 1; i <= n; ++i) { //普通floyd过程
            for(j = 1; j <= n; ++j) {
                if(f[i][j] > f[i][k] + f[k][j]) {
                    f[i][j] = f[i][k] + f[k][j];
                    pre[i][j] = pre[i][k];
                }
            }
        }
    }
    return mc;
}

int main() {
    int i, j, u, v, w;
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                g[i][j] = MOD;
            }
            g[i][i] = 0;
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[u][v] = g[v][u] = min(g[u][v],w);
        }
        
        int res = MinCircle();
        if(res < MOD) {
            for(i = 0; i < len; i++) {
                if(i) printf(" ");
                printf("%d", path[i]);
            }
            printf("\n");
        }
        else {
            printf("No solution.\n"); 
        }
    }
    return 0;
}
