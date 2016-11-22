#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define eps 1e-16

const long double pi=3.141592653589793;

struct point
{
    long double x,y;
    long double tht;
    point(long double xx=0.0,long double yy=0.0)
    {
        x=xx;
        y=yy;
    }
    void input()
    {
        cin >> x >> y;
    }
    point operator -(const point &b)
    {
        return point(x - b.x, y - b.y);
    }
    point operator +(const point &b)
    {
        return point(x - b.x, y - b.y);
    }
    long double operator ^(const point &b)
    {
        return x*b.y - y*b.x;
    }
    long double operator *(const point &b)
    {
        return x*b.x + y*b.y;
    }
};
//两点距离
long double dist(point p1,point p2)
{
    return sqrt((p1-p2)*(p1-p2));
}

long double area_of_overlap(point c1, long double r1, point c2, long double r2)
{
    long double a=dist(c1,c2),b=r1,c=r2;
    //相交关系
    if(a<r1+r2-eps&&a>fabs(r1-r2)+eps)
    {
        long double cta1=acos((a*a+b*b-c*c)/(2*a*b));
        long double cta2=acos((a*a+c*c-b*b)/(2*a*c));
        long double s1=r1*r1*cta1-r1*r1*sin(cta1)*(a*a+b*b-c*c)/(2*a*b);
        long double s2=r2*r2*cta2-r2*r2*sin(cta2)*(a*a+c*c-b*b)/(2*a*c);
        return s1+s2;
    }
    //包含及内切
    else if(a<=fabs(r1-r2)+eps)
    {
        long double big=MAX(r1,r2);
        long double sml=MIN(r1,r2);
        return pi*sml*sml;
    }
    //相离及外切
    else
        return 0.0;
}

int main()
{
    point cir1,cir2;
    long double r1,r2;

    cir1.input();
    cin >> r1;
    cir2.input();
    cin >> r2;
    cout.precision(12);

    cout << area_of_overlap(cir1,r1,cir2,r2) << endl;
    return 0;
}