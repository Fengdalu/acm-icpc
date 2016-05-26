#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1010;
bool g[maxn][maxn][4][4];
int dp[maxn][maxn][4];
char s[maxn];
int n, m;
const int inf = 1e9;
int xx, yy;

void cmin(int &a, int b) { a = min(a, b); }

int dfs(int x, int y, int d) {
    if(x == xx && y == yy) return 0;
    if(x < 1 || x > n || y < 1 || y > m) return inf;
    if(dp[x][y][d] != -1) return dp[x][y][d];
    dp[x][y][d] = inf;

    cmin(dp[x][y][d], dfs(x, y, (d + 1) % 4) + 1);
    if(x > 1 && g[x][y][0][d] && g[x - 1][y][2][d]) cmin(dp[x][y][d], dfs(x - 1, y, d) + 1);
    if(y < m && g[x][y][1][d] && g[x][y + 1][3][d]) cmin(dp[x][y][d], dfs(x, y + 1, d) + 1);
    if(x < n && g[x][y][2][d] && g[x + 1][0][d]) cmin(dp[x][y][d], dfs(x + 1, y, d) + 1);
    if(y > 0 && g[x][y][3][d] && g[x][y][1][d]) cmin(dp[x][y][d], dfs(x, y - 1, d) + 1);
    return dp[x][y][d];
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for(int j = 1; j <= m; j++) {
            if(s[j] == '+') {
                g[i][j][0][0] = g[i][j][2][0] = true;
                g[i][j][1][0] = g[i][j][3][0] = true;
            }
            else if(s[j] == '-') {
                g[i][j][1][0] = g[i][j][3][0] = true;
            }
            else if(s[j] == '|') {
                g[i][j][0][0] = g[i][j][2][0] = true;
            }
            else if(s[j] == '^') {
                g[i][j][0][0] = true;
            }
            else if(s[j] == '>') {
                g[i][j][1][0] = true;
            }
            else if(s[j] == 'v') {
                g[i][j][2][0] = true;
            }
            else if(s[j] == '<') {
                g[i][j][3][0] = true;
            }
            else if(s[j] != '*'){
                g[i][j][0][0] = g[i][j][2][0] = true;
                g[i][j][1][0] = g[i][j][3][0] = true;
                if(s[j] == 'U') g[i][j][0][0] = false;
                else if(s[j] == 'R') g[i][j][1][0] = false;
                else if(s[j] == 'D') g[i][j][2][0] = false;
                else if(s[j] == 'L') g[i][j][3][0] = false;
            }
        }
    }
    for(int k = 0; k < 3; k++) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                for(int p = 0; p < 4; p++)
                    g[i][j][(p + 1) % 4][k + 1] = g[i][j][p][k];
    }
    memset(dp, -1, sizeof dp);
    int a, b;
    scanf("%d%d%d%d", &a, &b, &xx, &yy);
    int ans = dfs(a, b, 0);
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
