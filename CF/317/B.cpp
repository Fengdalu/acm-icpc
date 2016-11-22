#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define N 5010
#define LL long long

LL dp[N][N];
LL a[300010];
int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    sort(a + 1, a + n + 1);

    int LA = n / k + 1;
    int LB = n / k;
    int A = n - k * LB;
    int B = k - A;
    for(int i = 0; i <= A; i++) for(int j = 0; j <= B; j++)
    {
        if(i == 0 && j == 0) continue;
        if(i == 0) dp[i][j] = dp[i][j - 1] + a[i * LA + j * LB] - a[i * LA + (j - 1) * LB + 1];
        else if(j == 0) dp[i][j] = dp[i - 1][j] + a[i * LA + j * LB] - a[(i - 1) * LA + j * LB + 1];
        else dp[i][j] = min(dp[i][j - 1] + a[i * LA + j * LB] - a[i * LA + (j - 1) * LB + 1],
                            dp[i - 1][j] + a[i * LA + j * LB] - a[(i - 1) * LA + j * LB + 1]
                            );
    }
    printf("%I64d\n", dp[A][B]);
    return 0;
}