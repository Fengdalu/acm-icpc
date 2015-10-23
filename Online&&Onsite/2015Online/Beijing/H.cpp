#include<cstdio>
#include<cmath>
using namespace std;
double eps = 1e-9;
long long a[1005];
double b[1005];
int main()
{
    int _T;
    scanf("%d",&_T);
    double x;
    a[0] = 1;
    for(int i = 1; i <= 1000; i++)
        a[i] = a[i - 1] * 2LL;
    for(int i = 0; i <= 1000; i++)
        b[i] = (double)(a[i] - 1) / a[i] / 2.0;
    for(int i = 0; i <= 1000; i++)
        a[i] = b[i] * 10000000000LL;
//    for(int i = 0; i <= 50; i++)
//        printf("%d %I64d\n",i,a[i]);
    for(int CAS = 0; CAS < _T; CAS++)
    {
        scanf("%lf",&x);
        long long now = x * 10000000000LL;
        int ans = 0;
        if(ans == 0)
        {
            for(int i = 0; i <=50; i++)
                if(now == a[i]) ans = -1;
        }
        if(ans == 0)
        {
            for(int i = 0; i <= 50; i++)
                if(now > a[i]) ans = i * 4 + 4;
        }
        if(now == 5000000000)
            ans = 1000;
        if(now == 0)
            ans = -1;
        printf("%d\n",ans);
    }
}
