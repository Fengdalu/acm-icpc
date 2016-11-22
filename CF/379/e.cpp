#include <bits/stdc++.h>

const int N = 2e5+1000;
int c[N], fa[N];
int op[N], ed[N], id[N];
std::vector<int> g[N];

int get(int x) {
    if(x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}

std::pair<int, int> dp[N][3];
int d[N];
void dfs(int x) {
    for(auto &v : g[x]) if(v != fa[x]) {
        fa[v] = x;
        d[v] = d[x] + 1;
        dfs(v);
        if(dp[v][0].first + 1 > dp[x][1].first) {
            dp[x][1] = std::make_pair(dp[v][0].first + 1, v);
        }
        if(dp[x][1] > dp[x][0]) std::swap(dp[x][1], dp[x][0]);
    }
}

void dfs1(int x) {
    if(fa[x] != -1) {
        int u = fa[x];
        dp[x][2].first = dp[u][2].first + 1;
        if(dp[u][0].second == x) dp[x][2].first = std::max(dp[x][2].first, dp[u][1].first + 1);
        else dp[x][2].first = std::max(dp[x][2].first, dp[u][0].first + 1);
    }
    for(auto &v : g[x]) if(v != fa[x]) dfs1(v);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", c + i);
    for(int i = 0; i < n; i++) fa[i] = i;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        if(c[u] == c[v]) fa[get(u)] = get(v);
        op[i] = u; ed[i] = v;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(get(i) == i) id[i] = cnt++;
    }
    for(int i = 0; i < n; i++) {
        int u = op[i], v = ed[i];
        if(get(u) != get(v)) {
            u = id[get(u)]; v = id[get(v)];
            g[u].push_back(v); g[v].push_back(u);
        }
    }
    for(int i = 0; i < cnt; i++) {
        std::sort(g[i].begin(), g[i].end());
        g[i].erase(std::unique(g[i].begin(), g[i].end()), g[i].end());
    }

    memset(fa, 0, sizeof fa);
    fa[0] = -1;
    dfs(0);
    dfs1(0);
    int tot = n + 1;
    for(int i = 0; i < cnt; i++) tot = std::min(tot, std::max(dp[i][0].first
                                                              ,std::max(dp[i][1].first, dp[i][2].first)));
    printf("%d\n", tot);
    return 0;
}
