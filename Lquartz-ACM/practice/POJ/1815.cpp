#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define Maxn 444
#define Maxm 160000
#define MOD 10000007
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int n, m, S, T;
int g[Maxn / 2][Maxn / 2];
int flow[Maxn], visit[Maxn];

int cur[Maxn], dist[Maxn], que[Maxn], head, tail, sta[Maxn], top;

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
        u = s; top = 0;
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
                    e[sta[i]^1].c += tp;
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

bool dfs(int u, int t) {
    visit[u] = true;
    cout << "dfs " << u << " " << t << endl;
    if(u == t) return true;
    int j, v;
    for(j = last[u]; j != -1; j = e[j].next) {
        v = e[j].v;
        if(e[j].c > 0 && !visit[v]) {
            if(dfs(v, t)) return true;
        }
    }
    return false;
}

int main() {
    int i, j, k, u, v, w;
    int N, src, des;
    while(scanf("%d%d%d", &n, &src, &des) != EOF) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                scanf("%d", &g[i][j]);
            }
        }
        if(g[src][des]) {
            printf("NO ANSWER!\n");
            continue;
        }
        int used[Maxn];
        for(i = 0; i <= n + 1; i++) used[i] = 1;
        for(i = 0; i <= n + 1; i++) {
            if(i != src && i != des) {
                S = 0, T = 2 * n + 1, N = T + 1;
                for(k = 0; k < N; k++) {
                    last[k] = -1;
                }
                tot = 0;
                adde(S, src, MOD);
                adde(des + n, T, MOD);
                for(j = 1; j <= n; j++) {
                    if(j == i || !used[j]) continue;
                    else if(j == src || j == des) {
                        adde(j, j + n, MOD);
                    }
                    else {
                        adde(j , j + n, 1);
                    }
                    for(k = 1; k <= n; k++) {
                        if(k == i || !used[k]) continue;
                        if(g[j][k])
                            adde(j + n, k, MOD);
                    }
                }
                flow[i] = dinic(S, T, N);
//                cout << "flow " << i << " " << flow[i] << endl;
                if(i && flow[i] < flow[i - 1]) used[i] = 0;
                if(flow[i] == 0) break;
            }
            else flow[i] = flow[i - 1];
        }
        vector<int> ans, tp;
        for(i = 1; i <= n; i++) {
            if(i == src || i == des) continue;
            if(!used[i]) tp.push_back(i);
        }
//        cout << "Maxflow " << flow[n + 1] << endl;
//        for(j = 0; j < tot; j++) cout << "e " << e[j].u << " " << e[j].v << " " << e[j].c << endl;
//        for(i = 1; i <= n; i++) {
//            for(j = 0; j < N; j++) visit[j] = false;
//            for(j = last[i]; j != -1; j = e[j].next) {
//                if(e[j].v == i + n && e[j].c == 0){
//                    if(!dfs(i, i + n)) ans.push_back(i);
//                    break;
//                }
//            }
//        }

        printf("%d\n", tp.size());
        for(i = 0; i < tp.size(); i++) {
            if(i) printf(" ");
            printf("%d", tp[i]);
        }
        printf("\n");
    }
    return 0;
}

/*
input
10 10 1
0 1 1 1 1 0 1 1 0 0 
1 0 0 0 0 1 1 1 1 1 
1 0 0 1 1 1 1 1 1 1 
1 0 1 0 1 1 0 1 1 0 
1 0 1 1 0 0 1 1 1 1 
0 1 1 1 0 0 1 0 0 1 
1 1 1 0 1 1 0 1 1 0 
1 1 1 1 1 0 1 0 0 0 
0 1 1 1 1 0 1 0 0 1 
0 1 1 0 1 1 0 0 1 0 
output
5
2 3 4 5 7

8 8 5
0 1 1 1 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 0 1 0 0
0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0
1 0 1 0 0 0 0 0
2
1 3
*/
