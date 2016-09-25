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
vector<int> prime, prim;
int ispri[1000];
int n, m, a[111], b[111];
int dp[105][(1<<16) + 100], prev[105][(1<<16) + 100];
int mask[105];
int p, q;
queue<int> que[105];
set<int> S;
void pre() {
    int i, j;
    for(i = 0; i < 1000; i++) ispri[i] = 1;
    prim.clear();
    for(i = 2; i < 1000; i++) {
        if(ispri[i]) {
            prim.PB(i);
            for(j = 2 * i; j < 1000; j += i) {
                ispri[j] = 0;
            }
        }
    }
//    for(i = 0; i < 20; i++) cout << i <<" "<< prim[i] << endl;
}

void ready() {
    int i, j;
    S.clear();
    prime.clear();
    for(i = 0; i < 16; i++) prime.PB(prim[i]);
    m = prime.SZ;
    for(i = 1; i <= 60; i++) {
        mask[i] = 0;
        for(j = 0; j < m; j++) {
            if(i % prime[j] == 0) mask[i] |= 1 << j;
        }
    }
}

int main() {
    int i, j, x, y, z;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    pre();
    while(cin >> n) {
        for(i = 1; i <= n; i++) cin >> a[i];
        ready();
        p = 0; q = 1;
        dp[0][0] = 0;
        que[p].push(0);
        for(i = 1; i <= n; i++) {
            for(j = 0; j < (1 << m); j++) dp[i][j] = MOD;
            for(x = 0; x < (1<<16); x++) {
                if(dp[i - 1][x] == MOD) continue;
                for(j = 1; j < 59; j++) {
                    if(x & mask[j]) continue;
                    z = dp[i - 1][x] + abs(a[i] - j);
                    y = x | mask[j];
                    if(dp[i][y] > z) {
                        dp[i][y] = z;
                        prev[i][y] = j;
                    }
                }
            }
        }
        int ans = MOD;
        for(j = 0, p = 0; j < (1 << m); j++)
            if(ans > dp[n][j]) {
                ans = dp[n][j]; p = j;
            }
//        cout << ans << endl;
        for(i = n; i > 0; i--) {
            q = prev[i][p];
//            cout << "~ " << i << " " << p << " " << q << endl;
            b[i] = q;
            p -= mask[q];
        }
        for(i = 1; i <= n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
100
30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 
30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 30 

*/
