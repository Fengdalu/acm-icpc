#include <bits/stdc++.h>
#define PB push_back
#define OP begin()
#define ED end()
#define SZ size()

const int N = 1000;
typedef long long ll;
int a[N], b[N];
int id[N][N];
int fa[N*N];
ll sz[N*N];
bool vis[N][N];

int find(int x) { return (fa[x] == x) ? (fa[x]) : (fa[x] = find(fa[x])); }

    //freopen("a.in", "r", stdin);
int main() {
    int _t; scanf("%d", &_t);
    int R, C;
    for(int cas = 1; cas <= _t; cas++) {
        scanf("%d%d", &R, &C);
        int m; scanf("%d", &m);
        std::vector<int> X, Y;
        for(int j = 0; j < m; j++) scanf("%d%d", a + j, b + j);
        for(int i = 0; i < m; i++) {
            int x = a[i], y = b[i];
            if(x > 1) X.PB(x - 1);
            if(x < R) X.PB(x + 1);
            X.PB(x);
            if(y > 1) Y.PB(y - 1);
            if(y < C) Y.PB(y + 1);
            Y.PB(y);
        }
        X.PB(R + 1); Y.PB(C + 1);
        X.PB(1); Y.PB(1);
        std::sort(X.OP, X.ED); std::sort(Y.OP, Y.ED);
        X.erase(std::unique(X.OP, X.ED), X.ED);
        Y.erase(std::unique(Y.OP, Y.ED), Y.ED);
        int tot = 0;
        for(int i = 0; i < X.SZ - 1; i++)
            for(int j = 0; j < Y.SZ - 1; j++) {
                id[i][j] = tot++;
                sz[id[i][j]] = 1ll * (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
            }
        for(int i = 0; i < tot; i++) fa[i] = i;
        memset(vis, 0, sizeof vis);

        for(int i = 0; i < m; i++) {
            int x = a[i], y = b[i];
            x = std::lower_bound(X.OP, X.ED, x) - X.OP;
            y = std::lower_bound(Y.OP, Y.ED, y) - Y.OP;
            vis[x][y] = true;
        }

        for(int i = 0; i < X.SZ - 1; i++)
            for(int j = 0; j < Y.SZ - 1; j++) if(!vis[i][j]) {
                int u = find(id[i][j]);
                if(i + 1 <= X.SZ - 2 && !vis[i + 1][j]) {
                    int v = find(id[i + 1][j]);
                    ll t = sz[v]; sz[v] = 0;
                    sz[u] += t;
                    fa[v] = u;
                }
                if(j + 1 <= Y.SZ - 2 && !vis[i][j + 1]) {
                    int v = find(id[i][j + 1]);
                    ll t = sz[v]; sz[v] = 0;
                    sz[u] += t;
                    fa[v] = u;
                }
            }

        std::vector<ll>ans;
        for(int i = 0; i < X.SZ - 1; i++)
            for(int j = 0; j < Y.SZ - 1; j++) if(find(id[i][j]) == id[i][j] && !vis[i][j]) {
                ans.push_back(sz[id[i][j]]);
            }
        std::sort(ans.OP, ans.ED);
        printf("Case #%d:\n%u\n", cas, ans.SZ);
        for(int i = 0; i < ans.SZ; i++) {
            printf("%I64d", ans[i]);
            if(i == ans.SZ - 1) puts("");
            else printf(" ");
        }
    }
    return 0;
}

/*
5

3 3
2
1 2
2 1

3 3
1
2 2

3 3
4
1 2
2 1
2 3
3 2

3 3
5
1 1
1 3
2 2
3 1
3 3

99999 99999
8
1 99994
2 99995
3 99996
4 99996
5 99997
5 99998
5 99999
5 99996
*/
