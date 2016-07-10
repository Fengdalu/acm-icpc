#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int vx[4] = {0, -1, 0, 1};
const int vy[4] = {1, 0, -1, 0};
int vis[60][60];
int f[600][60];
int h[60][60];
int n, m;


bool dfs(int a, int b, int p) {
    if(a < 0 || a >= n || b < 0 || b >= m) return false;
    vis[a][b] = true;
    if(h[a][b] >= p) return true;
    for(int i = 0; i < 4; i++) {
        int x = a + vx[i];
        int y = b + vy[i];
        if(x >= 0 && x < n && b >= 0 && b < m) {
            if(!vis[x][y])
                if(!dfs(x, y, p)) return false;
        }
        else return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    int ii = 0;
    while(T--) {
        scanf("%d%d", &n, &m);
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &h[i][j]);
        int tot = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int add = h[i][j];
                for(int p = 1000; p >= h[i][j]; p--) {
                    memset(vis, 0, sizeof vis);
                    if(dfs(i, j, p)) { add = p; break; }
                }
                tot += add - h[i][j];
            }
        }
        printf("Case #%d: %d\n", ++ii, tot);

    }
    return 0;
}
