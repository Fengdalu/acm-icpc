#include <cstdio>
#include <cstring>
using namespace std;
#define Maxn 10000
typedef long long LL;
LL dp[Maxn];
int co[10] = {1, 5, 10, 25, 50};

int main() {
    int i, j, u, v, w;
    int n = 7489;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(j = 0; j < 5; j++) {
        for(i = 1; i <= n; i++) {
            if(i < co[j]) continue;
            dp[i] += dp[i - co[j]];
        }
    }
    //for(i = 1; i <= n; i++) printf("%d %lld\n", i, dp[i]);
    while(scanf("%d", &n) != EOF) {
        printf("%lld\n", dp[n]);
    }
    return 0;
}

