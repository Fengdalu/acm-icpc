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
char p[100], q[100], ans[200];
int main() {
    int i, j, k;
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);
    int Test;
    cin >> Test;
    for(int Ca = 1; Ca <= Test; Ca++) {
        cin >> p >> q;
        int lp = strlen(p);
        int lq = strlen(q);
        i = lq;
        for(i = 0; i < lp; i++) {
            if(i == lp) break;
            if(p[i] != q[i]) break;
        }
        for(k = 0, j = i; j < lq; j++, k++) {
            ans[k] = '<';
        }
        for(j = i; j < lp; j++, k++) {
            ans[k] = p[j];
        }
        ans[k++] = '*';
        ans[k++] = '\0';
        if(strlen(ans) > lp + 2) {
            k = 0;
            ans[k++] = '*';
            for(i = 0; i < lp; i++, k++) ans[k] = p[i];
            ans[k++] = '*';
            ans[k++] = '\0';
        }
        cout << ans << endl;
    }
    return 0;
}

