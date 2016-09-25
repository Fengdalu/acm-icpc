#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 111
int A[Maxn], B[Maxn], AA[Maxn], BB[Maxn], g[Maxn];
int dp[Maxn][Maxn];
int n;
int dg(int n, int A[], int B[]) {
    int i, j;
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(A[i] == B[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp[n][n];
}
int doit(int n, int A[], int B[]) {
    int i, j;
    int cnt = 0;
    for(i = 1, j = 1; i <= n; i++) {
        if(A[i] == B[j]) {
            cnt++;
            continue;
        }
        AA[j] = A[i]; BB[j] = B[i];
        j++;
    }
    //printf("cnt %d dp %d\n", cnt, dg(j - 1, AA, BB));
    return cnt + dg(j - 1, AA, BB);
}
int main() {
    int i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &g[i]);
        A[g[i]] = i;
    }
    while(scanf("%d", &g[1]) != EOF) {
        B[g[1]] = 1;
        for(i = 2; i <= n; i++) {
            scanf("%d", &g[i]);
            B[g[i]] = i;
        }
        printf("%d\n", dg(n, A, B));
    }
    return 0;
}
