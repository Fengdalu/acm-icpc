#include <bits/stdc++.h>

const int N = 4 * 1e5;
double c[N], x[N];
int main() {
    int n, m;
    double r;
    scanf("%d%d%lf", &m, &n, &r);
    for(int i = 0; i < m; i++) scanf("%lf", c + i);
    for(int i = 0; i < n; i++) scanf("%lf", x + i);
    int cur = 0;
    double tot = 0;
    for(int i = 0; i < n; i++) {
        double lx = x[i] - sqrt(r * r - 1);
        double rx = x[i] + sqrt(r * r - 1);
        int l = std::lower_bound(c, c + m, lx) - c;
        int r = std::upper_bound(c, c + m, rx) - c;
        r--;
        if(l <= cur && cur <= r) continue;
        if(cur < l) {
            tot += c[l] - c[cur];
            cur = l;
        }
        else {
            tot += c[cur] - c[r];
            cur = r;
        }
    }
    printf("%.10f\n", tot);
    return 0;
}

