#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MP make_pair
typedef pair<double, double> P;
P p[100100];

double u, v, w;
int cmp(P a, P b) {
    double ba = a.Y - a.X * u / v, bb = b.Y - b.X * u / v;
    return ba < bb;
}
int main() {
    int n;
    scanf("%d%lf%lf%lf", &n, &w, &v, &u);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].X, &p[i].Y);
    }
    sort(p, p + n, cmp);
    P q = p[0];
    double b = q.Y - q.X * u / v;
    double x = -b * v / u;
    x = max(x, 0.0);
    double ans = x / v + w / u;
    q = p[n - 1];
    b = q.Y - q.X * u / v;
    if(b <= 0) ans = min(ans, w / u);
    x = -b * v / u;
    if(x >= 0) ans = min(ans, x / v + w / u);
    printf("%.16f", ans);
    return 0;
}
