#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100010;
queue<int>g[maxn];
bool vis[maxn];
int tot = 0;
int n, k, m;

void dfs(int x) {
    if(vis[x]) return;
    vis[x] = true;
    tot++;
    while(g[x].size()) {
        dfs(g[x].front());
        g[x].pop();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        vis[x] = true;
        tot++;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(!vis[a]) {
            if(vis[b]) dfs(a);
            else g[b].push(a);
        }
        printf("%d\n", tot);
    }
    return 0;
}
