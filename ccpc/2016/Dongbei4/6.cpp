#include <bits/stdc++.h>
#define PB push_back
#define OP begin()
#define ED end()
#define SZ size()

const int N = 1e5+7;
std::vector<int>T[N];
int d[N];
int s[N];
int fa[N];
int son[N];

int cmp(int a, int b) { return d[a] > d[b]; }

void dfs(int u) {
    for(int i = 0; i != T[u].SZ; i++) {
        int v = T[u][i];
        if(v == fa[u]) continue;
        d[v] = d[u] + 1;
        fa[v] = u;
        son[u]++;
        dfs(v);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    int _t; scanf("%d", &_t);
    for(int cas = 1; cas <= _t; cas++) {
        int n, q; scanf("%d%d", &n, &q);
        std::fill(d, d + 1 + n, 0);
        std::fill(son, son + 1 + n, 0);
        for(int i = 1; i <= n; i++) T[i].clear();
        for(int i = 1; i < n; i++) {
            int u, v; scanf("%d%d", &u, &v);
            T[u].PB(v);
            T[v].PB(u);
        }
        fa[1] = 0;
        dfs(1);
        printf("Case #%d:\n", cas);
        while(q--) {
            int nn; scanf("%d", &nn);
            for(int i = 0; i < nn; i++) scanf("%d", s + i);
            std::sort(s, s + nn, cmp);
            int dec = 0;
            std::queue<int> modify;
            for(int i = 0; i < nn; i++) {
                int u = s[i];
                if(son[u] < 2) {
                    dec++;
                    if(son[u] == 0) {
                        son[fa[u]]--;
                        modify.push(fa[u]);
                    }
                }
            }
            printf("%d\n", n - dec);
            while(modify.size()) {
                son[modify.front()]++;
                modify.pop();
            }
        }
    }
    return 0;
}

/*
1
6 3
6 4
2 5
5 4
1 5
5 3
3 1 2 3
1 5
3 3 1 4
*/
