#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
bool zero(double x)
{
    return fabs(x)<=eps;
}
int sign(double x)
{
    if(zero(x))
        return 0;
    if(x>0)
        return 1;
    return -1;
}
long long k=100000;
bool check(long long l,long long d,long long r)
{
    if(l*d*r-(d*r+l*r+l*d)*k>0)
        return true;
    return false;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double l,d,r;
        scanf("%lf%lf%lf",&l,&d,&r);
        long long L,D,R;
        L=(long long)((l+eps)*k);
        D=(long long)((d+eps)*k);
        R=(long long)((r+eps)*k);
//        printf("%I64d %I64d %I64d\n",L,D,R);
//        printf("%I64d\n",L*D*R);
        int flag=0;
        flag|=check(L,D,R);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
