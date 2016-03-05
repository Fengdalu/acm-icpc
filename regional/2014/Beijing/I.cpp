#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)
#define SIZE 1000005
#define INF 0x7fffffff

const double PI=acos(-1.0);

struct point
{
    double x,y;
};
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int intersect_circle_circle(point c1,double r1,point c2,double r2)
{
//    printf("%f %f %f\n",dist(c1,c2),r1,r2);
    return dist(c1,c2)<r1+r2-eps&&dist(c1,c2)>fabs(r1-r2)+eps;
}
double area_of_overlap(point c1, double r1, point c2, double r2)
{
    double a = dist(c1, c2), b = r1, c = r2;

    if(dist(c1,c2)<r1+r2-eps&&dist(c1,c2)>fabs(r1-r2)+eps)
    {
        double cta1 = acos((a * a + b * b - c * c) / 2 / (a * b)), cta2 = acos((a * a + c * c - b * b) / 2 / (a * c));
        double s1 = r1*r1*cta1 - r1*r1*sin(cta1)*(a * a + b * b - c * c) / 2 / (a * b);
        double s2 = r2*r2*cta2 - r2*r2*sin(cta2)*(a * a + c * c - b * b) / 2 / (a * c);
        return s1 + s2;
    }
    else if(dist(c1,c2)<=fabs(r1-r2)+eps)
    {
        double big=MAX(r1,r2);
        double sml=MIN(r1,r2);
        return PI*sml*sml;
    }
    else
        return 0.0;

}

int main()
{
//    while(1)
//    {
//        point c1,c2;
//        double r1,r2;
//        scanf("%lf%lf",&r1,&r2);
//        scanf("%lf%lf",&c1.x,&c1.y);
//        scanf("%lf%lf",&c2.x,&c2.y);
//        printf("%f\n",area_of_overlap(c1,r1,c2,r2));
//    }
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        double r,R;
        scanf("%lf%lf",&r,&R);
        point c1,c2;
        scanf("%lf%lf",&c1.x,&c1.y);
        scanf("%lf%lf",&c2.x,&c2.y);

        double ans=0.0;
        ans=ans+area_of_overlap(c1,R,c2,R);
//        printf("%f\n",ans);
        ans=ans-2.0*area_of_overlap(c1,r,c2,R);
//        printf("%f\n",ans);
        ans=ans+area_of_overlap(c1,r,c2,r);
//        printf("%f\n",area_of_overlap(c1,R,c2,R));
        printf("Case #%d: %.6f\n",cas,ans);

    }
    return 0;
}