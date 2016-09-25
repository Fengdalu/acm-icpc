#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define Maxn 2400
#define Maxm 210000
#define MOD 100000007
#define PB push_back
#define MP make_pair
#define AA frist
#define BB second
#define SZ size()
#define BG begin()
#define ED end()

struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn], pre[Maxn];
int n, m;
int S, T, N;

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}
int cur[Maxn], sta[Maxn], top, que[Maxn], head, tail, dist[Maxn];

bool bfs(int s, int t, int n) {
    int i, j, u, v, d;
    for(i = 0; i < n; i++) {
        dist[i] = MOD;
    }
    head = tail = 0;
    dist[s] = 0;
    que[tail++] = s;
    while(head < tail) {
        u = que[head++];
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(e[j].c > 0 && dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                if(v == t) return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}

int dinic(int s, int t, int n) {
    int i, j, u, v, tp;
    int maxflow = 0;
    while(bfs(s, t, n)) {
        top = 0;
        u = s;
        for(i = 0; i < n; i++) cur[i] = last[i];
        while(cur[s] != -1) {
            if(u == t) {
                tp = MOD;
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
    int i, j, k, u, v, w;
    while(scanf("%d%d", &n, &m) != EOF) {
        S = 0;
        T = n + m + 1;
        N = T + 1;
        for(i = 0; i < N; i++) last[i] = -1;
        tot = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d", &w);
            adde(S, i, w);
        }
        for(i = 1; i <= n; i++) pre[i] = -1;
        for(i = 1; i <= m; i++) {
            scanf("%d", &k);
            for(j = 0; j < k; j++) {
                scanf("%d", &w);
                if(pre[w] != -1) {
                    adde(n + pre[w], n + i, MOD);
                }
                pre[w] = i;
                adde(w, i + n, MOD);
            }
            scanf("%d", &w);
            adde(n + i, T, w);
        }
        printf("%d\n", dinic(S, T, N));
    }
    return 0;
}
