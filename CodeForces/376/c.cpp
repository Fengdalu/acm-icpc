#include <bits/stdc++.h>

const int N = 2e5+10;
int fa[N];
int c[N];
int G[N];
std::map<int, int> cc[N];
typedef std::map<int, int>::iterator IT;
int n;
int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= n; i++) scanf("%d", c + i);
    for(int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if(find(l) == find(r)) continue;
        fa[find(l)] = find(r);
    }

    for(int i = 1; i <= n; i++) {
        cc[find(i)][c[i]]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(find(i) == i) {
        std::map<int, int> &f = cc[i];
        int cnt = 0;
        for(IT it = f.begin(); it != f.end(); it++)
            G[cnt++] = it->second;
        int tot = std::accumulate(G, G + cnt, 0);
        int mx = *std::max_element(G, G + cnt);
        ans += tot - mx;
    }
    printf("%d\n", ans);
    return 0;
}
