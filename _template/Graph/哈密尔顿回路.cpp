/*
 * 设$dp[i][j]$表示站在$i$点, 盘面状态为$j$的最短路,
 * 最后答案需要遍历所有$j == (1 << n) - 1$
 * 注意有的题需要用$Floyd$预处理最短路
 */
#include <bits/stdc++.h>
const int N = 18;
const int INF = 1e9+7;
int f[N][N];
int dp[N][(1 << N)];
int n, m;
int main() {
  int T; scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++) f[i][j] = INF;
    for(int i = 1; i <= n; i++) f[i][i] = 0;
    for(int i = 0; i < m; i++) {
      int x, y, z; scanf("%d%d%d", &x, &y, &z);
      // 处理重边
      f[x][y] = std::min(f[x][y], z);
      f[y][x] = std::min(f[y][x], z);
    }
    for(int k = 1; k <= n; k++)
      for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
          f[i][j] = std::min(f[i][k] + f[k][j], f[i][j]);

    for(int i = 1; i <= n; i++)
      for(int j = 0; j < 1 << (n + 1); j++) dp[i][j] = INF;

    dp[1][2] = 0;

    for(int j = 0; j < (1 << (n + 1)); j++) {
      for(int i = 1; i <= n; i++)
        if(((1 << i) & j) != 0) {
          for(int k = 1; k <= n; k++)
            dp[k][(1 << k) | j] =
              std::min(dp[i][j] + f[i][k]
                  , dp[k][(1 << k) | j]);
        }
    }
    int ans = INF;
    for(int i = 1; i <= n; i++) {
      ans = std::min(ans, dp[i][(1 << (n + 1)) - 2] + f[i][1]);
    }
    printf("%d\n", ans);
  }
  return 0;
}

