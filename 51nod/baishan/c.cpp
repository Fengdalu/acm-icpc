#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);

double cal(double s, double r) {
    double l = (s - pi * r * r) / pi / r;
    return pi * r * r * sqrt(l * l - r * r) / 3.0;
}

int main() {
    double s;
    while(cin >> s) {
        double l = 1e-10, r = sqrt(s / pi);
        for(int i = 0; i < 1000; i++) {
            double mid = (l + r) / 2;
            double mmid = (l + mid) / 2;
            if(cal(s, mmid) < cal(s, mid)) l = mmid;
            else r = mid;
        }
        printf("%.8f\n", cal(s, l));
    }
    return 0;
}
