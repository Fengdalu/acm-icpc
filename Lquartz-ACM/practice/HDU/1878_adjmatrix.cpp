#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 1111
int g[Maxn][Maxn];
int n, m;
int visit[Maxn], deg[Maxn];
int cnt;
void dfs(int u) {
    visit[u] = 1;
    cnt++;
    for(int i = 1; i <= n; i++) {
        if(g[u][i] && !visit[i]) {
            dfs(i);
        }
    }
}
int main() {
    int i, j;
    int u, v;
    while(scanf("%d", &n) != EOF && n) {
        scanf("%d", &m);
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                g[i][j] = 0;
            }
        }
        for(i = 1; i <= n; i++) deg[i] = 0, visit[i] = false;
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            g[u][v]++;
            g[v][u]++;
            deg[u]++;
            deg[v]++;
        }
        cnt = 0;
        dfs(1);
        int flag = false;
        if(cnt == n) {
            for(i = 1, j = 0; i <= n; i++) {
                if(deg[i] & 1) {
                    j++;
                }
            }
            if(!j) flag = true;
        }
        if(flag) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
