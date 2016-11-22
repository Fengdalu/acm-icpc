#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<double, double> obj;
#define mp(x, y) make_pair(x, y)
int cnt;
obj f[200010];

const double eps = 1e-9;
const double pi = acos(-1.0);
double trans(double x) {
    return x / (2 * pi) * 360;
}
inline int sign(double x) {
    return x < -eps ? -1 : 1;
}

inline void insert(double l, double r) {
    if(l < 0 && r > 0) {
        f[cnt++] = mp(2 * pi + l, 2 * pi);
        f[cnt++] = mp(0, r);
    }
    else if(l < 2 * pi && r > 2 * pi) {
        f[cnt++] = mp(l, 2 * pi);
        f[cnt++] = mp(0, r - 2 * pi);
    }
    else {
        f[cnt++] = mp(l, r);
    }
}

int main() {
    double x, y, v, T;
    scanf("%lf%lf%lf%lf", &x, &y, &v, &T);
    int n;
    double d = 1.0 * v * T;
    scanf("%d", &n);
    bool flag = false;
    while(n--) {
        double a, b, r;
        scanf("%lf%lf%lf", &a, &b, &r);
        a -= x; b -= y;
        double alpha = atan2(b, a);
        if(alpha < 0) alpha += 2 * pi;
        double len = sqrt(a * a + b * b);
        double s = sqrt(a * a + b * b - r * r);
        if(r * r >= a * a + b * b) {
            flag = true;
        }
        else if(sign(d - s) >= 0) {
            double beta = atan2(r, s);
            insert(alpha - beta, alpha + beta);
        }
        else if(sign((r + d) - len) >= 0) {
            double beta = acos((len * len + d * d - r * r) / (2.0 * d * len));
            insert(alpha - beta, alpha + beta);
        }
    }
    sort(f, f + cnt);
    double cover = 0;
    double l = f[0].first, r = f[0].second;
    for(int i = 0; i < cnt; i++) {
        if(sign(r - f[i].first) > 0) {
            r = max(r, f[i].second);
        }
        else  {
            cover += (r - l);
            l = f[i].first;
            r = f[i].second;
        }
    }
    cover += (r - l);
    if(flag) puts("1");
    else printf("%.16f", cover / (2. * pi));
    return 0;
}
