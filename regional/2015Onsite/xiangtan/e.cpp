#include<stdio.h>
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
const double pi=acos(-1.0);
struct point
{
    double x,y;
    double tht;
    point(){}
    point(double xx,double yy)
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
//两点距离
double dist(point p1,point p2)
{
    return sqrt((p1-p2)*(p1-p2));
}
//两点距离平方
double dist2(point p1,point p2)
{
    return (p1-p2)*(p1-p2);
}
//计算向量p0p1与p0p2的夹角
double gettht(point p0,point p1,point p2)
{
    return acos((p1-p0)*(p2-p0)/(dist(p0,p1)*dist(p0,p2)));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double j1,j2;
        scanf("%lf%lf",&j1,&j2);
        j1=(60-j1)/180.0*pi;
        j2=j2/180.0*pi;
        double a=2.0*sin(j2)/sin(j1+j2);
        point po(-1+a*cos(j1),a*sin(j1));
        point pa(0,sqrt(3));
        point pc(1,0);
        printf("%.2f\n",gettht(pa,po,pc)/pi*180);
    }
    return 0;
}
