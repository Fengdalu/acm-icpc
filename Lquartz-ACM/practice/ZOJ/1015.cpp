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
#define Maxm 111111
int adj[Maxn][Maxn];
int n, m;
vector<int> g[Maxn];
int L[Maxn], cnt[Maxn], visit[Maxn], mpL[Maxn];
set<PII> S;
int getList() {
    int i, j, k, u, v, w;
    S.clear();
    for(i = 1; i <= n; i++) cnt[i] = 0, visit[i] = 0;
    S.insert(MP(0, 1));
    k = n;
    while(!S.empty()) {
        u = (*S.BG).BB; w = -(*S.BG).AA;
        S.erase(S.BG);
        if(w != cnt[u]) continue;
        visit[u] = 1;
        mpL[u] = k;
        L[k--] = u;
        for(j = 0; j < g[u].SZ; j++) {
            v = g[u][j];
            if(!visit[v]) {
                cnt[v]++;
                S.insert(MP(-cnt[v], v));
            }
        }
    }
    for(i = k + 1; i <= n; i++) printf("L %d %d\n", i, L[i]);
    if(k < 1) return true;
    else return false;
}
int check() {
    int i, j, k, u, v, w;
    k = -1; w = n + 1;
    for(i = n - 1; i >= 1; i--) {
        u = L[i];
        for(j = 0; j < g[u].SZ; j++) {
            v = g[u][j];
            if(mpL[v] > i) {
                if(mpL[v] < w) {
                    w = mpL[v];
                    k = v;
                }
            }
        }
        if(k != -1) {
            for(j = 0; j < g[u].SZ; j++) {
                v = g[u][j];
                if(mpL[v] > i && v != k) {
                    if(!adj[v][k]) return false;
                }
            }
        }
    }
    return true;
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d%d", &n, &m) != EOF) {
        if(!n && !m) break;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            adj[u][v] = adj[v][u] = 1;
        }
        for(i = 1; i <= n; i++) g[i].clear();
        for(i = 1; i <= n; i++) {
            for(j = i + 1; j <= n; j++) {
                if(adj[i][j]) {
                    g[i].PB(j); g[j].PB(i);
                }
            }
        }
        
        if(getList() && check()) {
            printf("Perfect\n");
        }
        else {
            printf("Imperfect\n");
        }
        printf("\n");
    }
    return 0;
}

