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
int n, m;
int cost[1111], has[1111], sum[1111], all[1111];
vector <int> g[1111];
priority_queue <pair<int, PII> > Q;

int main() {
    int i, j, x, y;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(cin >> n >> m) {
        for(i = 1; i <= n; i++) {
            cin >> cost[i];
            has[i] = 0; sum[i] = 0; all[i] = 0;
            g[i].clear();
        }
        for(i = 0; i < m; i++) {
            cin >> x >> y;
            g[x].PB(y); g[y].PB(x);
            sum[x] += cost[y]; sum[y] += cost[x];
            all[x] += cost[x]; all[y] += cost[y];
        }
        while(!Q.empty()) Q.pop();
        for(i = 1; i <= n; i++) {
            Q.push(MP(cost[i], MP(-sum[i], i)));
        }
        int ans = 0;
        while(!Q.empty()) {
            y = Q.top().BB.BB;
            x = sum[y];
            
            Q.pop();
            if(!has[y]) {
//                cout << "~ " << y << " " << x << endl;
                ans += x;
                for(i = 0; i < g[y].SZ; i++) {
                    j = g[y][i];
                    if(!has[j]) {
                        sum[j] -= cost[y];
                        all[j] -= cost[j];
                        Q.push(MP(cost[j], MP(-sum[j], j)));
                    }
                }
                has[y] = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
