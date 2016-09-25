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
#define N 21111
vector<int> g[N];
int n, ans;
void dfs(int u, int dep) {
    ans += dep;
    if(g[u].SZ == 0) return;
    int j = 0;
    for(j = 0; (1<<j) < g[u].SZ; j++);
    cout << "~ " << u << " " << g[u].SZ << " " << j << endl;
    for(int i = 0; i < g[u].SZ; i++) {
        int v = g[u][i];
        dfs(v, dep+ j);
    }
}
int main() {
    int i, j;
    freopen("i1.in", "r", stdin);
    freopen("i1.out", "w", stdout);
    int TE;
    scanf("%d", &TE);
    for(int CA = 1; CA <= TE; CA++) {
        scanf("%d", &n);
        for(i = 1; i <= n; i++) g[i].clear();
        for(i = 2;  i <= n; i++) {
            scanf("%d", &j);
            g[j].PB(i);
        }
        ans = 0;
        dfs(1, 0);
        printf("%d\n", ans);
    }
    
    return 0;
}
