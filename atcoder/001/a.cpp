#include <bits/stdc++.h>
using namespace std;

int a[5000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n + n);
    reverse(a, a + n + n);
    int ans = 0;
    for(int i = 0; i < n * 2; i += 2) {
        ans += min(a[i], a[i + 1]);
    }
    printf("%d\n", ans);
    return 0;
}

