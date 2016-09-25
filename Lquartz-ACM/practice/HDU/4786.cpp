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
#define Maxn 111111
#define Maxm 111111
vector<pair<int, PII> > g[2];
int fa[Maxn];
int getfa(int x) {
    if(x == fa[x]) return x;
    else return (fa[x] = getfa(fa[x]));
}
int f[100];
int n, m;
int main() {
    int i, j, k, p, u, v, w, x, y;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    f[0] = 1;
    f[1] = 1;
    for(i = 2; i < 30 && f[i - 1] < Maxn; i++) f[i] = f[i - 1] + f[i - 2];
    k = i;
    int dmax, dmin;
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d%d", &n, &m);
        g[0].clear(); g[1].clear();
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            g[w].PB(MP(w, MP(u, v)));
        }
        dmax = dmin = 0;
        for(i = 1; i <= n; i++) fa[i] = i;
        for(p = 0, j = 0; p < 2; p++) {
            for(i = 0; i < g[p].SZ; i++) {
                u = g[p][i].BB.AA; v = g[p][i].BB.BB; w = g[p][i].AA;
                x = getfa(u); y = getfa(v);
                if(x != y) {
                    fa[x] = y;
                    j++;
                    dmin += w;
                    if(j == n -1) break;
                } 
            }
        }
        printf("Case #%d: ", ca);
        if(j < n - 1) {
            printf("No\n");
            continue;
        }
        for(i = 1; i <= n; i++) fa[i] = i;
        for(p = 1, j = 0; p >= 0; p--) {
            for(i = 0; i < g[p].SZ; i++) {
                u = g[p][i].BB.AA; v = g[p][i].BB.BB; w = g[p][i].AA;
                x = getfa(u); y = getfa(v);
                if(x != y) {
                    fa[x] = y;
                    j++;
                    dmax += w;
                    if(j == n -1) break;
                } 
            }
        }
        for(i = 1; i < k; i++) {
            if(dmin <= f[i] && f[i] <= dmax) break;
        }
        if(i < k) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
