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

#define INF 2000000000
#define Maxn 21111
#define Maxm 161111
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int n, m;
int cur[Maxn], sta[Maxn], top;
int que[Maxn], head, tail;
int dist[Maxn];

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    swap(u, v);
    e[tot].u = u; e[tot].v = v; e[tot].c = 0; e[tot].next = last[u]; last[u] = tot++;
}

int bfs(int s, int t, int n) {
    int i, j, k, u, v, w;
    head = tail = 0;
    que[tail++] = s;
    for(i = 0; i < n; i++) dist[i] = INF;
    dist[s] = 0;
    while(head < tail) {
        u = que[head++];
        for(j = last[u]; j != -1; j = e[j].next) {
            if(e[j].c == 0) continue;
            v = e[j].v;
            w = dist[u] + 1;
            if(w < dist[v]) {
                dist[v] = w;
                if(v == t) return 1;
                que[tail++] = v;
            }
        }
    }
    return 0;
}

int dinic(int s, int t, int n) {
    int maxflow = 0, tp = 0;
    int i;
    int u;
    while(bfs(s, t, n)) {
        for(i = 0; i < n; i++) cur[i] = last[i];
        u = s;
        top = 0;
        while(cur[s] != -1) {
            if(u == t) {
                tp = INF;
                for(i = top - 1; i >= 0; i--) {
                    cmin(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--) {
                    e[sta[i]].c -= tp;
                    e[sta[i] ^ 1].c += tp;
                    if(e[sta[i]].c == 0) {
                        top = i;
                    }
                }
                u = e[sta[top]].u;
            }
            else if(cur[u] != -1 && e[cur[u]].c > 0 && dist[u] + 1 == dist[e[cur[u]].v]) {
                sta[top++] = cur[u];
                u = e[cur[u]].v;
            }
            else {
                while(u != s && cur[u] == -1) {
                    u = e[sta[--top]].u;
                }
                cur[u] = e[cur[u]].next;
            }
        }
    }
    return maxflow;
}

int main() {
    int i,j;
    int k, u, v, w;
    //freopen(NAME".in", stdin, "r");
    //freopen(NAME".out", stdout, "w);
    while(scanf("%d%d", &n, &m) != EOF) {
        tot = 0;
        int N = 2 * n + 3, S = 2 * n, T = S + 1;
        for(i = 0; i < N; i++) last[i] = -1;
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            adde(u, v + n, 1);
        }
        for(i = 0; i < n; i++) adde(S, i, 1);
        for(i = 0; i < n; i++) adde(i + n, T, 1); 
        int flow = dinic(S, T, N);
        //printf("flow %d\n", flow);
        if(flow == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
