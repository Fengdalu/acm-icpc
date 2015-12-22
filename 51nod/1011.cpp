#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define LL long long

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}
