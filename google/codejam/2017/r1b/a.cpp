#include <bits/stdc++.h>

using namespace std;

double s[50000], a[50000];
pair<double, double> tmp[50000];
void run() {
    double d;
    int n;
    scanf("%lf%d", &d, &n);
    for(int i = 0; i < n; i++) {
        //scanf("%lf%lf", a + i, s + i);
        scanf("%lf%lf", &tmp[i].first, &tmp[i].second);
        //a[i] = d - a[i];
    }
    sort(tmp, tmp + n);
    for(int i = 0; i < n; i++) {
        a[i] = tmp[i].first;
        s[i] = tmp[i].second;
    }

    double v;
    double t = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || v > s[i]) {
            double ds = a[i];
            double dt = (d - a[i]) / s[i];
            if(i != 0 && (v - s[i]) * dt <= ds) continue;
            v = ds / dt + s[i];
            t = dt;
            // printf("%f %f %d\n", v, t, i);
        }
    }
    /*
      (d - a0) = (v - s0) * (a0 / s0)
      v = (d - a0) / (a0 - s0)
    */
    printf("%.6f\n", v);
}

int main() {
    //freopen("a.txt.in", "r", stdin);
    //freopen("a.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int ii = 1; ii <= T; ii++) {
        printf("Case #%d: ", ii);
        run();
    }
    return 0;
}
