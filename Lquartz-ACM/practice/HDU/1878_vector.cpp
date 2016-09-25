#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 1111
vector<int> g[Maxn];
int deg[Maxn], visit[Maxn];
int n, m;
int cnt;

void dfs(int u) {
    visit[u] = true;
    cnt++;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(!visit[v]) {
            dfs(v);
        }
    }
}

int main() {
    int i, j, u, v;
    while(scanf("%d", &n) != EOF && n) {
        scanf("%d", &m);
        for(i = 1; i <= n; i++) {
            deg[i] = 0;
            g[i].clear();
            visit[i] = false;
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            deg[u]++, deg[v]++;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int flag = true;
        for(i = 1; i <= n; i++) {
            if(deg[i] & 1) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cnt = 0;
            dfs(1);
            if(cnt != n) flag = false;
        }
        if(flag) {
            printf("1\n");
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}
