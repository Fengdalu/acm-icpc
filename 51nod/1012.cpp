#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define LL long long

LL gcd(LL a, LL b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int main() {
    LL a, b;
    scanf("%I64d%I64d", &a, &b);
    printf("%I64d\n", a / gcd(a, b) * b);
    return 0;
}
