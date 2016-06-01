#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100010;
vector<int>g[maxn];
bool vis[maxn];

int tot;
void dfs(int x, int pre) {
    int cur = 0;
    for(int i = 0; i < g[x].size(); i++)
    if(g[x][i] != pre){
        int to = g[x][i];
        dfs(to, x);
        if(!vis[to]) cur++;
    }
    tot += cur;
    vis[x] = cur & 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(vis, 0, sizeof vis);
    dfs(1, -1);
    cout << (n - 1) - tot << endl;
    return 0;
}
