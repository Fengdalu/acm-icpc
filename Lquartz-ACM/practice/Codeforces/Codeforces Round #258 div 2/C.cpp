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

LL t, n, k, d1, d2;

bool gao(LL a, LL b) {
    int i, j, l;
    LL A, B, C, t;
    for(i = 0; i < (1<<2); i++) {
        t = 0;
        if(i & 2) {
            t += a;
        }
        else {
            t -= a;
        }
        if(i & 1) {
            t += b;
        }
        else {
            t -= b;
        }
        if(k - t < 0 || (k - t) % 3 > 0) continue;
        B = (k - t) / 3;
        if(B > n / 3) continue;
        if(i & 2) {
            A = B + a;
        }
        else {
            A = B - a;
        }
        if( A < 0 || A > n / 3) continue;
        if(i & 1) {
            C = B + b;
        }
        else {
            C = B - b;
        }
        if(C < 0 || C > n / 3) continue;
        if(A + B + C == k) return true;
    }
    return false;
}

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    cin >> t;
    for(i = 1; i <= t; i++) {
        cin >> n >> k >> d1 >> d2;
        int flag = 0;
        if(n % 3 == 0) {
            flag = gao(d1, d2);
        }
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
