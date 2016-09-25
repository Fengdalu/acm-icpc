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
#define Maxm 61111
//dinic O(m*n^2)
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
int n, m, c, sumr, sumc;
int row[300], col[50], big[300][50], small[300][50], mat[300][50];

int main() {
    int i, j, u, v, w;
    char opt[10];
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    int rl, rr, cl, cr;
    scanf("%d", &te);
    for(int ca = 0; ca < te; ca++) {
        scanf("%d%d", &n, &m);
        sumr = 0; sumc = 0;
        for(i = 1; i <= n; i++) {scanf("%d", &row[i]); sumr += row[i];}
        for(i = 1; i <= m; i++) {scanf("%d", &col[i]); sumc += col[i];}
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                big[i][j] = MOD;
                small[i][j] = 0;
            }
        }
        scanf("%d", &c);
        while(c--) {
            scanf("%d%d%s%d", &u, &v, opt, &w);
            rl = rr = u; cl = cr = v;
            if(u == 0) {rl = 1; rr = n;}
            if(v == 0) {cl = 1; cr = m;}
            if(opt[0] == '=') {
                for(i = rl; i <= rr; i++) {
                    for(j = cl; j <= cr; j++) {
                        cmin(big[i][j], w);
                        cmax(small[i][j], w);
                    }
                }
            }else if(opt[0] == '>') {
                for(i = rl; i <= rr; i++) {
                    for(j = cl; j <= cr; j++) {
                        cmax(small[i][j], w + 1);
                    }
                }
            } else if(opt[0] == '<') {
                for(i = rl; i <= rr; i++) {
                    for(j = cl; j <= cr; j++) {
                        cmin(big[i][j], w - 1);
                    }
                }
            }
        }
        int flag = true;
        if(sumr != sumc) flag = false;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                if(big[i][j] < small[i][j]) {flag = false; break;}
            }
            if(!flag) break;
        }
        if(flag) {
            int M = n * m;
            int N = n + m + 4, S = 0, T = n + m + 1, SS = T + 1, TT = SS + 1;
            for(i = 0; i <= N; i++) last[i] = -1;
            tot = 0;
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= m; j++) {
                    u = i, v = n + j;
                    adde(SS, v, small[i][j], 0);
                    adde(u, TT, small[i][j], 0);
                    adde(u, v, big[i][j] - small[i][j], 0);
                }
            }
            for(i = 1; i <= n; i++) {
                adde(SS, i, row[i], 0);
                adde(S, TT, row[i], 0);
//                adde(S, i, row[i], 0);
            }
            for(j = 1; j <= m; j++) {
                adde(SS, T, col[j], 0);
                adde(n + j, TT, col[j], 0);
//                adde(n + j, T, col[i], 0);
            }
            adde(T, S, MOD, 0);
            adde(TT, SS, MOD, 0);
            dinic(SS, TT, N);
            dinic(SS, TT, N);
//            for(i = 0; i < tot; i++) cout << "edge " << i << " " << e[i].u << "->" << e[i].v << " " << e[i].c << endl;
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= m; j++) {
                    u = (i - 1) * m + j - 1;
                    u *= 6;
                    if(e[u].c > 0) {
//                        cout << "fail " << i << " " << j << " " << u << endl;
                        flag = false; 
                        break;
                    }
                    mat[i][j] = small[i][j] + e[u + 5].c;
                }
                if(!flag) break;
            }
        }
        if(ca) printf("\n");
        if(!flag) printf("IMPOSSIBLE\n");
        else {
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= m; j++) {
                    if(j > 1) printf(" ");
                    printf("%d", mat[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
