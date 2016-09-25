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
#define LEN 405
int n, m;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int cnt[8][LEN][LEN];
char g[LEN][LEN];

int get(int x, int y, int u, int v, int k) {
    int kk = (k + 4) % 8;
    if(k < 4) {
        return cnt[k][u][v] - cnt[k][x + dx[kk]][y + dy[kk]];
    }
    else {
        int k1 = k % 4;
        return cnt[k1][x][y] - cnt[k1][u + dx[k]][v + dy[k]];
    }
}

int main() {
    int i, j, k, l;
    int x, y, u, v;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    for(i = 0; i < LEN; i++) {
        for(j = 0; j < LEN; j++) {
            g[i][j] = '0';
        }
    }
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 1; i <= n; i++) {
            scanf("%s", g[i] + 1);
        }
        for(i = 0; i <= n + 1; i++) {
            for(j = 0; j <= m + 1; j++) {
                for(k = 0; k < 8; k++) {
                    cnt[k][i][j] = 0;
                }
            }
        }
        for(k = 2; k <= 3; k++) {
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= m; j++) {
                    int o = 0;
                    if(g[i][j] == '1') o = 1;
                    x = i + dx[(k + 4) % 8];
                    y = j + dy[(k + 4) % 8];
                    cnt[k][i][j] = cnt[k][x][y] + o;
                }
            }
        }
        for(k = 0; k <= 1; k++) {
            for(i = n; i >= 1; i--) {
                for(j = 1; j <= m; j++) {
                    int o = 0;
                    if(g[i][j] == '1') o = 1;
                    x = i + dx[(k + 4) % 8];
                    y = j + dy[(k + 4) % 8];
                    cnt[k][i][j] = cnt[k][x][y] + o;
                }
            }
        }
        int ans = 0;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                for(k = 0; k < 8; k++) {
                    int k1 = (k + 2) % 8, k2 = (k + 3) % 8;
                    for(l = 1; ; l++) {
//                        cout << i << " " << j << " " << k << " " << l << endl;
                        x = i + dx[k] * l; y = j + dy[k] * l;
                        if(x < 1 || x > n || y < 1 || y > m) break;
                        u = i + dx[k1] * l; v = j + dy[k1] * l;
                        if(u < 1 || u > n || v < 1 || v > m) break;
                        int d1 = get(i, j, x, y, k);
                        int d2 = get(i, j, u, v, k1);
                        int d3 = get(x, y, u, v, k2);
                        if(d1 > 0 || d2 > 0) break;
                        if(d3 > 0) continue;
//                        cout << "++++ " << i << " " << j << " " << k << " " << l << endl;
//                        cout << "---- " << d1 << " " << d2 << " " << d3 << endl;
                        ans++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
