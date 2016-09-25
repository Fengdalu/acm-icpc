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
#define Maxn 20
#define Maxm 111111

#define eps 1e-10
#define fabs(x) ((x)>eps?(x):-(x))
#define ZERO(x) (fabs(x) > eps ? 0 : 1)
int gauss_tpivot (int n, double a[][Maxn]) {
    int i, j, k, p;
    double maxp, t;
    for (k = 0; k < n; k++) {
        if(ZERO(a[k][k])) {
            for(i = k + 1; i < n; i++) if(!ZERO(a[i][i])) break;
            if(i >= n) return 0;
            for(j = k; j < n; j++) {
                swap(a[k][j], a[i][j]);
            }
        }
        maxp = a[k][k];
        for (j = k + 1; j < n; j++) {
            a[k][j] /= maxp;
            for (i = k + 1; i < n; i++)
                a[i][j] -= a[i][k] * a[k][j];
        }
    }
    return 1;
}
double a[Maxn][Maxn], b[Maxn][Maxn];
int n, m;
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d%d", &n, &m);
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++) {
                a[i][j] = b[i][j] = 0;
            }
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            if(u == v) continue;
            u--; v--;
            a[u][u]++; a[v][v]++;
            b[u][v] = b[v][u] = 1;
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                a[i][j] = a[i][j] - b[i][j];
            }
        }
        double ans = 0;
        if(gauss_tpivot(n - 1, a)) {
            ans = 1;
            for(i = 0; i < n - 1; i++) ans *= a[i][i];
        }
        else ans = 0;
        printf("%0.0f\n", ans);
    }
    return 0;
}

