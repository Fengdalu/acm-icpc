#include <bits/stdc++.h>


using namespace std;
typedef long long LL;

LL dp[6000];
char s[6000];

int main() {
    while(~scanf("%s", s + 1)) {
        if(!strcmp(s + 1, "0")) break;
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        dp[1] = 1;
        int len = strlen(s + 1);
        for(int i = 2; i <= len; i++) {
            int a = (s[i - 1] - '0'), b = s[i] - '0';
            if(a != 0 && a * 10 + b <= 26) dp[i] += dp[i - 2];
            if(b != 0) dp[i] += dp[i - 1];
        }
        printf("%I64d\n", dp[len]);
    }
    return 0;
}
