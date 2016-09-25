#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define Maxn 111
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dp[Maxn][Maxn];
int n, m;
int g[Maxn][Maxn];

int dfs(int x, int y) {
    int &tp = dp[x][y];
    if(tp != -1) return tp;
    tp = 0;
    int i = 0;
    for(i = 0; i < 4; i++) {
        if(g[x][y] <= g[x + dx[i]][y + dy[i]]) continue;
        tp = max(tp, dfs(x + dx[i], y + dy[i]));
    }
    tp ++;
    return tp;
}

int main() {
    int i, j, k;
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 0; i <= n + 1; i++) {
            for(j = 0; j <= m + 1; j++) {
                dp[i][j] = 0;
            }
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                dp[i][j] = -1;
                scanf("%d", &g[i][j]);
            }
        }
        int ans = 0;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                dfs(i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
