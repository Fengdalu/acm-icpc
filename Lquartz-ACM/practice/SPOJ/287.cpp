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
#define Maxn 511
#define Maxm 251111

struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int cur[Maxn], dist[Maxn], que[Maxn], sta[Maxn], head, tail, top;

void adde(int u, int v, int c, int c1) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = c1; e[tot].next = last[v]; last[v] = tot++;
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
int n, m, k;
int pt[Maxn], x[Maxm], y[Maxm];
bool check(int va) {
    int i, j;
    tot = 0;
    int N = n + 2, S = 0, T = n + 1;
    for(i = 0; i <= N; i++) last[i] = -1;
    for(i = 0; i < m; i++) adde(x[i], y[i], va, va);
    for(i = 0; i < k; i++) adde(pt[i], T, 1, 0);
    adde(S, 1, k, 0);
    if(dinic(S, T, N) == k) return true;
    else return false;
}

int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    while(te--) {
        scanf("%d%d%d", &n, &m, &k);
        for(i = 0; i <k; i++) scanf("%d", &pt[i]);
        for(i = 0; i < m; i++) scanf("%d%d", &x[i], &y[i]);
        int l = 1, r = k + 1, mid, ans;
        while(l < r - 1) {
            mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        if(check(l)) ans = l;
        else ans = r;
        printf("%d\n", ans);
    }
    return 0;
}
