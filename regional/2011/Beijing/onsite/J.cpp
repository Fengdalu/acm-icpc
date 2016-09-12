#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <cassert>

#define AA first
#define BB second
#define MP std::make_pair
#define PII std::pair<int, int>

int n, m, K;
char a[11][11];
bool vis[11][11];
const int VX[] = {0, -1,  0, 1, 1,  1, -1, -1};
const int VY[] = {1,  0, -1, 0, 1, -1, -1,  1};
int ANS;

/*
void out(int a[10][10]) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
}
*/

void down() {
    int p = -1;
    for(int j = 1; j <= m; j++) {
        int I = n;
        for(int i = n; i >= 0; i--) {
            if(a[i][j]) a[I--][j] = a[i][j];
        }
        while(I >= 0) a[I--][j] = 0;
    }
}

bool vis1[10][10];
int dfs1(int x, int y, int cc) {
    if(x < 0 || x > n || y < 0 || y > m) return 0;
    if(vis1[x][y]) return 0;
    if(a[x][y] != cc) return 0;
    vis1[x][y] = true;
    int tot = 0;
    for(int i = 0; i < 8; i++) {
        tot += dfs1(x + VX[i], y + VY[i], cc);
    }
    return tot + 1;
}


int deal(int i, int j, bool vis[10][10]) {
    static int ans, target, tot;
    ans = 0;
    target = a[i][j];
    tot = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) vis1[i][j] = false;
    /*
       int l = 0, r = 0;
       q[l] = MP(i, j);
       vis[i][j] = true;
       while(l <= r) {
       PII t = q[l++];
       tot++;
       vis[t.AA][t.BB] = true;
       vis[t.AA][t.BB] = true;
       for(int i = 0; i < 8; i++) {
       int xx = t.AA + VX[i], yy = t.BB + VY[i];
       if(vis[xx][yy] || a[xx][yy] != target) continue;
       vis[xx][yy] = true;
       q[++r] = (MP(xx, yy));
       }
       }
       */
    tot = dfs1(i, j, target);
    if(tot >= 3) {
        ans += tot * tot;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                if(vis1[i][j]) a[i][j] = 0, vis[i][j] = true;
            }
        down();
        int J = 1;
        for(int j = 1; j <= m; j++) {
            bool flag = false;
            for(int i = 1; i <= n; i++) if(a[i][j]) flag = true;
            if(flag)  {
                for(int i = 1; i <= n; i++) a[i][J] = a[i][j];
                J++;
            }
        }
        while(J <= m) {
            for(int i = 1; i <= n; i++) a[i][J] = 0;
            J++;
        }
    }
    return ans;
}

int color[9];
int fx() {
    for(int i = 1; i <= K; i++) color[i] = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) if(a[i][j])
            if(a[i][j])
                color[a[i][j]]++, cnt++;
    int tot = 0;
    for(int i = 0; i <= K; i++) if(color[i] >= 3)
        tot += color[i] * color[i];
    return tot;
}

void dfs(int ans) {
    ANS = std::max(ANS, ans);
    if(ans + fx() <= ANS) {
        return;
    }
    char b[10][10];
    bool vis[10][10];
    memcpy(b, a, sizeof(b));
    memset(vis, 0, sizeof vis);
    int flag = false;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) if(a[i][j] && !vis[i][j]) {
            flag = true;
            int profile = deal(i, j, vis);
            if(profile == 0) continue;
            dfs(profile + ans);
            memcpy(a, b, sizeof(a));
        }
}

void solve() {
    if(scanf("%d%d%d", &n, &m, &K) == -1) exit(0);
    ANS = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            a[i][j] = x;
        }
    dfs(0);
    printf("%d\n", ANS);
}

int main() {
    for(;;solve());
    return 0;
}
