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
#define Maxn 11111
#define Maxm 111111
struct node {
    int u, v, next;
    double c;
}e[Maxm];
int tot, last[Maxn];
int d[Maxn];
int n, m;
vector<PII> edge;
int cur[Maxn], que[Maxn], sta[Maxn], top, head, tail;
int dist[Maxn];
void adde(int u, int v, double c, double c0) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = c0; e[tot].next = last[v]; last[v] = tot++;
}
bool bfs(int s, int t, int n) {
    int i, j, u, v;
    for(i = 0; i < n; i++) dist[i] = n + n;
    dist[s] = 0;
    head = tail = 0;
    que[tail++] = s;
    while(head < tail) {
        u = que[head++];
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(e[j].c < eps) continue;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                if(v == t) return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}
double dinic(int s, int t, int n) {
    int i, j, u, v;
    double maxflow = 0;
    while(bfs(s, t, n)) {
        for(i = 0; i < n; i++) cur[i] = last[i];
        u = s; top = 0;
        while(cur[s] != -1) {
            if(u == t) {
                double tp = 1e20;
                for(i = top - 1; i >= 0; i--) {
                    tp = min(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--) {
                    e[sta[i]].c -= tp;
                    e[sta[i] ^ 1].c += tp;
                    if(e[sta[i]].c < eps) top = i;
                }
                u = e[sta[top]].u;
            }
            else if(cur[u] != -1 && e[cur[u]].c > eps && dist[u] + 1 == dist[e[cur[u]].v]) {
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
void build(int S, int T, int N, double g) {
    int i, j, u, v, w;
    tot = 0;
    for(i = 0; i < N; i++) last[i] = -1;
    for(i = 1; i <= n; i++) adde(S, i, m, 0);
    for(i = 0; i < m; i++) {
        u = edge[i].AA, v = edge[i].BB;
        adde(u, v, 1, 0);
        adde(v, u, 1, 0);
    }
    for(i = 1; i <= n; i++) {
        adde(i, T, m + 2 * g - d[i], 0);
    }
}
int used[Maxn];
vector<int> ans;
void dfs(int u) {
    used[u] = 1;
    if(1 <= u && u <= n) {
        ans.PB(u);
    }
    for(int j = last[u]; j != -1; j = e[j].next) {
        int v = e[j].v;
        if(e[j].c > eps && !used[v]) {
            dfs(v);
        }
    }
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d%d", &n, &m) != EOF) {
//        scanf("%d%d", &n, &m);
        if(m == 0) {
            printf("1\n1\n");
            continue;
        }
        edge.clear();
        for(i = 1; i <= n; i++) d[i] = 0;
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            edge.PB(MP(u, v));
            d[u]++; d[v]++;
        }
        int S = 0, T = n + 1, N = T + 2;
        double l = 0., r = m + eps, mid;
        while((r - l) > 1.0 / n / n) {
            mid = (l + r) / 2;
            build(S, T, N, mid);
            double flow = dinic(S, T, N);
            if(0.5 * (1.0 * n * m - flow) > eps)
                l = mid;
            else r = mid;
        }
//        cerr << (l + r) / 2 << endl;
        build(S, T, N, l);
        double flow = dinic(S, T, N);
        ans.clear();
        for(i = 0; i <= N; i++) used[i] = 0;
        dfs(S);
        printf("%d\n", ans.SZ);
        sort(ans.BG, ans.ED);
        for(i = 0; i < ans.SZ; i++) printf("%d\n", ans[i]);
//        cerr << (l + r) / 2 << " " << flow <<" " << 0.5 * (n * m - flow) << "\n";
    }
    return 0;
}

