#include <bits/stdc++.h>

int mk[1<<20];
int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int t; scanf("%d", &t);
        ans += mk[t ^ x];
        mk[t]++;
    }
    printf("%I64d\n", ans);
    return 0;
}
