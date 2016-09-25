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
int n;
int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        for(i = -(n / 2); i <= (n / 2); i++) {
            for(j = 0; j < abs(i); j++) printf("*");
            for(j = 0; j < 2 * (n / 2 - abs(i)) + 1; j++) printf("D");
            for(j = 0; j < abs(i); j++) printf("*");
            printf("\n");
        }
    }
    return 0;
}
