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
const LL MOD = 1000000009;
int n, K, m;
char s1[200], s2[200];
LL dp[111][111];
LL c[111][111];

void pre() {
    c[0][0] = 1;
    c[1][0] = 1; c[1][1] = 1;
    for(int i = 2; i <= 100; i++) {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    int i, j, k;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    pre();
    while(scanf("%d%d%d", &n, &K, &m) != EOF) {
        scanf("%s%s", s1, s2);
        int step = K * m;
        int diff = 0;
        for(i = 0; i < n; i++) {
            if(s1[i] != s2[i]) diff++;
        }
        int same = n - diff;
        for(i = 0; i <= K; i++) 
            for(j = 0; j <= n; j++) 
                dp[i][j] = 0;
        dp[0][diff] = 1;
        for(i = 1; i <= K; i++) {
            for(j = 0; j <= n; j++) {
                for(k = 0; k <= m; k++) {
                    if(k > j) break;
                    int jian = k, jia = m - k;
                    if(jia > n - j) continue;
//                    cout << "~" << i << " " << j << " " << k << endl;
                    dp[i][j - jian + jia] = 
                    (dp[i][j - jian + jia] + (c[j][jian] * dp[i - 1][j]) % MOD * c[n - j][jia]) % MOD;
                }
            }
        }
        cout << dp[K][0] << endl;
    }
    
    return 0;
}
/*
1 1 1
1
0
5 2 2
11111
00000
*/
