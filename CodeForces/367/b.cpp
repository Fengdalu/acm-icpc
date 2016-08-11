#include <bits/stdc++.h>
using namespace std;

int a[1000100];
int b[1000100];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
    a[n++] = 1e9 + 1;
    sort(a, a + n);
    for(int i = 0; i < m; i++) {
        int p = upper_bound(a, a + n, b[i]) - a;
        printf("%d\n", p);
    }
    return 0;
}
