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
char gao[3000][1111] = {0};

int main() {
    int i, j, k, x, n;
    int ay = 1500, iy = 1500;
    int ax = 0, ix = 10001;
    int px = 0, py = 1500;
    int o = 1;
    //freopen("", "r", stdin);
//    freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &x);
        int u = px + x, v = py + o * x;
        o *= -1;
        cmax(ax, u);
        cmax(ay, v);
        cmin(iy, v);
        for(j = 1; j <= x; j++) {
            if(v > py) gao[++py][px++] = '/';//, cout << px << "-" << py << " " << "/" << endl;
            else gao[py--][px++] = '\\';//, cout << px << "~" << py << " " << "\\" << endl ;
        }
        px = u; py = v;
    }
    for(i = ay; i > iy; i--) {
//        for(k = ax; k > 0; k--) if(gao[i][k] != 0) break;
        for(j = 0; j < ax; j++) {
            if(gao[i][j] == 0) printf(" ");
            else printf("%c", gao[i][j]);
        }
        printf("\n");
    }
    return 0;
}
