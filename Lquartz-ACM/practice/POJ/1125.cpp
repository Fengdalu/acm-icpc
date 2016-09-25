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
#define Maxn 111
#define Maxm 111111
int n, k;
int f[Maxn][Maxn];
int ans[Maxn];
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF && n) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                f[i][j] = MOD;
            }
            f[i][i] = 0;
        }
        for(i = 1; i <= n; i++) {
            scanf("%d", &k);
            for(j = 0; j < k; j++) {
                scanf("%d%d", &v, &w);
                cmin(f[i][v], w);
            }
        }
        for(k = 1; k <= n; k++) {
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= n; j++) {
                    cmin(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        u = 0;
        ans[0] = MOD;
        for(i = 1; i <= n; i++) {
            ans[i] = 0;
            for(j = 1; j <= n; j++) {
                cmax(ans[i], f[i][j]);
            }
            if(ans[i] < ans[0]) {
                ans[0] = ans[i]; u = i;
            }
        }
        printf("%d %d\n", u, ans[0]);
    }
    return 0;
}
