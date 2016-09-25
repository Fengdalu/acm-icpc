//#pragma comment(linker,"/STACK:102400000,102400000")​

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
typedef pair<long, long> PLL;

#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
#define SORT(g) sort(g.BG, g.ED)
#define MEM(a,b) memset(a,b,sizeof(a))
#define REVERSE(g) reverse(g.BG,g.ED)
#define REVERSE(g,l,r) reverse(g, g.BG + i, g.ED + i)
#define SBUSTR(S,l,r) S.substr(l, (r)-(l))

typedef vector<int> VI;
typedef vector<PII> VII;
typedef deque<int> QI;
typedef deque<PII> QII;
typedef vector<LL> VL;
typedef vector<PLL> VLL;
typedef deque<LL> QL;
typedef deque<PLL> QLL;
typedef vector<string> VS;
typedef deque<string> QS;

const double eps = 1e-8;
const LL MOD = 1000000007;
int n, v;
int g[4000];

int main() {
    int i, j, a, b;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    cin >>  n >> v;
    MEM(g, 0);
    int dmax = 0;
    for(i = 0; i < n; i++) {
        cin >> a >> b;
        g[a] += b;
        cmax(dmax, a);
    }
    int ans = 0, pre = 0;
    for(i = 1; i <= dmax + 1; i++) {
        int ok = g[i - 1] + g[i];
        if(ok <= v) {
            g[i] = 0;
            ans += ok;
        }
        else {
            ans += v;
            cmin(g[i], g[i] + g[i - 1] - v);
        }
    }
    cout << ans << endl;
    return 0;
}
