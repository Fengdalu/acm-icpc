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
typedef pair<LL, int> PLI;
LL org, e[30], ans;
char in[30];
int k, len;

void gao(int h) {
//    cout << "h: " << h << " " << org << " " << k << endl;
    LL o = org;
    LL dmax = o;
    int p = -1;
    int step = 0;
    for(int i = 2; i <= len; i++) {
        int he = max(1, i - k);
        LL t = org;
        int c = 0;
        for(int j = i - 1; j >= he; j--) {
            int ii = ( t % e[j - 1] ) / e[j];
            int jj = ( t % e[j] ) / e[j + 1];
            LL tt = t - ii * e[j] - jj * e[ j + 1] + ii * e[j + 1] + jj * e[j];
            if(tt > t) {
                c++;
                t = tt;
            }
            else break;
        }
//        cout << o << " " << he << " " << i << " " << t << endl;
        if(dmax < t) {
            dmax = t;
            p = i;
            step = c;
        }
    }
    if(p == -1) {
        k = 0;
    }
    else {
//        cout << "dmax: " << dmax << " " << step << endl;
        k -= step;
        org = dmax;
        cmax(ans, org);
    }
}

int main() {
    int i, j;
//    freopen("input.txt", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%s%d", in, &k);
    len = strlen(in);
    e[len] = 1;
    for(i = len - 1; i >= 0; i--) {
        e[i] = e[i + 1] * 10;
    }
    org = 0;
    for(i = 1; i <= len; i++) org = org * 10 + in[i-1] - '0';
    ans = org;
    for(int step = 1; k > 0; step++) {
        gao(step);
    }
    printf("%I64d\n", ans);
    return 0;
}
