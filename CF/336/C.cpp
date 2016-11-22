#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define LL long long
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)

PII s[100010];
int dp[100010];
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i].AA >> s[i].BB;
    sort(s, s + n);
    int ans = n;
    for(int i = 0; i < n; i++) {
        int p = lower_bound(s, s + n, PII(s[i].AA - s[i].BB, -1)) - s;
        if(p) dp[i] = dp[p - 1] + i - p;
        else dp[i] = i;
        ans = min(ans, dp[i] + n - i - 1);
    }
    cout << ans << endl;
    return 0;
}
