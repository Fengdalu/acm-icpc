//#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define Maxn 101111
#define FA 100005
int cnt[Maxn];
map<int, int> mp;
vector<int> f;
int g[Maxn];
struct node {
    int l, r, next, n;
}e[Maxn * 2];
int tot, last[Maxn];
int sum[Maxn];
int ans[Maxn];
PII Q[Maxn];
int n, m;

void adde(int u, int v, int n) {
    e[tot].l = u; e[tot].r = v; e[tot].n = n; e[tot].next = last[v]; last[v] = tot++;
}

void check(int u, int x) {
    int i, j, l, r;
    for(j = last[u]; j != -1; j = e[j].next) {
        l = e[j].l; r = e[j].r; i = e[j].n;
        if(sum[r] - sum[l - 1] == x) ans[i]++;
    }
}

int main() {
    int i, j, k, u, v, w;
    while(cin >> n >> m) {
        f.clear();
        for(i = 0; i < n; i++) {
            cin >> w;
            f.PB(w);
            g[i + 1] = w;
        }
        memset(last, -1, sizeof(last));
        tot = 0;
        for(i = 0; i < m; i++) {
            cin >> u >> v;
            Q[i] = MP(u, v);
            adde(u, v, i);
        }
        sort(f.BG, f.ED);
        f.erase(unique(f.BG, f.ED), f.ED);
        for(i = 0; i < f.SZ; i++) mp[f[i]] = i + 1;
        memset(cnt, 0, sizeof(cnt));
        for(i = 1; i <= n; i++) {
            cnt[mp[g[i]]]++;
        }
        memset(ans, 0, sizeof(ans));
        for(i = 0; i < f.SZ; i++) {
            if(f[i] > FA) break;
            if(cnt[mp[f[i]]] < f[i]) continue;
            sum[0] = 0;
            for(j = 1; j <= n; j++) {
                sum[j] = sum[j - 1];
                if(g[j] == f[i]) sum[j]++;
                check(j, f[i]);
            }
        }
        for(i = 0; i < m; i++) printf("%d\n", ans[i]);
    }

    return 0;
}
