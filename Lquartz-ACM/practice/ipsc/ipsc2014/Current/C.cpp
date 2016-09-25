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
#define N 111111
int n, dmax;
int a[N];
bool used[N];
int ans[N];
int main() {
    int i, j, k;
    freopen("c1.in", "r", stdin);
    freopen("c1.out", "w", stdout);
    int TE;
    scanf("%d", &TE);
    dmax = 0;
    for(int CA = 1; CA <= TE; CA++) {
        scanf("%d", &n);
        dmax = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cmax(dmax, a[i]);
            used[i] = 0;
        }
        for(k = 1, i = 1; k <= dmax && i <= n; i++) {
            if(used[a[i]] == 0) {
                ans[k++] = a[i];
                used[a[i]] = 1;
            }
        }
        for(i = 1; i <= dmax; i++) {
            if(i > 1) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
