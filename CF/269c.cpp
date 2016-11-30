// 3 * (n + 1) * n / 2 - n

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL f(LL n) {
    return 3 * (n + 1) * n / 2 - n;
}

int main() {
    LL n;
    int ans = 0;
    scanf("%lld", &n);
    for(int i = 1; i < 1000000; i++) 
        if(n >= f(i) && (n - f(i)) % 3 == 0) ans++;
    printf("%d\n", ans);
    return 0;
}