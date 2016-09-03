#include <vector>
using namespace std;
const int POW = 18;
const int N = 1e5;
/*
 * p[i][j]: $i$的第$j$倍祖先
 * d[i]: $i$在树中的深度
 * edge[N]: 边集合
 * dfs(u, fa): 求出$p, d$
 * lca(a, b): 求出$(a, b)$的最近公共祖先
 */
int p[N][POW];
int d[N];
vector<int>edge[N];
void dfs(int u, int fa){
    d[u] = d[fa]+1;
    p[u][0] = fa;
    for(int i = 1; i < POW; i++) p[u][i] = p[p[u][i - 1]][i - 1];
    int sz=edge[u].size();
    for(int i=0;i<sz;i++){
        int v = edge[u][i];
        if(v == fa) continue;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if(d[a] > d[b]) a ^= b, b ^= a, a ^= b;
    if(d[a] < d[b]) {
        int del = d[b] - d[a];
        for(int i = 0; i < POW; i++) if(del & (1 << i)) b = p[b][i];
    }
    if(a != b) {
        for(int i = POW - 1; i >= 0; i--)
            if(p[a][i] != p[b][i])
                a = p[a][i], b = p[b][i];
        a = p[a][0], b = p[b][0];
    }
    return a;
}
