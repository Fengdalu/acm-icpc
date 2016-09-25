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
VI ans;
int main() {
    int i, j, k, x;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d%d", &n, &v);
    ans.clear();
    for(i = 1; i <= n; i++) {
        int flag = 0;
        scanf("%d", &k);
        for(j = 0; j < k; j++) {
            scanf("%d", &x);
            if(v > x) flag = 1;
        }
        if(flag) {
            ans.PB(i);
        }
    }
    printf("%d\n", ans.SZ);
    for(i = 0; i < ans.SZ; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
