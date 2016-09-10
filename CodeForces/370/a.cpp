#include <bits/stdc++.h>

typedef long long ll;
ll a[100010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%I64d", a + i);
    }
    for(int i = 1; i <= n; i++) {
        printf("%I64d ", a[i] + a[i + 1]);
    }
    return 0;
}
