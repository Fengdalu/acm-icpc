#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 20
#define Maxm 3000
const int MOD = 1111111;
int n, m;
int c[Maxn][Maxn];
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn], cur[Maxn];
int que[Maxn], sta[Maxn], dist[Maxn], head, tail, top;

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}

bool bfs(int s, int t, int n) {
    int i, j, u, v;
    for(i = 1; i <= n; i++) {
        dist[i] = MOD;
    }
    dist[s] = 0;
    head = tail = 0;
    que[tail++] = s;
    while(head < tail) {
        u = que[head++];
        for(j = last[u]; j != -1; j = e[j].next) {
            if(e[j].c == 0) continue;
            v = e[j].v;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                if(v == t) return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}

int dinic(int s, int t, int n) {
    int maxflow = 0;
    int i, j, u, v;
    while(bfs(s, t, n)) {
        for(i = 1; i <= n; i++) cur[i] = last[i];
        top = 0;
        u = s;
        while(cur[s] != -1) {
            if(u == t) {
                int tp = MOD;
                for(i = top - 1; i >= 0; i--) {
                    tp = min(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--) {
                    e[sta[i]].c -= tp;
                    e[sta[i] ^ 1].c += tp;
                    if(e[sta[i]].c == 0) top = i;
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
    int i, j, u, v, w, T;
    scanf("%d", &T);
    for(int CA = 1; CA <= T; CA++) {
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; i++) last[i] = -1;
        tot = 0;
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            adde(u, v, w);
        }
        printf("Case %d: %d\n", CA, dinic(1, n, n));
    }
    return 0;
}
