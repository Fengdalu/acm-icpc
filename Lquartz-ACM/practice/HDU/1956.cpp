#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 5222
#define Maxm 5111
#define MOD 202345678

int odeg[Maxn], ideg[Maxn], dist[Maxn], cur[Maxn], head, tail, top, que[Maxn], sta[Maxn];
int n, m, S, T;
int tot, last[Maxn];
struct node {
    int u, v, c, next;
}e[Maxm];

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}

bool bfs(int s, int t, int n) {
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
    int i, j, u, v;
    int maxflow = 0;
    while(bfs(s, t, n)) {
        for(i = 0; i < n; i++) cur[i] = last[i];
        u = s; top = 0;
        while(cur[s] != -1) {
//            printf("flow %d\n", maxflow);
            if(u == t) {
                int tp = MOD;
                for(i = top - 1; i >= 0; i--) {
                    tp = min(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--){
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
    int i, j, u, v, w, x, y;
    int Te;
    scanf("%d", &Te);
    for(int CA = 1; CA <= Te; CA++) {
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; i++) {
            odeg[i] = ideg[i] = 0;
        }
        tot = 0;
        S = 0, T = n + 1;
        for(i = 0; i <= n + 1; i++) last[i] = -1;
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            ideg[v]++; odeg[u]++;
            if(w != 1) {
                adde(u, v, 1);
            }
        }
        int flag = 1;
        for(i = 1; i <= n; i++) {
            if(abs(ideg[i] - odeg[i]) & 1) {
                flag = 0;  break;
            }
        }
        if(flag) {
            int Tsum = 0, Ssum = 0;
            for(i = 1; i <= n; i++) {
                if(ideg[i] > odeg[i]) {
                    int det = ideg[i] - odeg[i];
                    adde(i, T, det / 2);
                    Tsum += det / 2;
                }
                else if(ideg[i] < odeg[i]) {
                    int det = odeg[i] - ideg[i];
                    adde(S, i, det / 2);
                    Ssum += det / 2;
                }
            }
            int maxflow = dinic(S, T, T + 1);
//            printf("S %d T %d flow %d\n", Ssum, Tsum, maxflow);
            if(maxflow != Tsum) flag = false;
        }
        if(flag) {
            printf("possible\n");
        }
        else {
            printf("impossible\n");
        }
    }
    return 0;
}
