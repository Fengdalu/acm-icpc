#include <bits/stdc++.h>
using namespace std;

int n, k;
double l, v1, v2;

bool check(double limit) {
    double cc = 0;
    double tot = 0;
    for(int i = 0; i < n; i += k) {
        if(i + k >= n) {
            return tot + (l - cc) / v2 <= limit;
        }
        double tt = (limit - tot);
        double dis = (l - cc);
        double t = (dis - tt * v1) / (v2 - v1);
        tot += t;
        double off = cc + t * v2;
        cc += t * v1;
        t = (off - cc) / (v1 + v2);
        tot += t;
        cc += t * v1;
    }
    return -1;
}

int main() {
    cin >> n >> l >> v1 >> v2 >> k;
    double cc = 0;
    double tot = 0;
    double ll = 0, rr = l / v1;
    for(int i = 0; i < 100; i++) {
        double mid = (ll + rr) / 2.0;
        if(check(mid)) rr = mid;
        else ll = mid;
    }
    printf("%.10f", ll);
    return 0;
}
