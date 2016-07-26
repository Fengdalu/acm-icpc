#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 100010;
const int inf = 1e9;
vector<int>g[maxn];
int dp[maxn][3][2];
int ncc;

void update(int &a, int b) { if(a == -1) a = b; else a = min(a, b); }

void dfs(int rt, int fa) {
    int nc = 0;
    for(auto &x: g[rt]) if(x != fa) {
        nc++;
        dfs(x, rt);
    }
    for(int i = 0; i < 3; i++) for(int j = 0; j < 2; j++) dp[rt][i][j] = -1;
    if(!nc) {
        ncc++;
        dp[rt][1][0] = 0;
        dp[rt][0][1] = 0;
        return;
    }
    int x = 0, y = 1;
    int f[2][3][2];
    memset(f, -1, sizeof f);
    f[0][0][0] = 0;
    for(auto &t: g[rt]) if(t != fa) {
        memset(f[y], -1, sizeof f[y]);
        for(int i = 1; i < 3; i++)
            for(int j = 0; j < 2; j++) if(~dp[t][i][j])
                for(int k = 0; k < 3; k++)
                    for(int p = 0; p < 2 - j; p++) if(~f[x][k][p]) {
                        int nj = i + k, nk = p + j, w = dp[t][i][j] + f[x][k][p] + i;
                        while(nj >= 3) nj -= 2;
                        update(f[y][nj][nk], w);
                        if(!nk && nj) update(f[y][nj - 1][nk + 1], w);
                        if(nj >= 2) update(f[y][nj - 2][nk], w);
                    }
        swap(x, y);
    }
    for(int i = 0; i < 3; i++) for(int j = 0; j < 2; j++) dp[rt][i][j] = f[x][i][j];
}

int main() {
    int _T;
    scanf("%d", &_T);
    while(_T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 1; i < n; i++) {
            int x, y; scanf("%d%d", &x, &y); x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ncc = 0;
        int root = 0;
        int ans;
        for(int i = 0; i < n; i++) if(g[i].size() - 1) root = i;
        dfs(root, -1);
        if(ncc & 1) ans = dp[root][0][1];
        else ans = dp[root][0][0];
        printf("%d\n", ans);
    }
    return 0;
}
