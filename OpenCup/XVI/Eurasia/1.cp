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
struct point
{
    double x,y;
    double tht;
    point(double xx=0.0,double yy=0.0)
    {
        x=xx;
        y=yy;
    }
    void output()
    {
        printf("(%f,%f)\n",x,y);
    }
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    point operator -(const point &b)
    {
        return point(x - b.x, y - b.y);
    }
    point operator +(const point &b)
    {
        return point(x + b.x, y + b.y);
    }
    double operator ^(const point &b)
    {
        return x*b.y - y*b.x;
    }
    double operator *(const point &b)
    {
        return x*b.x + y*b.y;
    }
};
struct xishu//直线ax+by+c=0的系数
{
    double a,b,c;
};
xishu getline(point x,point y)
{
    struct xishu w;
    w.a=y.y-x.y;
    w.b=x.x-y.x;
    w.c=y.x*x.y-x.x*y.y;
    return w;
}
point getnode(xishu l1,xishu l2)
{
    point CrossP;
    CrossP.x=(l1.c*l2.b-l1.b*l2.c)/(l1.a*l2.b-l1.b*l2.a)*(-1.0);
    CrossP.y=(l1.c*l2.a-l1.a*l2.c)/(l1.b*l2.a-l1.a*l2.b)*(-1.0);
    return CrossP;
}
point symmetric_point(point p1, point l1, point l2)
{
    point ret;
    xishu line1=getline(l1,l2);
    point vec=point((l1.y-l2.y),(l2.x-l1.x));
    point p2=p1+vec;
    xishu line2=getline(p1,p2);
    point cross=getnode(line1,line2);
    ret.x=cross.x*2-p1.x;
    ret.y=cross.y*2-p1.y;
    return ret;
}
point p[100005];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        p[i].input();
    for(int i=0;i<m;i++)
    {
        point l1,l2;
        l1.input();
        l2.input();
        xishu l=getline(l1,l2);
        for(int j=0;j<n;j++)
        {
            if(sign(l.a*p[j].x+l.b*p[j].y+l.c)==1)
            {
                p[j]=symmetric_point(p[j],l1,l2);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%f %f\n",p[i].x,p[i].y);
    }
    return 0;
}
