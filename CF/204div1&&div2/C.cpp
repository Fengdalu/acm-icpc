#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 100010
#define PII pair<int, int>
#define PB(x) push_back(x)
#define INF 1e9
int main()
{
    int n; scanf("%d", &n);
    n *= 2;
    double ans = 0;
    int t = 0;
    for(int i = 0; i < n; i++)
    {
        double x; scanf("%lf", &x);
        ans += x - floor(x);
        //cout << x << " " << floor(x) << endl;
        if(x - floor(x) < 1e-9) t++;
    }
    //cout << t << endl;
    double s = INF;
    n /= 2;
    for(int i = n - t; i <= n; i++) s = min(s, fabs(i - ans));
    printf("%.3f\n", s);
    return 0;
}
