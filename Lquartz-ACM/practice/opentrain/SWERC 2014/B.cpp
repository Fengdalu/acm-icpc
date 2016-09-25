#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))

#define NAME ""

#define Maxn 20111
#define Maxm 501111
#define INF 2100000000
struct node {
    int u, v, l, next;
}e[Maxm];
int tot, last[Maxn];
int n, m;
priority_queue<PII> que;
int dist[Maxn];

void adde(int u, int v, int l) {
    e[tot].u = u; e[tot].v = v; e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
    swap(u, v);
    e[tot].u = u; e[tot].v = v; e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
}

void dijkstra(int s, int t) {
    int i, j, k, u, v, w;
    int d;
    while(!que.empty()) que.pop();
    for(i = 0; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    que.push(MP(-dist[s], s));
    while(!que.empty()) {
        u = que.top().BB, d = -que.top().AA;
        que.pop();
        if(d != dist[u]) continue;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            w = d + e[j].l;
            if(w < dist[v]) {
                dist[v] = w;
                que.push(MP(-w, v));
            }
        }
    }
}

int visit[Maxn];
queue<int> Q;
int bfs(int s) {
    int i, j, k, u, v, w;
    int ret = 0;
    memset(visit, 0, sizeof(visit));
    visit[s] = 1;
    while(!Q.empty()) Q.pop();
    Q.push(s);
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            w = e[j].l;
            if(dist[v] + w == dist[u]) {
                ret += w;
                if(!visit[v]) {
                    Q.push(v);
                    visit[v] = 1;
                }
            }
        }
    }
    return ret;
}

int main() {
    int i,j;
    int u, v, w;
    //freopen(NAME".in", stdin, "r");
    //freopen(NAME".out", stdout, "w);
    while(scanf("%d%d", &n, &m) != EOF) {
        tot = 0;
        for(i = 0; i <= n; i++) last[i] = -1;
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            adde(u, v, w);
        }
        dijkstra(0, n - 1);
        //for(i = 0; i < n; i++) printf("dist %d %d\n", i, dist[i]);
        int ans = bfs(n - 1);
        printf("%d\n", ans * 2);
    }
    return 0;
}
