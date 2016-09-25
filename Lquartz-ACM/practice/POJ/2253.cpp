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
#define Maxn 211
#define Maxm 111111
double f[Maxn][Maxn];
int visit[Maxn];
int n;
queue<int> Q;
bool check(double x) {
    int i, j;
    for(i = 1; i <= n; i++) visit[i] = false;
    visit[1] = true;
    while(!Q.empty()) Q.pop();
    Q.push(1);
    while(!Q.empty()) {
        i = Q.front(); Q.pop();
        for(j = 1; j <= n; j++) {
            if(!visit[j] && x - f[i][j] > eps) {
                visit[j] = true;
                if(j == 2) return true;
                Q.push(j);
            }
        }
    }
    return false;
}
int x[Maxn], y[Maxn];
int main() {
    int i, j, u, v, w, ca = 0;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF && n) {
        for(i = 1; i <= n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        for(i = 1; i <= n; i++) {
            for(j = i + 1; j <= n; j++) {
                f[i][j] = f[j][i] = sqrt(SQ(x[i] - x[j]) + SQ(y[i] - y[j]));
            }
        }
        double l = 0, r = 2100, mid;
        for(i = 0; i < 30; i++) {
            mid = (l + r) / 2;
            if(check(mid)) {
                r = mid;
            }
            else l = mid;
        }
        ca++;
        printf("Scenario #%d\n", ca);
        printf("Frog Distance = %.3f\n\n", (l + r) / 2);
    }
    return 0;
}

