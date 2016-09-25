#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define Maxn 222
#define Maxm 2220
#define MOD 2012345678
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int cur[Maxn], dist[Maxn], sta[Maxn], que[Maxn], head, tail, top;
int n, m, S, T;

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}

bool bfs(int s, int t, int n) {
    int i, j, u, v;
    head = tail = 0;
    for(i = 1; i <= n; i++) dist[i] = MOD;
    dist[s] = 0;
    que[tail++] = s;
    while(head < tail) {
        u = que[head++];
//        printf("bfs u %d\n", u);
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
//        printf("flow %d\n", maxflow);
        for(i = 1; i <= n; i++) {
            cur[i] = last[i];
        }
        u = s, top = 0;
        while(cur[s] != -1) {
//            printf("u %d  top %d\n", u, top);
            if(u == t) {
                int tp = MOD;
                for(i = top - 1; i >= 0; i--) {
                    tp = min(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--) {
                    e[sta[i]].c -= tp;
                    e[sta[i] ^ 1].c += tp;
                    if (e[sta[i]].c == 0)
                        top = i;
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
    int i, j, u, v, w;
    while(scanf("%d%d", &m, &n) != EOF) {
        tot = 0;
        S = 1; T = n;
        for(i = 1; i <= n; i++) {
            last[i] = -1;
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            adde(u, v, w);
        }
        int maxflow = dinic(S, T, n);
        printf("%d\n", maxflow);
    }
    return 0;
}
