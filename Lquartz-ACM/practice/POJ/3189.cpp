//#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define NAME ""

#define Maxn 1041
#define Maxm 80111
const int INF = 2000000000;

struct node {
    int u, v, c, w, next;
}e[Maxm];
int tot, last[Maxn];
int n, b;
int dist[Maxn], visit[Maxn], pre[Maxn];
queue<int> que;

void adde(int u, int v, int c, int w) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].w = w; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].w = -w; e[tot].next = last[v]; last[v] = tot++;
}

int spfa(int s, int t, int n) {
    int i, j, k, u, v, w;
    for(i = 0; i < n; i++) {
        dist[i] = INF;
    }
    while(!que.empty()) que.pop();
    dist[s] = 0;
    que.push(s);
    while(!que.empty()) {
        u = que.front(); que.pop();
        for(j = last[u]; j != -1; j = e[j].next) {
            if(e[j].c == 0) continue;
            v = e[j].v;
            if(dist[v] == INF) {
                dist[v] = dist[u] + 1;
                if(v == t) return 1;
                que.push(v);
            }
        }
    }
    return 0;
}

int changeflow(int s, int t, int n) {
    int i, j, k, u, v, w;
    int det = INF;
    v = t; j = pre[v];
    while(j != -1) {
        cmin(det, e[j].c);
        v = e[j].u;
        j = pre[v];
    }
    v = t; j = pre[v];
    while(j != -1) {
        e[j].c -= det;
        e[j ^ 1].c += det;
        v = e[j].u; j = pre[v];
    }
    return det;
}

int MaxFlow(int s, int t, int n) {
    int ret = 0;
    while(spfa(s, t, n)) {
        ret += changeflow(s, t, n);
    }
    return ret;
}

int cur[Maxn];
int sta[Maxn], top;

int dinic(int s, int t, int n) {
    int maxflow, i, j, k, u, v, w;
    int tp;
    maxflow = 0;
    while(spfa(s, t, n)) {
        for(i = 0; i < n; i++) cur[i] = last[i];
        u = s;
        top = 0;
        while(cur[s] != -1) {
            if(u == t) {
                tp = INF;
                for(i = 0; i < top; i++) {
                    cmin(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--) {
                    e[sta[i]].c -= tp;
                    e[sta[i] ^ 1].c += tp;
                    if(e[sta[i]].c == 0) {
                        top = i;
                    }
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

int rank[Maxn][30];
int flow[Maxn];

int build(int l, int r) {
    int i, j, k, u, v, w;
    int N = n + b + 3, S = 0, T = n + b + 1;
    for(i = 0; i < N; i++) last[i] = -1;
    tot = 0;
    for(i = 1; i <= n; i++) {
        adde(S, i, 1, 0);
        for(j = l; j <=r; j++) {
            w = rank[i][j];
            adde(i, w + n, 1, j - 1);
        }
    }
    for(j = 1; j <= b; j++) {
        w = flow[j];
        adde(n + j, T, w, 0);
    }
    k = dinic(S, T, N);
    if(k >= n) return 1;
    else return 0;
}

int main() {
    int i, j, k, u, v, w;
    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);

    while(scanf("%d%d", &n, &b) != EOF) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= b; j++) scanf("%d", &rank[i][j]);
        }
        for(j = 1; j <= b; j++) scanf("%d", &flow[j]);
        int flag = 0;
        for(k = 1; k <= b; k++) {
            if(flag) break;
            for(i = 1; i <= b; i++) {
                j = i + k - 1;
                if(j > b) break;
                if(build(i, j)) {
                    printf("%d\n", k);
                    flag = 1;
                    break;
                }
            }
        }
    }

    return 0;
}
