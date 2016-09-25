#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 1000
#define Maxm 40000
#define MOD 1000000007
struct node {
    int u, v, c, next;
}e[Maxm];
int tot,  last[Maxn], cur[Maxn];
int dist[Maxn], que[Maxn], sta[Maxn], top, head, tail;
int n, m, d, S, T;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

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
    int maxflow = 0;
    int i, j, u, v;
    while(bfs(s, t, n)) {
        for(i = 0; i < n; i++) cur[i] = last[i];
        top = 0; u = s;
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
    int i, j, u, v, w, a, x, y, k, l;
    char str[100];
    int Te;
    scanf("%d", &Te);
    for(int CA = 1; CA <= Te; CA++) {
        scanf("%d%d", &n, &d);
        tot = 0;
        scanf("%s", str);
        m = strlen(str);
        a = (n + 2)* (m + 2);
        for(i = 0; i < 2 * a + 10; i++) last[i] = -1;
        S = 0; T = 2 * a + 1;
        for(i = 1; i <= n; i++) {
            if(i > 1) scanf("%s", str);
            for(j = 1; j <= m; j++) {
                u = i * (m + 2)+ j + 1;
                v = u + a;
                w = str[j - 1] - '0';
                adde(u, v, w);
                for(k = 0; k <= n + 1; k++) {
                    for(l = 0; l <= m + 1; l++) {
                        int dd = abs(i - k) + abs(j - l);
                        if(dd <= d) {
                            if(k == 0 || l == 0 || k == n + 1 || l == m + 1) {
                                adde(v, T, MOD);
                            }
                            else {
                                adde(v, k * (m + 2)+ l + 1, MOD);
                            }
                        }
                    }
                }
            }
        }
        int all = 0;
        for(i = 1; i <= n; i++) {
            scanf("%s", str);
            for(j = 1; j <= m; j++) {
                u = i * (m + 2)+ j + 1;
                v = u + a;
                if(str[j - 1] == 'L') {
                    adde(S, u, 1);
                    all++;
                }
            }
        }
        int maxflow = dinic(S, T, T + 1);
        printf("Case #%d: ", CA);
        if(maxflow == all) {
            printf("no lizard was left behind.\n");
        }
        else if(all - maxflow == 1) {
            printf("1 lizard was left behind.\n");
        }
        else printf("%d lizards were left behind.\n", all - maxflow);
    }
    return 0;
}
