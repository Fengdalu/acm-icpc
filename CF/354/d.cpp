#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

const int maxn = 1010;
struct state { int a, b, c; state(int a, int b, int c): a(a), b(b), c(c){}; state(){}};
bool g[maxn][maxn][4][4];
int dp[maxn][maxn][4];
state pre[maxn][maxn][4];
char s[maxn];
int n, m;
const int inf = 1e9;
int xx, yy;

void cmin(int &a, int b) { a = min(a, b); }
const int vx[4] = {-1, 0, 1, 0};
const int vy[4] = {0, 1, 0, -1};

int dfs(int x, int y, int d) {
    dp[x][y][d] = 0;
    queue<state>q;
    q.push(state(x, y, d));
    while(q.size()) {
        state s = q.front();
        if(s.a < 1 || s.a > n || s.b < 1 || s.b > m) continue;
        int w = dp[s.a][s.b][s.c];
        q.pop();
        if(s.a == xx && s.b == yy) {
            return w;
        }
        for(int i = 0; i < 4; i++)
        if(g[s.a][s.b][i][s.c]) {
            int x = s.a + vx[i];
            int y = s.b + vy[i];
            if(x < 1 || x > n || y < 1 || y > m) continue;
            if(g[x][y][(i + 2) % 4][s.c] == false) continue;
            if(dp[x][y][s.c] != -1) continue;
            dp[x][y][s.c] = w + 1;
            q.push(state(x, y, s.c));
            pre[x][y][s.c] = s;
        }
        if(dp[s.a][s.b][(s.c + 1) % 4] != -1) continue;
        dp[s.a][s.b][(s.c + 1) % 4]  = w + 1;
        q.push(state(s.a, s.b, (s.c + 1) % 4));
        pre[s.a][s.b][(s.c + 1) % 4] = s;
    }
    return inf;
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
