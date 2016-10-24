#include <bits/stdc++.h>

int main() {
    int ans = 0;
    for(int i = 1; i <= 100; i++) ans += i * i;
    printf("%d\n", (5050 * 5050) - ans);
    return 0;
}
