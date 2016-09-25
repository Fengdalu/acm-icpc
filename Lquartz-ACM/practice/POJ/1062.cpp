#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define Maxn 111
#define Maxm 21111
#define MOD (1<<28)
#define MP make_pair
#define AA first
#define BB second

struct node {
    int u, v, l, next;
}e[Maxm];
int tot, last[Maxn];
int lev[Maxn], has[Maxn], dist[Maxn];

priority_queue <pair<int, int> > Q;
int n, M;
int p, l, x;

void adde(int u, int v, int l) {
    e[tot].u = u; e[tot].v = v; e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
}

int spfa(int w) {
    if(lev[0] < w || lev[0] > w + M) return MOD;
    int i, j, u, v;
    for(i = 0; i <= n; i++) {
        dist[i] = MOD;
    }
    dist[0] = 0;
    Q.push(MP(0, 0));
    while(!Q.empty()) {
        u = Q.top().BB;
        int d = -Q.top().AA;
        Q.pop();
        if(d != dist[u]) continue;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(lev[v] < w || lev[v] > w + M) continue;
            if(dist[v] > d + e[j].l) {
                dist[v] = d + e[j].l;
                Q.push(MP(-dist[v], v));
            }
        }
    }
    return dist[1];
}

int main() {
    int i, j, u, v, S, T;
    while(scanf("%d%d", &M, &n) != EOF) {
        tot = 0;
        for(i = 0; i <= n; i++) last[i] = -1;
        for(i = 1; i <= n; i++) {
            scanf("%d%d%d", &p, &l, &x);
            lev[i] = l;
            has[i] = l;
            adde(0, i, p);
            for(j = 0; j < x; j++) {
                scanf("%d%d", &u, &v);
                adde(u, i, v);
            }
        }
        lev[0] = lev[1];
        int ans = MOD;
        for(i = 1; i <= n; i++) {
            ans = min(ans, spfa(lev[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
1 5
10000 3 2
2 5000
3 5000
3000 4 1
4 400
3000 2 1
4 500
1000 3 1
5 100
100 2 0

1 5
10000 3 2
2 5000
3 5000
3000 2 1
4 500
3000 4 1
4 400
1000 3 1
5 100
100 2 0
*/
