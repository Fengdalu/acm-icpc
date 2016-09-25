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
//const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 1111
#define Maxm 111111

struct node {
    int u, v, c, w, next;
} e[Maxm];
int tot, last[Maxn];
int dist[Maxn], pre[Maxn];
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

int MinCostFlow (int s, int t, int n) {
    int mincost, maxflow;
    mincost = maxflow = 0;
    while (spfa (s, t, n) ) {
        int det = ChangeFlow (t);
        mincost += det * dist[t];
        maxflow += det;
    }
    return mincost;
}
int n;
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    while(te--) {
        scanf("%d", &n);
        int tot = 0;
        int N = n + 2, S = 0, T = N - 1;
        for(i = 0; i <= N; i++) last[i] = -1;
        for(i = 1; i <= n; i++) {
            if(i == 1) u = n; 
            else u = i - 1;
            if(i == n) v = 1;
            else v = i + 1;
            adde(i, u, n, 1);
            adde(i, v, n, 1);
            scanf("%d", &w);
            if(w) adde(S, i, w, 0);
            adde(i, T, 1, 0);
        }
        printf("%d\n", MinCostFlow(S, T, N));
    }
    return 0;
}
