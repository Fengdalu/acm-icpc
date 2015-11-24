#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL long long

LL ans;
LL n;

LL qpow(LL x, LL y) {
    if(y == 0) return 1;
    if(y & 1) return x * qpow(x * x, y >> 1);
    return qpow(x * x, y >> 1);
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%I64d", &n);
        ans = (1 + n) * n / 2;
        LL k = log2(n);
        ans -= qpow(2, k + 1) - 1;
        ans -= qpow(2, k + 1) - 1;
        printf("%I64d\n", ans);
    }
}
