#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
#define Maxn 110
#define Maxm 20100
int mincost, maxflow;
int n;
struct node {
    int u, v, c, next;
} e[Maxm];
int tot, last[Maxn];
bool visit[Maxn];
queue<int> Q;
#define MOD 0x3f3f3f3f
int g[Maxn][Maxn];
int f[Maxn][Maxn];
int cur[Maxn], que[Maxn], sta[Maxn], head, tail, top, dist[Maxn];

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
    int i, j, k, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        for(i = 0; i < n;i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &g[i][j]);
                if(i != j) f[i][j] = g[i][j];
//                else f[i][j] = 0;
            }
        }
        scanf("%d%d", &u, &v);
        if(u == v) {
            printf("inf\n");
            continue;
        }
        for(k = 0; k < n; k++) {
            for(i = 0; i < n; i++) {
                if(i == k) continue;
                if(f[i][k] == -1) continue;
                for(j = 0; j < n; j++) {
                    if(j == i || j == k) continue;
                    if(f[k][j] == -1) continue;
                    if(f[i][j] == -1 || f[i][j] > f[i][k] + f[k][j]) {
                        f[i][j] = f[i][k] + f[k][j];
                    }
                }
            }
        }
        tot = 0;
        int N = n, S = u, T = v;
        for(i = 0; i <= N; i++) last[i] = -1;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                //因为没有对f[][]初始化为MOD, 所以注意f[][]==-1的情况的特判!
                if(f[u][v] != -1 && f[u][i] != -1 && f[j][v] != -1 && g[i][j] != -1 && f[u][i] + g[i][j] + f[j][v] == f[u][v]) {
                    adde(i, j, 1);
                }
            }
        }
        printf("%d\n", dinic(u, v, n));
    }
    return 0;
}
/*
5
0 1 1 1 -1
-1 0 -1 -1 1
-1 -1 0 -1 1
-1 -1 -1 0 1
-1 -1 -1 -1 0
0 4

5
0 1 1 2 -1
-1 0 -1 -1 1
-1 -1 0 -1 1
-1 -1 -1 0 1
-1 -1 -1 -1 0
0 4

*/
