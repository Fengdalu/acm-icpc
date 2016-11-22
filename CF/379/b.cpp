#include <bits/stdc++.h>

typedef long long LL;
int main() {
    int k2, k3, k5, k6;
    scanf("%d%d%d%d", &k2, &k3, &k5, &k6);
    LL sum = 0;
    for(int i = 0; i <= std::min(k2, k3); i++) {
        LL t = 1ll * i * 32;
        t += 256ll * std::min(std::min(k5, k6), k2 - i);
        sum = std::max(sum, t);
    }
    printf("%I64d\n", sum);
    return 0;
}
