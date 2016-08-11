#include <bits/stdc++.h>
using namespace std;

inline double sqr(double x) { return x * x; }
int main() {
    double ans = -1.0;
    int n; double x, y;
    scanf("%lf%lf%d", &x, &y, &n);
    for(int i = 0; i < n; i++) {
        double a, b, v; scanf("%lf%lf%lf", &a, &b, &v);
        double dis = sqrt(sqr(a - x) + sqr(b - y)) / v;
        if(ans < 0 || dis < ans) ans = dis;
    }
    printf("%.15f", ans);
    return 0;
}
