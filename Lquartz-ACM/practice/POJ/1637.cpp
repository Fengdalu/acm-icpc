#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define Maxn 222
#define Maxm 3000
#define MOD 100000007

struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int n, m;
int sums, sumt, S, T;
int outdeg[Maxn], indeg[Maxn];

int cur[Maxn], que[Maxn], dist[Maxn], sta[Maxn], head, tail, top;

bool bfs(int s, int t, int n) {
    int i, j, u, v;
    for(i = 0; i < n; i++) {
        dist[i] = MOD;
    }
    dist[s] = 0;
    head = tail = 0;
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
        u = s, top = 0;
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

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}


int main() {
    int i, j, u, v, w, te;
    scanf("%d", &te);
    while(te--) {
        scanf("%d%d", &n, &m);
        for(i = 0; i <= n + 10; i++) {
            outdeg[i] = indeg[i] = 0;
            last[i] = -1;
        }
        tot = 0;
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            outdeg[u]++;
            indeg[v]++;
            if(!w) {
                adde(u, v, 1);
            }
        }
        int flag = true;
        for(i = 1; i <= n; i++) {
            if(abs(indeg[i] - outdeg[i]) & 1) {
                flag = false;
                break;
            }
        }
        if(flag) {
            S = 0; T = n + 1; sums = sumt = 0;
            for(i = 1; i <= n; i++) {
                if(outdeg[i] > indeg[i]) {
                    adde(S, i, (outdeg[i] - indeg[i]) / 2);
                    sums += (outdeg[i] - indeg[i]) / 2;
                }
                if(indeg[i] > outdeg[i]) {
                    adde(i, T, (indeg[i] - outdeg[i]) / 2);
                    sumt += (indeg[i] - outdeg[i]) / 2;
                }
            }
            int flow = dinic(S, T, T + 1);
            if(flow != sums) flag = false;
        }
        if(!flag) {
            printf("impossible\n");
        }
        else {
            printf("possible\n");
        }
    }
    return 0;
}
