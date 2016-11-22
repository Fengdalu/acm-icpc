#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define PII pair<int, int>
#define AA first
#define BB second
#define N 2000

const char *s = "DIMA";
char c[N][N];
int dp[N][N];
bool vis[N][N];
int n, m;
const PII D[4] = { PII(1, 0), PII(-1, 0), PII(0, 1), PII(0, -1) };

int dfs(int x, int y, int p)
{
    if(x < 0 || y < 0 || x >= n || y >= m) return 0;
    if(c[x][y] != s[p]) return 0;
    if(vis[x][y]) return -1;
    if(dp[x][y] != -1) return dp[x][y];
//    cout << x << " " << y << " " << s[p] << endl;

    vis[x][y] = true;

    bool flg = false;
    dp[x][y] = 0;
    for(int i = 0; i < 4; i++)
    {
        int tmp = dfs(x + D[i].AA, y + D[i].BB, (p + 1) % 4);
        if(tmp == -1) { flg = true; break; }
        dp[x][y] = max(dp[x][y], tmp);
    }
    if(p == 3) dp[x][y]++;
    vis[x][y] = false;

    if(flg) return -1;
    else return dp[x][y];
}

int main()
{
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%s", c[i]);
    memset(dp, -1, sizeof dp);
    int ans = 0;
    bool flg = false;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    if(c[i][j] == 'D')
    {
        int tmp = dfs(i, j, 0);
        if(tmp == -1) { flg = true;  break; }
        ans = max(ans, tmp);
    }
    if(flg) printf("Poor Inna!");
    else if(ans == 0) printf("Poor Dima!\n");
    else printf("%d\n", ans);
    return 0;
}