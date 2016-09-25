#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 1111
#define Maxm 510000
#define MOD 1000000

struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn], cur[Maxn];
int que[Maxn], sta[Maxn], dist[Maxn], top, head, tail;
int n, m, S, T;

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}

bool bfs(int s, int t, int n) {
//    printf("bfs %d %d %d\n", s, t, n);
    int i, j, u, v;
    for(i = 0; i < n; i++) dist[i] = MOD;
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
        for(i = 0; i < n; i++) cur[i] = last[i];
        u = s; top = 0;
        while(cur[s] != -1) {
//            printf("max %d u %d\n", maxflow, u);
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
    int i, j, u, v, w, Te;
    scanf("%d", &Te);
    for(int CA = 1; CA <= Te; CA++) {
        scanf("%d%d", &n, &m);
        S = 0;
        int dmax = 0;
        tot = 0;
        for(i = 0; i <= n + 600; i++) last[i] = -1;
        for(i = 1; i <= n; i++) {
            scanf("%d%d%d", &w, &u, &v);
            dmax = max(dmax, v);
            adde(S, i, w);
            for(j = u; j <= v; j++) {
                adde(i, n + j, 1);
            }
        }
        T = n + dmax + 1;
        for(i = 1; i <= dmax; i++) {
            adde(n + i, T, m);
        }
        dinic(S, T, T + 1);
        int flag = true;
        for(i = 0; i < tot; i+= 2) {
            if(e[i].u == S && e[i].c > 0) {
                flag = false;
                break;
            }
        }
        printf("Case %d: ", CA);
        if(flag) printf("Yes\n");
        else printf("No\n");
        printf("\n");
    }
    return 0;
}
