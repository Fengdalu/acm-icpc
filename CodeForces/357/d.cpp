#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 100010;
vector<int>g[maxn], p[maxn];
int to[maxn];
int vis[maxn];
int in[maxn];
int ans[maxn];
int id[maxn];
int cnt;
int n, m;

void dfs(int x) {
    for(int i = 0; i < g[x].size(); i++)
        dfs(g[x][i]);
    if(to[x]) {
        vis[x] = cnt;
        ans[cnt++] = x;
    }
}

bool check(int x, int pre) {
    if(vis[x] != -1) { pre = x; }
    if(id[x] != pre) return false;
    for(int i = 0; i < g[x].size(); i++) {
        int v = g[x][i];
        bool flag = check(v, pre);
        if(!flag) return flag;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        in[b]++;
    }
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        id[i] = x;
        to[x] = true;
    }
    memset(vis, -1, sizeof vis);
    for(int i = 1; i <= n; i++)
    if(in[i] == 0)
        dfs(i);
    bool flag = true;
    for(int i = 1; i <= n; i++)
    if(in[i] == 0)
        flag &= check(i, i);
    if(flag) {
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; i++)
            printf("%d\n", ans[i]);
    }
    else printf("-1\n");
    return 0;
}


