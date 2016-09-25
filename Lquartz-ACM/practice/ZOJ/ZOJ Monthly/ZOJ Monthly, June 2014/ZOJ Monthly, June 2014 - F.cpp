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
#define TT 11111
int b[TT], e[TT], ans[TT];

int calc(int o) {
    double lg = 1.0 * e[o] * log10(b[o]);
    int lgi = (int)lg;
    lg -= lgi;
    double ret = pow(10, lg);
    return (int) ret;
}

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int T;
    scanf("%d", &T);
    int cnt = 0;
    for(i = 1; i <= T; i++) {
        scanf("%d%d", &b[i], &e[i]);
        ans[i] = calc(i);
        if(cnt * 4 >= T) ans[i] = (ans[i] + 1) % 10;
        if(ans[i] == 0) ans[i] = 1;
        printf("%d\n", ans[i]);
        cnt++;
    }
    return 0;
}

