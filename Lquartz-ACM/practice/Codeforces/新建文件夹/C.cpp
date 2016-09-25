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
long double gao[111111];
long double a;

long double calc(int n) {
    if(n == 0) return 1.0;
    else if( n == 1) return a;
    long double tp = calc(n / 2);
    tp *= tp;
    if(n & 1) tp *= a;
    return tp;
}

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(cin >> m >> n) {
        gao[0] = 0;
        for(i = 1; i <= m; i++) gao[i] = 1;
        for(j = 1; j <= m; j++) {
            a = 1.0 * j / m;
            gao[j] = calc(n);
        }
        double ans = 0;
        for(i = m; i > 1; i--) gao[i] -= gao[i - 1];
//        for(i = 1; i <= m; i++) cout << i <<" "<< gao[i]<< endl;
        for(i = 1; i <= m; i++) ans += gao[i] * i;
        cout << ans << endl;
    }
    return 0;
}
