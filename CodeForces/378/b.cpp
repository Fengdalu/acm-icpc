#include <bits/stdc++.h>

const int N = 1e5+100;
int a[N], b[N];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", a + i, b + i);
    int L = std::accumulate(a, a + n, 0);
    int R = std::accumulate(b, b + n, 0);
    int ans = abs(L - R);
    int p = -1;
    for(int i = 0; i < n; i++) {
        int LL = L - a[i] + b[i];
        int RR = R - b[i] + a[i];
        if(abs(LL - RR) > ans) {
            ans = abs(LL - RR);
            p = i + 1;
        }
    }
    if(p == -1) printf("%d\n", 0);
    else printf("%d\n", p);
    return 0;
}
