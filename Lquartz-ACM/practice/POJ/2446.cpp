#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 3000
#define Maxm 20000
#define MOD 1000000007
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int n, m, S, T;
int g[40][40];

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v =v ; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v =u ; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}

int cur[Maxn], dist[Maxn], sta[Maxn], que[Maxn], head, tail, top;

bool bfs(int s, int t, int n) {
    int i, j, u, v;
    for(i = 0; i < n; i++) {
        dist[i] = MOD;
    }
    head = tail = 0;
    que[tail++] = s;
    dist[s] = 0;
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
    int maxflow = 0;
    int u, v, i, j;
    while(bfs(s, t, n)) {
        u = s, top = 0;
        for(i = 0; i < n; i++) cur[i] = last[i];
        while(cur[s] != -1) {
            if(u == t) {
                int tp = MOD;
                for(i = top - 1; i >= 0; i--) tp = min(tp, e[sta[i]].c);
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
    while(scanf("%d%d%d", &n, &m, &k) != EOF) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                g[i][j] = 0;
            }
        }
        for(i = 0; i < k; i++) {
            scanf("%d%d", &v, &u);
            g[u][v] = 1;
        }
        bool flag = true;
        if((n * m - k) & 1) flag = false;
        else {
            tot = 0;
            for(i = 0; i <= n * m * 2 + 2; i++) last[i] = -1;
            S = 0, T = 2 * n * m + 1;
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= m; j++) {
                    if(g[i][j]) continue;
                    u = (i - 1)* m + j;
                    v = u + n * m;
                    adde(u, v, 1);
                    if((i & 1) == (j & 1)) {
                        adde(S, u, 1);
                        if(i != n && !g[i + 1][j]) adde(v, u + m, 1);
                        if(j != m && !g[i][j + 1]) adde(v, u + 1, 1);
                    }
                    else {
                        adde(v, T, 1);
                        if(i != n && !g[i + 1][j]) adde(v + m, u, 1);
                        if(j != m && !g[i][j + 1]) adde(v + 1, u, 1);
                    }
                    
                }
            }
            int res = dinic(S, T, T + 1);
            if(res * 2 != n * m - k) flag = false;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
