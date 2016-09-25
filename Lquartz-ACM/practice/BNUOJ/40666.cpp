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
#define Maxn 13111
#define Maxm 211111
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
//ISAP O(m*n^2)
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}

int dist[Maxn], cur[Maxn], gap[Maxn], pre[Maxn];
int ISAP(int s, int t, int n) {
    int i, j, u, v, det;
    int maxflow = 0;
    memset(dist, 0, sizeof(dist[0]) * (n + 3));
    memset(gap, 0, sizeof(gap[0]) * (n + 3));
    for (i = 0; i < n; i ++ )
        cur[i] = last[i];
    u = s;
    gap[0] = n;
    pre[s] = -1;
    while (dist[s] <= n) {
        bool flag = false;
        for (j = cur[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if (e[j].c > 0 && dist[u] == dist[v] + 1) {
                flag = true;
                pre[v] = u;
                cur[u] = j;
                u = v;
                break;
            }
        }
        if (flag) {
            if (u == t) {
                int det = MOD;
                for (i = u; i != s; i = pre[i])
                    det = min(det, e[cur[pre[i]]].c);
                for (i = u; i != s; i = pre[i]) {
                    e[cur[pre[i]]].c -= det;
                    e[cur[pre[i]] ^ 1].c += det;
                }
                maxflow += det;
                u = s;
            }
        }
        else {
            int mind = n;
            for (j = last[u]; j != -1; j = e[j].next ) {
                v = e[j].v;
                if (e[j].c > 0 && dist[v] < mind) {
                    mind = dist[v];
                    cur[u] = j;
                }
            }
            if (( -- gap[dist[u]]) == 0) break;
            gap[dist[u] = mind + 1] ++ ;
            if (u != s) u = pre[u];
        }
    }
    return maxflow;
}

int te, n, m;
int sx, sy, ex, ey;
int g[55][55];
int visit[55][55];
int inque[55][55];
queue<PII> Q;
vector<pair<int, PII> > from[Maxn];
void ready(int S, int T, int N) {
    int i, j, k, u, v, w, x, y, z;
    while(!Q.empty()) Q.pop();
    Q.push(MP(sx, sy));
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            from[(i - 1) * m + j].clear();
            visit[i][j] = 0;
        }
    }
    visit[sx][sy] = 1;
    while(!Q.empty()) {
        u = Q.front().AA, v = Q.front().BB;
        Q.pop();
        i = (u - 1) * m + v;
//        cout << "pop " << u << " " << v << endl;
        for(k = 0; k < 4; k++) {
            x = u + dx[k]; y = v + dy[k];
            if(x < 1 || y < 1 || x > n || y > m) continue;
            if(g[x][y] > g[u][v]) continue;
            j = (x - 1) * m + y;
            from[j].PB(MP(g[u][v] - g[x][y] + 1, MP(i, (k + 2) % 4)));
            if(!visit[x][y]) {
                Q.push(MP(x, y));
                visit[x][y] = 1;
            }
        }
    }
}
int main() {
    int i, j, k, u, v, w, x, y, z;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d%d", &n, &m);
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) scanf("%d", &g[i][j]);
        }
        if(abs(sx - ex) + abs(sy - ey) < 2) {
            if(g[sx][sy] >= g[ex][ey]) {
                printf("-1\n");
                continue;
            }
            else {
                printf("0\n");
                continue;
            }
        }
//        cout << "xx " << endl;
        int S = 0, N = 5 * n * m + 10, M = n * m, T = N - 1;
        for(i = 0; i <= N; i++) last[i] = -1;
        tot = 0;
        ready(S, T, N);
        if(!visit[ex][ey]) {
            printf("0\n");
            continue;
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                v = (i - 1) * m + j;
                sort(from[v].BG, from[v].ED);
                for(k = 0; k < from[v].SZ; k++) {
                    u = from[v][k].BB.AA;
                    w = from[v][k].AA;
                    adde(4 * M + u, from[v][k].BB.BB * M + v, w);
                }
                from[v].PB(MP(0, MP(v, 4)));
                for(k = 0; k < from[v].SZ - 1; k++) {
                    x = from[v][k].BB.BB * M + v;
                    y = from[v][k + 1].BB.BB * M + v;
                    w = from[v][k].AA;
                    adde(x, y, w);
                }
            }
        }
        adde(S, (sx - 1) * m + sy + 4 * n * m, MOD);
        for(k = 0; k < 4; k++) {
            u = ex + dx[k]; v = ey + dy[k];
            if(1 <= u && u <= n && 1 <= v && v <= m) {
                if(g[u][v] >= g[ex][ey])
                    adde((u - 1) * m + v + 4 * n * m, T, MOD);
            }
        }
        printf("%d\n", ISAP(S, T, N));
    }
    return 0;
}

/*
8

4 2
1 1 3 2
10 11
6 6
4 4
3 4

1 5
1 2 1 3
3 4 2 5 5

4 2
1 1 1 2
10 11
6 6
4 4
3 4

3 3
1 1 3 3
1 1 1
1 1 1
1 1 1

6 7
1 1 6 7
100 90 80 70 60 59 49
90 101 101 101 101 101 39
80 70 60 50 101 101 29
70 101 101 40 101 101 19
60 101 101 30 101 101 9
50 40 30 22 23 24 0


6 7
1 1 6 7
100 90 80 70 60 59 49
90 101 101 101 101 101 39
80 70 60 50 101 101 29
70 101 101 43 101 101 19
60 101 101 36 101 101 9
50 43 36 30 20 10 0

6 7
1 1 6 7
100 90 80 70 60 59 49
90 101 101 101 101 101 39
80 70 60 50 101 101 29
70 101 101 43 101 101 19
62 101 101 36 101 101 9
52 47 38 30 20 10 0

7 8
1 2 6 8
99 100 101 80 70 60 59 49
98 90 101 101 101 101 101 39
97 80 70 60 50 101 101 29
96 70 101 101 43 101 101 19
95 62 101 101 36 101 101 9
94 54 46 38 30 20 10 1
93 92 91 90 80 0 0 0
*/
