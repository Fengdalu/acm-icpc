#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
const long long mod = 1000000007;
const int maxd = 17;

int dp[maxd][2001];

void add(int &a, int b) {
    a = (a + b) % mod;
}

int mul(long long a, long long b) {
    return (a * b) % mod;
}

int cal(int h, int x) {
    if(h == 0 && x == 0) return 1;
    if(h > x) return 0;
    if((1 << h) < x) return 0;
    if(h <= 0 || x <= 0) return 0;
    if(dp[h][x] != -1) return dp[h][x];
    dp[h][x] = 0;
    for(int i = 0; i < x; i++)  {
        add(dp[h][x], mul(cal(h - 1, i), cal(h - 1, x - i - 1)));
        add(dp[h][x], mul(cal(h - 2, i), cal(h - 1, x - i - 1)));
        add(dp[h][x], mul(cal(h - 1, i), cal(h - 2, x - i - 1)));
    }
    return dp[h][x];
}

int main() {
    int n;
    memset(dp, -1, sizeof dp);
    cin >> n;
    int tot = 0;
    for(int i = 1; i < maxd; i++)  add(tot, cal(i, n));
    cout << tot << endl;
}
