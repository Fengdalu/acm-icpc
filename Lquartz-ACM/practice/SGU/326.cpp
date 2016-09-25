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
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 1111
#define Maxm 5111
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int cur[Maxn], dist[Maxn], que[Maxn], sta[Maxn], head, tail, top;

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

int n, w[30], r[30], s[30], sum, g[30][30];


int main() {
    int i, j, u, v;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        sum = 0;
        int all = 0;
        for(i = 1; i <= n; i++) scanf("%d", &w[i]);
        sum += w[1];
        for(i = 1; i <= n; i++) scanf("%d", &r[i]);
        for(i = 1; i <= n; i++) {
            s[i] = 0;
            for(j = 1; j <= n; j++) {
                scanf("%d", &g[i][j]);
                s[i] += g[i][j];
            }
        }
        sum += r[1];
        int N = n + n * n + 2, S = 0, T = N - 1;
        for(i = 0; i <= N; i++)last[i] = -1;
        tot = 0;
        for(i = 2; i <= n; i++) {
            adde(S, i, w[i]);
            adde(i, T, sum);
            all += w[i];
        }
        for(i = 2; i <= n; i++) {
            for(j = i + 1; j <= n; j++) {
                if(g[i][j] > 0) {
                    all += g[i][j];
                    u = (i - 1) * n + j + n;
                    adde(S, u, g[i][j]);
                    adde(u, i, g[i][j]);
                    adde(u, j, g[i][j]);
                }
            }
        }
        if(all == dinic(S, T, N)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

