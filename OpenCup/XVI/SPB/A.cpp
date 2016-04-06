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
set<long long>ss;
struct point
{
    double x,y;
};
bool zero(double x)
{
    if(fabs(x)<=eps)
        return true;
    return false;
}
bool cmp(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
point p[1005];
int main()
{
    freopen("bubbles.in","r",stdin);
    freopen("bubbles.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(zero(p[i].x-p[j].x)&&zero(p[i].y-p[j].y))
            {
                printf("0\n");
                return 0;
            }
            if(zero(p[i].x-p[j].x))
                continue;
            double l=-1000000,r=1000000;
            while(r-l>eps)
            {
                double mid=(l+r)/2.0;
                double dis1=(p[i].x-mid)*(p[i].x-mid)+p[i].y*p[i].y;
                double dis2=(p[j].x-mid)*(p[j].x-mid)+p[j].y*p[j].y;
                if(dis1<dis2)
                    l=mid;
                else
                    r=mid;
            }
//            printf("%d %d\n",i,j);
//            printf("%f\n",l);
//            printf("%I64d\n",(long long)((l+eps)*1000000LL));
            ss.insert((long long)((l+eps)*1000000LL));
        }
    }
    printf("%d\n",ss.size()+1);
    return 0;
}
