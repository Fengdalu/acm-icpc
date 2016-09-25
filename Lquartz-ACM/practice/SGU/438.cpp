#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL USE = 20000;
const LL INF = 0x3f3f3f3f;
#define Maxn 111
#define Maxm 61111
struct node {
    int u, v, c, w, next;
} e[Maxm];
int tot, last[Maxn];
int dist[Maxn], pre[Maxn];
int man, prev, mincost, maxflow;
bool visit[Maxn];
queue<int> Q;
#define MOD 0x3f3f3f3f

void adde (int u, int v, int c, int w) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
}

bool spfa (int s, int t, int n) {
    memset (dist, 0x3f, sizeof (dist[0]) * (n + 3) );
    memset (visit, 0, sizeof (visit[0]) * (n + 3) );
    memset (pre, -1, sizeof (pre[0]) * (n + 3) );
    while (!Q.empty() ) Q.pop();
    Q.push (s);
    visit[s] = true;
    dist[s] = 0;
    pre[s] = -1;
    while (!Q.empty() ) {
        int u = Q.front();
        visit[u] =false;
        Q.pop();
        for (int j = last[u]; j != -1; j = e[j].next)
            if (e[j].c > 0 && dist[u] + e[j].w < dist[e[j].v]) {
                dist[e[j].v] = dist[u] + e[j].w;
                pre[e[j].v] = j;
                if (!visit[e[j].v]) {
                    Q.push (e[j].v);
                    visit[e[j].v] = true;
                }
            }
    }
    if (dist[t] == MOD) return false;
    else return true;
}

int ChangeFlow (int t) {
    int det = MOD, u = t;
    while (~pre[u]) {
        u = pre[u];
        det = min (det, e[u].c);
        u = e[u].u;
    }
    u = t;
    while (~pre[u]) {
        u = pre[u];
        e[u].c -= det;
        e[u ^ 1].c += det;
        u = e[u].u;
    }
    return det;
}

int x[100], y[100], f[55][55], C[100], mp[55][55], n, c, D, W, m;
int MinCostFlow (int s, int t, int n) {
    mincost = maxflow = prev = man = 0;
    int tp;
    while (spfa (s, t, n) ) {
        int det = ChangeFlow (t);
        tp = man + (dist[t] - prev) * maxflow + det;
//        cout << tp << " " << prev << " " << dist[t] << " det " << det << endl;
        if(tp >= c) {
            for(int j = prev + 1; j <= dist[t]; j++) {
                tp = man + (j - prev) * maxflow;
                if(tp >= c) {
                    return prev = j;
                }
            }
            return prev = dist[t];
        }
        man = tp;
        prev = dist[t];
        mincost += det * dist[t];
        maxflow += det;
    }
//    cout << "flow " << maxflow << " prev " << prev << " man " << man << endl;
    if(maxflow > 0) {
        return (prev + (c - man) / maxflow + ((c - man) % maxflow != 0 ? 1 : 0));
    }
    else return -1;
}
int main() {
    int i, j, k, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d%d%d%d", &n, &c, &D, &W) != EOF) {
        for(i = 1; i <= n; i++)scanf("%d%d%d", &x[i], &y[i], &C[i]);
        if(D >= W) {
            printf("%d\n", 1);
            continue;
        }
        for(i = 0; i <= n + 3; i++) {
            for(j = 0; j <= n + 3; j++) {
                f[i][j] = USE;
                mp[i][j] = 0;
            }
        }
        for(i = 1; i <= n; i++) {
            for(j =1 ; j <= n; j++) {
                int d = SQ(x[i] - x[j]) + SQ(y[i] - y[j]);
                if(d <= SQ(D)) f[i][j] = 1, mp[i][j] = 1;
            }
            f[i][i] = 0;
            if(y[i] <= D) mp[n + 1][i] = f[n + 1][i] = 1;
            if(W - y[i] <= D) mp[i][n + 2] = f[i][n + 2] = 1;
        }
//        for(i = 1; i <= m; i++) {
//            for(j = 1; j <= m; j++) printf("%8d ", f[i][j]); printf("\n");
//        }
        int N = 2 * n + 3, S = 0, T = 2 * n + 1, SS = T + 1, TT = SS + 1;
        for(i = 0; i <= N; i++) last[i] = -1;
        tot = 0;
        for(i = 1; i <= n; i++) {
            if(mp[n + 1][i]) adde(S, i, MOD, 1);
            if(mp[i][n + 2]) adde(i + n, T, MOD, 1);
            adde(i, i + n, C[i], 0);
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(mp[i][j]) {
                    adde(i + n, j, MOD, 1);
                }
            }
        }
        int ti = MinCostFlow(S, T, N);
        if(ti != -1) 
            printf("%d\n", ti);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}


