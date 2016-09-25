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
#define N 111111
#define M 111111
int n, m;
int g[N];
struct node {
    int u, v, next;
}E[M];
int last[N], tot = 0;
int fa[N];
LL cnt[N];
int used[N];
vector <PII> gao;
void addedge(int u, int v) {
    E[tot].u = u; E[tot].v = v; E[tot].next = last[u]; last[u] = tot++;
    E[tot].u = v; E[tot].v = u; E[tot].next = last[v]; last[v] = tot++;
}
int getfa(int x) {
    if(fa[x] == x) return x;
    return (fa[x] = getfa(fa[x]));
}
int main() {
    int i, j;
    int u, v, x, y;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 0; i <= n; i++) last[i] = -1;
        tot = 0;
        gao.clear();
        for(i = 1; i <= n; i++) {
            scanf("%d", &g[i]);
            used[i] = 0;
        }
        
        for(i = 0; i < m; i++) {
            scanf("%d%d", &E[i].u, &E[i].v);
            gao.PB(MP(min(g[E[i].u], g[E[i].v]), i));
        }
        sort(gao.BG, gao.ED);
        for(i = 1; i <= n; i++) {
            fa[i] = i;
            cnt[i] = 1;
        }
        LL ans = 0;
        for(i = m - 1; i >= 0; i--) {
            j = gao[i].BB;
            LL value = gao[i].AA;
            x = getfa(E[j].u); y = getfa(E[j].v);
            if(x != y) {
//                cout << E[j].u << " " << E[j].v << " " << x << " " << y << endl;
                ans += value * (LL)(cnt[x] * cnt[y]);
                fa[x] = y;
                cnt[y] += cnt[x];
            }
        }
//        cout << ans << endl;
        printf("%.6lf\n", 2.0 * ans / (LL)((LL)n * (LL)(n - 1)));
    }
    
    return 0;
}
