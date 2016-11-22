#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long

int w;
int n;
int c[200010];
double p;

int main()
{
    scanf("%d %d", &n, &w);
    for(int i = 0; i < 2 * n; i++) scanf("%d", &c[i]);
    sort(c, c + 2 * n);
    p = -1;
    for(int i = 0; i < n; i++)
    {
        double tmp = min(c[n + i] / 2.0, (double)c[i]);
        p = (p < 0.0) ? tmp : min(p, tmp);
    }

    printf("%.2f\n", min((double)w, 3.0 * p * (double)n));
    return 0;
}
