#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+1000;
vector<int> g[N];
int ans[N];
int a[N], b[N];

void dfs(int x, int c) {
    if(ans[x] != 0) return ;
    ans[x] = c;
    if(c == 1) c = 2; else c = 1;
    for(auto &v : g[x]) {
        dfs(v, c);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i < 2 * n; i += 2) {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        a[i] = u; b[i] = v;
    }
    for(int i = 1; i <= 2 * n; i++) dfs(i, 1);
    for(int i = 0; i < n; i++) printf("%d %d\n", ans[a[i]], ans[b[i]]);
}
