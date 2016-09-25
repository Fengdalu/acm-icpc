#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define Maxn 1111
char A[Maxn], B[Maxn];
int dp[Maxn][Maxn];
int main() {
    int i, j;
    int n, m;
    while(gets(A + 1) != NULL) {
        gets(B + 1);
        n = strlen(A + 1);
        m = strlen(B + 1);
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= m; j++) {
                dp[i][j] = 0;
            }
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(A[i] == B[j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
