#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define Maxn 1000111
#define Maxm 111
#define PB push_back
int value[Maxm];
int dp[Maxn], pre[Maxn];
vector<int> ans;
int n, m;

int main() {
    int i, j, k, u, v, w;
    while(scanf("%d", &n) != EOF) {
        scanf("%d", &m);
        for(i = 0; i < m; i++) scanf("%d", &value[i]);
        for(i = 0; i <= n; i++) dp[i] = 0, pre[i] = -1;
        dp[0] = 1;
        for(i = 0; i < m; i++) {
            for(j = n; j >= value[i]; j--) {
                if(dp[j]) continue;
                if(dp[j - value[i]]) {
                    dp[j] = 1;
                    pre[j] = j - value[i];
                }
            }
        }
        //for(i = 0; i < n; i++) printf("%3d", dp[i]); puts("");
        //for(i = 0; i < n; i++) printf("%3d", pre[i]); puts("");
        int sum = 0;
        for(i = n; i >= 0; i--) {
            if(dp[i]) {
                sum = i;
                ans.clear();
                j = i;
                while(j != 0) {
                    ans.PB(j - pre[j]);
                    j = pre[j];
                }
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        for(i = 0; i < ans.size(); i++) {
            printf("%d ", ans[i]);
        }
        printf("sum:%d\n", sum);
    }
    return 0;
}
