#include <bits/stdc++.h>

int dp[11][11][11];
int w[11][11][11];
#define cmax(x, y) x = std::max(x, y)

int main() {
  freopen("commandos.in", "r", stdin);
  int T; scanf("%d", &T);
  while(T--) {
    int n; scanf("%d", &n);
    memset(dp, 0, sizeof dp);
    memset(w, 0, sizeof w);
    while(n--) {
      int f, x, y, sum;
      scanf("%d%d%d%d", &f, &x, &y, &sum);
      w[f][x][y] += sum;
    }
    dp[10][1][1] = w[10][1][1];
    for(int i = 10; i >= 0; i--)
      for(int x = 1; x <= 10; x++)
        for(int y = 1; y <= 10; y++) {
          int now = dp[i][x][y];
          if(x < 10) cmax(dp[i][x + 1][y], now + w[i][x + 1][y]);
          if(y < 10) cmax(dp[i][x][y + 1], now + w[i][x][y + 1]);
          if(i) cmax(dp[i - 1][x][y], now + w[i - 1][x][y]);
        }
    int ans = 0;
    for(int i = 0; i <= 10; i++)
      for(int j = 0; j <= 10; j++)
        for(int k = 0; k <= 10; k++)
          cmax(ans, dp[i][j][k]);
    printf("%d\n", ans);
  }
  return 0;
}
