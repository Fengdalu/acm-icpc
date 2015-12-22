#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define LL long long

int main() {
    LL n, p;
    scanf("%I64d%I64d", &n, &p);
    LL ans = 1;
    while(n) {
        ans *= n;
        ans %= p;
        n--;
    }
    printf("%I64d\n", ans);
    return 0;
}
