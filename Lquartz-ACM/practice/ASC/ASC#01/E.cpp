#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 500 000
#define M 101000
int n, m, p;
int g[20];
int dp[2][20];

int main() {
    int i, j, k, l;
    int T;
    scanf("%d", & T);
    for(int Ca = 1; Ca <= T; Ca++) {
        scanf("%d%d%d", &n, &m, &p);
        for(i = 0; i < (1<<m); i++) dp[0][i] = 1;
        cout << 1 << " " << (1<<m) << endl;
        int u = 1, v = 0;
        for(i = 2; i <= n; i++) {
            u ^= 1; v ^= 1;
            int sum = 0;
            for(j = 0; j < (1<<m); j++) {
                dp[v][j] = 0;
                for(k = 0; k < (1<<m); k++) {
                    for(l = 0; l < m - 1; l++) {
                        int gao = (3 << l);
                        if((j & gao) == gao && (k & gao) == gao) break;
                        if((j & gao) == 0 && (k & gao) == 0) break;
                        
                    }
                    if(l == m - 1) dp[v][j] = (dp[v][j] + dp[u][k]) % p;
                }
                sum += dp[v][j];
            }
            cout << i <<" " << sum % p<< endl;
        }
//        if(Ca > 1) cout << endl;
//        cout << ans <<endl;
    }
}
