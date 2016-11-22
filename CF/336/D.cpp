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
#define cmin(x, y) x = min(x, y)


int dp[510][510];
int a[510];
int n;

int cal(int l, int r) {
    if(l >= r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 10000000;
    if(a[l] == a[r]) cmin(dp[l][r], cal(l + 1, r - 1));
    for(int i = l; i <= r; i++)
        cmin(dp[l][r], cal(l, i) + cal(i + 1, r));
    return dp[l][r];}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << cal(0, n - 1);
    return 0;
}

