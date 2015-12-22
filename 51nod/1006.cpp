#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const int Maxn = 1010;
int dp[Maxn][Maxn];
int pre[Maxn][Maxn];
char a[Maxn], b[Maxn];

int main() {
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);
    memset(pre, -1, sizeof pre);
    int ii = 0, jj = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        if(dp[i - 1][j] > dp[i][j]) {
            dp[i][j] = dp[i - 1][j];
            pre[i][j] = 1;
        }
        if(dp[i][j - 1] > dp[i][j]) {
            dp[i][j] = dp[i][j - 1];
            pre[i][j] = 2;
        }
        if(a[i] == b[j])
        if(dp[i - 1][j - 1] + 1 > dp[i][j]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
            pre[i][j] = 3;
        }
        if(dp[i][j] > dp[ii][jj]) {
            ii = i;
            jj = j;
        }
    }
    string ans = "";
    while(pre[ii][jj] != -1) {
        if(pre[ii][jj] == 1) {
            ii--;
        }
        else if(pre[ii][jj] == 2) {
            jj--;
        }
        else if(pre[ii][jj] == 3) {
            ans.push_back(a[ii]);
            ii--; jj--;
        }
    }
    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
    return 0;
}
