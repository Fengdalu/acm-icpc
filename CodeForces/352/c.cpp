#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1000000;
double x[maxn], y[maxn];
double sqr(double x) { return x * x; }
double dis(double a, double b, double x, double y) {
    return sqrt(sqr(a - x) + sqr(b - y));
}
pair<double, int> f[maxn], g[maxn];
int main() {
    double ax, ay, bx, by, tx, ty;
    scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &tx, &ty);
    double tot = 0;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    if(n == 1) {
        double ans = min(dis(ax, ay, x[0], y[0]), dis(bx, by, x[0], y[0])) + dis(x[0], y[0], tx, ty);
        printf("%.16f", ans);
        return 0;
    }
    for(int i = 0; i < n; i++)
        tot += 2.0 * dis(tx, ty, x[i], y[i]);
    for(int i = 0; i < n; i++) f[i] = make_pair(dis(x[i], y[i], ax, ay) - dis(x[i], y[i], tx, ty), i);
    for(int i = 0; i < n; i++) g[i] = make_pair(dis(x[i], y[i], bx, by) - dis(x[i], y[i], tx, ty), i);
    double add = 1e20;;
    sort(f, f + n);
    sort(g, g + n);
    for(int i = 0; i < min(n, 3); i++)
        for(int j = 0; j < min(n, 3); j++)
        if(f[i].second != g[j].second) {
            add = min(add, f[i].first + g[j].first);
        }
    add = min(f[0].first, add);
    add = min(g[0].first, add);
    printf("%.16f", tot + add);
    return 0;
}
