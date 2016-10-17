#include <bits/stdc++.h>

int a[1000];
int n;
int main() {
    int k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    int tot = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] + a[i + 1] < k) {
            tot += k - a[i] - a[i + 1];
            a[i + 1] += k - a[i] - a[i + 1];
        }
    }
    printf("%d\n", tot);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
