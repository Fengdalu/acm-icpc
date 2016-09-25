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
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 111
#define Maxm 111111
int f[111][111];
int n;
char str[100];
int calc(char str[]) {
    int ret = 0;
    for(int i = 0; str[i]; i++) ret = ret * 10 + str[i] - '0';
    return ret;
}
int main() {
    int i, j, k, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &n);
    for(i = 1; i <= n; i++) f[i][i] = 0;
    for(i = 2; i <= n; i++) {
        for(j = 1; j < i; j++) {
            scanf("%s", str);
            if(str[0] == 'x') f[i][j] = f[j][i] = MOD;
            else f[i][j] = f[j][i] = calc(str);
        }
    }
    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                cmin(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for(i = 2; i <= n; i++) cmax(f[1][1], f[1][i]);
    printf("%d\n", f[1][1]);
    return 0;
}

