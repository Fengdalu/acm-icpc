#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int sz[maxn];
int ans[maxn];
int pre[maxn];
vector<int>g[maxn];
int n;

void dfs(int x) {
    sz[x] = 1;
    for(auto &t: g[x]) {
        dfs(t);
        sz[x] += sz[t];
    }
}

void cal(int x) {
    for(auto &t: g[x]) {
        cal(t);
    }
    ans[x] = x;
    if(g[x].size()) {
        int p = g[x][0];
        for(auto &t: g[x]) {
            if(sz[t] > sz[p]) p = t;
        }
        ans[x] = ans[p];
        while(ans[x] != x) {
            if(sz[ans[x]] * 2 >= sz[x]) break;
            ans[x] = pre[ans[x]];
        }
    }
}

int main() {
    int q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x); x--;
        pre[i] = x;
        g[x].push_back(i);
    }
    dfs(0);
    cal(0);
    while(q--) {
        int t; scanf("%d", &t); t--;
        printf("%d\n", ans[t] + 1);
    }
}
