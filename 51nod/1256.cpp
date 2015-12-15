#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int ans = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return ans;
}

int inv(int x, int MOD) {
    int k, p;
    exgcd(x, MOD, k, p);
    k %= MOD;
    k += MOD;
    k %= MOD;
    return k;
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", inv(m, n));
    return 0;
}
