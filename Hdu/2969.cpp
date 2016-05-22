#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
const int maxn = 10010;
int n, m;
double s[maxn];

bool check(double x) {
    int tot = 0;
    for(int i = 0; i < n; i++) {
        tot += int(s[i] / x);
    }
    return tot >= m;
}

int main() {
    int t; scanf("%d", &t);
    for(int ii = 0; ii < t; ii++) {
        scanf("%d%d", &n, &m); m++;
        double r = 0;
        for(int i = 0; i < n; i++)  {
            int x; scanf("%d", &x);
            s[i] = pi * x * x;
            r = max(r, s[i]);
        }
        double l = 0;
        while((r - l) > 1e-6)  {
            double mid = (l + r) / 2.0;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%.4f\n", r);
    }
    return 0;
}
