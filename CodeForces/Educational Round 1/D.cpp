#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL long long

int vis[2000][2000];
char s[2000][2000];
int ans[2000000];
int n, m, Q;

const int V[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
int cnt;
int dfs(int x, int y) {
    if(s[x][y] == '*') return 1;
    if(vis[x][y] != -1) return 0;
    vis[x][y] = cnt;
    int tot = 0;
    for(int i = 0; i < 4; i++)
        if(1 <= x + V[i][0] && x + V[i][0] <= n)
        if(1 <= y + V[i][1] && y + V[i][1] <= m)
            tot += dfs(x + V[i][0], y + V[i][1]);
    return tot;
}

int main() {
    scanf("%d%d%d", &n, &m, &Q);
    for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    cnt = 1;
    memset(vis, -1, sizeof vis);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        if(vis[i][j] == -1 && s[i][j] == '.') {
            ans[cnt] = dfs(i, j);
            cnt++;
        }

    for(int i = 1; i <= Q; i++) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%d\n", ans[vis[x][y]]);
    }
    return 0;
}
