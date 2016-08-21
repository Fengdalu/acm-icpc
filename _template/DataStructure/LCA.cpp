#include <vector>
using namespace std;
const int POW = 18;
const int N = 1e5;
void dfs(int u, int fa, int p[N][POW], int d[], vector<int>edge[] ){
    d[u] = d[fa]+1;
    p[u][0] = fa;
    for(int i = 1; i < POW; i++) p[u][i] = p[p[u][i - 1]][i - 1];
    int sz=edge[u].size();
    for(int i=0;i<sz;i++){
        int v = edge[u][i];
        if(v == fa) continue;
        dfs(v, u, p, d, edge);
    }
}
int lca(int a, int b, int d[], int p[N][POW]){
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
