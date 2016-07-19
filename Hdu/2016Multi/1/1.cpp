#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ONES(x) __builtin_popcount(x)

typedef long long ll;
const ll mod = 1e9 + 7;

const int maxn = 100100;
pair<int, pair<int, int> >e[1000100];
int fa[maxn];
int ind[maxn];
int nt[maxn * 2], c[maxn * 2], to[maxn * 2];
int sz[maxn];
int cnt;
int n, m;
ll cc = 0;

int get(int x) {
    if(fa[x] == x) return x;
    return fa[x] = get(fa[x]);
}

void add(int a, int b, int w)  {
    to[cnt] = b;
    c[cnt] = w;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}


void dfs(int rt, int fa) {
    sz[rt] = 1;
    for(int k = ind[rt]; k != -1; k = nt[k]) {
        int v = to[k];
        if(v == fa) continue;
        dfs(v, rt);
        sz[rt] += sz[v];
        cc += ((ll)c[k] * (ll)sz[v] * (ll)(n - sz[v]));
    }

}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) fa[i] = i;
        for(int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--; b--;
            e[i].first = c;
            e[i].second.first = a;
            e[i].second.second = b;
        }
        sort(e, e + m);
        for(int i = 0; i < n; i++) ind[i] = -1;
        for(int i = 0; i < n; i++) sz[i] = 0;
        cnt = 0;
        ll tot = 0;
        for(int i = 0; i < m; i++) {
            int u = e[i].second.first, v = e[i].second.second, c = e[i].first;
            if(get(u) == get(v)) continue;
            fa[get(u)] = get(v);
            tot += e[i].first;
            add(u, v, c); add(v, u, c);
        }
        cc = 0;
        printf("%lld ", tot);
        dfs(0, -1);
        printf("%.2f\n", 2LL * cc / (double)(n) / double(n - 1));
    }
    return 0;
}

