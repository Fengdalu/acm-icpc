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
int a[111111];
int n;

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        for(i = 0; i < n; i++) scanf("%d", &a[i]);
        for(i = 1; i <n; i++) if(a[i] < a[i - 1]) break;
        int flag = true;
        if(i < n) {
            for(j = i + 1; j < n; j++) if(a[j] < a[j - 1]) break;
            if(j == n && a[0] >= a[n - 1]) {
                flag = true;
            }
            else {
                flag = false;
            }
        }
        if(flag) printf("%d\n", n - i);
        else printf("-1\n");
    }
    return 0;
}
