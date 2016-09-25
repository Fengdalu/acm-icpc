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

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int n, m, x, ans, now;
    scanf("%d%d", &n, &m);
    ans = 0;
    now = 0;
    while(n--) {
        scanf("%d", &x);
        if(now + x > m) {
            now = x;
            ans++;
        }
        else now += x;
    }
    if(now) ans++;
    printf("%d\n", ans);
    return 0;
}
