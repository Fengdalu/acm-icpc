#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 400
#define Maxm 3000
#define MOD (1<<30)
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int n, m, p, N, S, T;

int cur[Maxn], sta[Maxn], que[Maxn], dist[Maxn], head, tail, top;
bool bfs(int s, int t, int n) {
    int i, j, u, v, d;
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
            if(e[j].c && dist[v] > dist[u] + 1) {
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
    int i, j, u, v, tp;
    while(bfs(s, t, n)) {
        top = 0;
        u = s;
        for(i = 0; i < n; i++) cur[i] = last[i];
        while(cur[s] != -1) {
            if(u == t) {
                tp = MOD;
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
                sta[top++] =cur[u];
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

int visit[2][Maxn];
void dfs(int u, int o) {
    int j, v;
    visit[o][u] = 1;
    for(j = last[u]; j != -1; j = e[j].next) {
        v = e[j].v;
        if(o == 0) if(e[j].c == 0) continue;
        if(o == 1) if(e[j ^ 1].c == 0) continue;
        if(!visit[o][v]) {
            dfs(v, o);
        }
    }
}
void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}
int x[Maxm], y[Maxm], z[Maxm];
int main() {
    int i, j, u, v, w;
    while(scanf("%d%d%d", &n, &m, &p) && n) {
        tot = 0;
        N = n + m + 2;
        S = n + m + 1; T = 0;
        for(i = 0; i < N; i++) last[i] = -1;
        for(i = 0; i < p; i++) {
            scanf("%d%d%d", &u, &v, &w);
            adde(u, v, w);
            x[i] = u; y[i] = v; z[i] = w;
        }
        for(i = 1; i <= n; i++) adde(S, i, MOD);
        int maxflow = dinic(S, T, N);
        for(i = 0; i < N; i++) visit[0][i] = visit[1][i] = 0;
        dfs(S, 0);
        dfs(T, 1);
        vector<int> ans;
        for(i = 0; i < p; i++) {
            j = i<<1;
            if(e[j].c > 0) continue;
            if((visit[0][x[i]] && visit[1][y[i]]) || 
               (visit[0][y[i]] && visit[1][x[i]])) {
                ans.push_back(i + 1);
            }
        }
        for(i = 0; i < ans.size(); i++) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
