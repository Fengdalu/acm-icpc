#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> mp;
int sum;
int dp[1<<16];
char ss[20], tt[20];
int g[20][20];
int n, m;

int getid(char str[]) {
    string s(str);
    int ret = mp[s];
    if(ret == 0) {
        mp[s] = ++sum;
        ret = sum;
    }
    return ret - 1;
}

// dp[status] 当前图中结点01表示
// deg[] 结点度数
// g[][] 邻接矩阵
int doit(int status) {
    if(status == 0) return 1;
    if(dp[status] != -1) return dp[status];
    int sum = 0;
    int i, j;
    int deg[20] = {0};
    for(i = 0; i < n; i++) {
        if(status & (1<<i)) {
            for(j = 0; j < n; j++) {
                if(i != j && (status & (1<<j)) && g[i][j]) {
                    deg[j]++;
                }
            }
        }
        else {
            deg[i] = -1;
        }
    }
    for(i = 0; i < n; i++) {
        if(deg[i]) continue;
        sum += doit(status^(1<<i));
    }
    return (dp[status] = sum);
}


int main() {
    int i, j, u, v;
    while(scanf("%d", &m) != EOF) {
        memset(dp, -1, sizeof(dp));
        memset(g, 0, sizeof(g));
        mp.clear();
        sum = 0;
        for(i = 0; i < m; i++) {
            scanf("%s%s", ss, tt);
            u = getid(ss), v = getid(tt);
            g[u][v] = 1;
        }
        n = sum;
        int ans = doit((1<<sum) - 1);
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
IORI KYO
MARY SHERMIE
KYO ANDY
SHERMIE ANDY
3
IORI KYO
KYO CLARK
CLARK IORI
*/
