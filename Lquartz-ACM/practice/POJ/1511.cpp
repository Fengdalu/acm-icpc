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
#define Maxn 1000111
#define Maxm 1011111
struct node {
    int u, v, l, next;
}e[Maxm];
int tot, last[Maxn];
int visit[Maxn];
int dist[2][Maxn];
int n, m;
queue<int> Q;
void adde(int u, int v, int l) {
    e[tot].u = u; e[tot].v = v; e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
}
void spfa(int s, int n, int o) {
    int i, j, u, v;
    for(i = 1; i <= n; i++) dist[o][i] = MOD, visit[i] = false;
    dist[o][s] = 0;
    while(!Q.empty()) Q.pop();
    Q.push(s);
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(dist[o][v] > dist[o][u] + e[j].l) {
                dist[o][v] = dist[o][u] + e[j].l;
                if(!visit[v]) {
                    visit[v] = true;
                    Q.push(v);
                }
            }
        }
        visit[u] = false;
    }
}

int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te, ca = 0;
    scanf("%d", &te);
    while(te--) {
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; i++) last[i] = -1;
        tot = 0;
        for(j = 0; j < m; j++) {
            scanf("%d%d%d", &u, &v, &w);
            adde(u, v, w);
        }
        spfa(1, n, 0);
        for(i = 1; i <= n; i++) last[i] = -1;
        tot = 0;
        for(j = 0; j < m; j++) {
            adde(e[j].v, e[j].u, e[j].l);
        }
        spfa(1, n, 1);
        LL ans = 0;
        for(i = 2; i <= n; i++) ans += dist[0][i] + dist[1][i];
        printf("%I64d\n", ans);
    }
    return 0;
}

