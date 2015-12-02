#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL long long

double s, m, p;

bool chk(double x) {
    double sum = s;
    for(int i = 0; i < m; i++) {
        double a = sum * p / 100.0;
        double b = max(0.0, x - a);
        sum -= b;
        if(sum <= 0) return true;
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%lf%lf%lf", &s, &m, &p);
    double l = 0, r = 1e9;
    while(fabs(r - l) >= 1e-7) {
        double mid = (l + r) / 2.0;
        if(chk(mid)) r = mid; else l = mid;
    }
    printf("%.10f\n", l);
    fclose(stdout);
    return 0;
}
