#include <bits/stdc++.h>

const int N = 1e5 + 10;
typedef unsigned long long ull;
typedef long long ll;
std::map<ull, int> f;
std::vector<int> g[N];
ull mod = 1e5 + 3;
int fa[N];
int q[N];
ull h[N];
int n;

void bfs(int x) {
    int l = 0, r = 0;
    std::fill(fa, fa + n + 1, -1);
    q[l] =  x;
    while(l <= r) {
        int x = q[l++];
        int sz = g[x].size();
        for(int i = 0; i < sz; i++) {
            int v = g[x][i];
            if(v == fa[x]) continue;
            fa[v] = x;
            q[++r] = v;
        }
    }
    for(int i = r; i >= 1; i--) {
        ull v = q[i];
        h[v] *= mod;
        h[v]++;
        f[h[v]]++;
        h[fa[v]] += h[v];
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1);
    ll ans = 0;
    for(std::map<ull, int>::iterator it = f.begin(); it != f.end(); it++) {
        ans += 1ll * (it->second) * (it->second - 1) / 2ll;
    }
    std::cout << ans << std::endl;
    return 0;
}

