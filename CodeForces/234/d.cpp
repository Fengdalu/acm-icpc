#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

#define cmin(x, y) x = std::min(x, y)
const int inf = 1e9 + 7;
const int N = 1e5 + 10;
int fa[N];
int find(int x) { if(fa[x] == x) return x; return fa[x] = find(fa[x]); }
int f[600][600];
int C[600];
int BL[N];
int u[N], v[N], w[N];

int main() {
    int n, m, K;
    scanf("%d%d%d", &n, &m, &K);
    for(int i = 0; i < K; i++) scanf("%d", C + i);
    for(int i = 1; i <= n; i++) fa[i] = i;
    int op;
    op = 0;
    for(int i = 0; i < K; i++) {
        for(int j = op + 1; j <= op + C[i]; j++)
            BL[j] = i;
        op += C[i];
    }
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", u + i, v + i, w + i);
        if(w[i] == 0) {
            if(find(u[i]) != find(v[i])) fa[find(u[i])] = find(v[i]);
        }
    }
    op = 0;
    bool flag = true;
    for(int i = 0; i < K; i++) {
        int ff = find(op + 1);
        for(int j = op + 1; j <= op + C[i]; j++)
            if(ff != find(j)) flag = false;
        op += C[i];
    }
    if(!flag) {
        puts("No");
        return 0;
    }
    for(int i = 0; i < K; i++)
        for(int j = 0; j < K; j++)
            f[i][j] = inf;
    for(int i = 0; i < K; i++) f[i][i] = 0;
    for(int i = 0; i < m; i++) {
        int U = BL[u[i]], V = BL[v[i]], P = w[i];
        if(U != V) {
            cmin(f[U][V], P);
            cmin(f[V][U], P);
        }
    }
    for(int k = 0; k < K; k++)
        for(int i = 0; i < K; i++)
            for(int j = 0; j < K; j++)
                cmin(f[i][j], f[i][k] + f[k][j]);
    puts("Yes");
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++)
            if(f[i][j] >= inf) printf("-1 ");
            else printf("%d ", f[i][j]);
        puts("");
    }
    return 0;
}

