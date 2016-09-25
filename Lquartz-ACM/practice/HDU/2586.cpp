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
const LL INF = 0x3f3f3f3f;
#define Maxn 41111
#define Maxm 81111
int n, m;
//Tarjan¿Îœﬂ«ÛLCA
struct node {
    int u, v, n, next;
};
struct GRAPH {
    node e[Maxm];
    int tot, last[Maxn];
    void init(int n) {
        for(int i = 0; i <= n; i++) last[i] = -1;
        tot = 0;
    }
    void adde(int u, int v, int n) {
        e[tot].u = u; e[tot].v = v; e[tot].n = n;
        e[tot].next = last[u]; last[u] = tot++;
        e[tot].u = v; e[tot].v = u; e[tot].n = n;
        e[tot].next = last[v]; last[v] = tot++;
    }
}e, q;
int fa[Maxn], lca[Maxn], ans[Maxn];
int visit[Maxn];
int dist[Maxn];
int getfa(int x) {
    if(x == fa[x]) return x;
    else return (fa[x] = getfa(fa[x]));
}

void dfs(int u, int from) {
    int j, v;
    for(j = e.last[u]; j != -1; j = e.e[j].next) {
        if(j == from) continue;
        v = e.e[j].v;
        dist[v] = dist[u] + e.e[j].n;
        dfs(v, j ^ 1);
    }
}

void tarjanLCA(int u) {
    int i, j, v, f;
    fa[u] = u;
    visit[u] = 1;
    for(j = e.last[u]; j != -1; j = e.e[j].next) {
        v = e.e[j].v;
        if(!visit[v]) {
            tarjanLCA(v);
            fa[v] = u;
        }
    }
    for(j = q.last[u]; j != -1; j = q.e[j].next) {
        v = q.e[j].v;
        if(visit[v]) {
            lca[q.e[j].n] = f = getfa(v);
            ans[q.e[j].n] = dist[u] + dist[v] - 2 * dist[f];
        }
    }
}

int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te, root;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d%d", &n, &m);
        e.init(n);
        for(i = 1; i < n; i++) {
            scanf("%d%d%d", &u, &v, &w);
            e.adde(u, v, w);
        }
        root = (n + 1) / 2;
        q.init(n);
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            q.adde(u, v, i);
        }
        dist[root] = 0;
        dfs(root, -1);
        for(i = 1; i <= n; i++) visit[i] = 0;
        tarjanLCA(root);
        for(i = 0; i < m; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
