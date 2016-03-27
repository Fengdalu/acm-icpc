#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
#include <bitset>

const int maxn = 20010;
const int maxm = 20000;
std::vector<int>g[maxn];
bool vis[maxn];
int n, m;

int bfs(int x) {
    int tot = 0;
    memset(vis, 0, sizeof vis);
    std::queue<int>q;
    vis[x] = true;
    q.push(x);
    while(q.size()) {
        int x = q.front();
        if(x < n) tot++;
        q.pop();
        for(int i = 0; i < g[x].size(); i++)
        if(!vis[g[x][i]]) {
            vis[g[x][i]] = true;
            q.push(g[x][i]);
        }
    }
    return tot;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        g[x].push_back(y);
        g[y + n].push_back(x + n);
    }
    for(int i = 0; i < n; i++) g[i + n].push_back(i);
    int tot = 0;
    for(int i = 0; i < n; i++) tot += bfs(i + n);
    std::cout << tot << std::endl;
    return 0;
}

