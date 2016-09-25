#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define Maxn 1005
#define Maxm 111111
const int MOD = 1000000007;

int n, m;
int s, t, k;
int h[Maxn];
vector<pair<int, int> > g[Maxn], g1[Maxn];
priority_queue <pair<int, int> > Q;
priority_queue <pair<int, pair<int, int> > > que;
vector<int> path;

void spfa(int s, int t) {
    int i, j, u, v, tp, d;
    for(i = 1; i <= n; i++) {
        h[i] = MOD;
    }
    h[t] = 0;
    while(!Q.empty()) Q.pop();
    Q.push(MP(0, t));
    while(!Q.empty()) {
        u = Q.top().BB, d = -Q.top().AA;
        Q.pop();
        if(d != h[u]) continue;
        for(j = 0; j < g1[u].SZ; j++) {
            v = g1[u][j].AA;
            tp = g1[u][j].BB + d;
            if(h[v] > tp) {
                h[v] = tp;
                Q.push(MP(-h[v], v));
            }
        }
    }
}

void Astar(int s, int t) {
    int i, j, u, v, f, g0, cur, d;
    path.clear();
    while(!que.empty()) que.pop();
    que.push(MP(-h[s], MP(s, 0)));
    for(cur = 0; cur < k && !que.empty(); ) {
        u = que.top().BB.AA;
        d = -que.top().BB.BB;
        que.pop();
        if(u == t) {
            cur++;
            path.PB(d);
        }
        for(j = 0; j < g[u].SZ; j++) {
            v = g[u][j].AA;
            g0 = d + g[u][j].BB;
            f = g0 + h[v];
            que.push(MP(-f, MP(v, -g0)));
        }
    }
}

int main() {
    int i, j, u, v, w;
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 1; i <= n; i++) g[i].clear(), g1[i].clear();
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[u].PB(MP(v, w));
            g1[v].PB(MP(u, w));
        }
        scanf("%d%d%d", &s, &t, &k);
        if(s == t) k++;
        spfa(s, t);
        Astar(s, t);
        if(path.SZ < k) printf("-1\n");
        else printf("%d\n", path[k - 1]);
    }
    return 0;
}
