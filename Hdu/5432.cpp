#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 10010

double a[N], h[N];
int n;

int calc(int H)
{
    double up = 0, down = 0;
    for(int i = 0; i < n; i++)
    {
        if(H >= h[i]) down += a[i] * a[i] * h[i];
        else
        {
            double l = h[i] - H;
            double t = a[i] * a[i] * h[i];
            double u = a[i] * a[i] * l * l * l / h[i] / h[i];
            up += u;
            down += t - u;
        }
    }
    if(up > down) return 1;
    return 0;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%lf", &h[i]);
        for(int i = 0; i < n; i++) scanf("%lf", &a[i]);
        double l = 0, r = 0;
        for(int i = 0; i < n; i++) r = max(r, h[i]);
        while(r - l >= 1.0)
        {
            double mid = (l + r) / 2.0;
            if(calc(mid)) l = mid;
            else r = mid;
        }
        l -= 0.5; l = max(0.0, l);
        printf("%.0f\n", l);
    }
    return 0;
}
