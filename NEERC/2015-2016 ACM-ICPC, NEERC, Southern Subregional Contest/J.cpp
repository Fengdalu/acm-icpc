#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 20


const int V[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int n, m;
char s[N][N];
bool dp[N][N][4];
bool vis[N][N];
int cnt = 0;

void dfs(int x, int y, int p)
{
    if(dp[x][y][p]) return;
    if(!vis[x][y]) vis[x][y] = true;
    dp[x][y][p] = true;
    int cc = 0;
    while(true)
    {
        int a = x + V[p][0], b = y + V[p][1];
        if(a < 0 || a > n - 1 || b < 0 || b > m - 1 || s[a][b] == '*') { p++; cc++; }
        else break;
        if(cc == 4) return;
        p %= 4;
    }
    dfs(x + V[p][0], y + V[p][1], p);
}


int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%s", &s[i]);
    memset(vis, 0, sizeof vis);
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    if(s[i][j] != '.' && s[i][j] != '*')
    {
        char p = s[i][j];
        if(p == 'R') dfs(i, j, 0);
        if(p == 'D') dfs(i, j, 1);
        if(p == 'L') dfs(i, j, 2);
        if(p == 'U') dfs(i, j, 3);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(vis[i][j]) cnt++;
    cout << cnt << endl;
    return 0;
}
