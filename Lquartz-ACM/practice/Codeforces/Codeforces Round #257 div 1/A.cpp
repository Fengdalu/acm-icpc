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
const LL MOD = (1LL << 60);
LL n, m, k, ans;

LL gao(LL x) {
    LL y = k - x;
    if(y >= m) return -1;
    x++; y++;
    LL nn = n / x;
    LL mm = m / y;
//    cout << nn << " ~ " << mm << endl;
    return nn * mm;
}

LL gao1(LL x) {
    LL cut = n / x;
    cut--;
    if(cut > k) return 0;
    LL y = 0;
    y = m / (k - cut + 1);
//    cout << x << " ~ " << y << endl;
    return x * y;
}

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(cin >> n >> m >> k) {
        if(n + m - 2 < k) {
            ans = -1;
        }
        else {
            ans = 1;
            for(LL i = 0; i * i <= k; i++) {
                if(i >= n) break;
                cmax(ans, gao(i));
                swap(n, m);
                cmax(ans, gao(i));
                swap(n, m);
            }
            for(LL i = 1; i * i <= n; i++) {
                if(i > k) break;
                cmax(ans, gao1(i));
            }
            swap(n, m);
            for(LL i = 1; i * i <= n; i++) {
                if(i > k) break;
                cmax(ans, gao1(i));
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
3 4 1
6 4 2
2 3 4
10 10 2

1000000000 1000000000 1000000000
482738478 493948384 502919283
1000000000 1000000000 1


*/
