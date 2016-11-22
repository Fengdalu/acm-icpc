#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
bool zero(double x)
{
    if(fabs(x)<=eps)
        return true;
    return false;
}
int sign(double x)
{
    if(zero(x))return 0;
    if(x>0)return 1;
    return -1;
}
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
struct xishu//直线ax+by+c=0的系数
{
    double a,b,c;
};
//两点距离
double dist(point p1,point p2)
{
    return sqrt((p1-p2)*(p1-p2));
}
//点到直线的距离
double disptoline(point p,point l1,point l2)
{
    return fabs((p-l2)^(l1-l2))/dist(l1,l2);
}
//线段
double ptoseg(point p,point l1,point l2)
{
    if(sign((l2-l1)*(p-l1))>=0&&sign((l1-l2)*(p-l2))>=0)
    {
        return disptoline(p,l1,l2);
    }
    else
    {
        return min(dist(p,l1),dist(p,l2));
    }
}

struct rec
{
    point p[4];
};
int n,W,H;
rec node[105];
double dis[222][222];
double cal(int x,int y)
{
    double ans=1e9;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            ans=min(ans,ptoseg(node[x].p[i],node[y].p[j],node[y].p[(j+1)%4]));
            ans=min(ans,ptoseg(node[y].p[i],node[x].p[j],node[x].p[(j+1)%4]));
        }
    }
    return ans;
}
void floyd()
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(i!=j&&dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
}
int main()
{
    freopen("street.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&H,&W);
        for(int i=0;i<n;i++)
        {
            int h,w,d,type;
            scanf("%d%d%d%d",&h,&w,&d,&type);
            if(type)
            {
                node[i].p[0]=point(0,d);
                node[i].p[1]=point(w,d);
                node[i].p[2]=point(w,d+h);
                node[i].p[3]=point(0,d+h);
            }
            else
            {
                node[i].p[0]=point(W-w,d);
                node[i].p[1]=point(W,d);
                node[i].p[2]=point(W,d+h);
                node[i].p[3]=point(W-w,d+h);
            }
        }
        node[n].p[0]=point(0,0);
        node[n].p[1]=point(W,0);
        node[n].p[2]=point(W,0);
        node[n].p[3]=point(0,0);
        n++;
        node[n].p[0]=point(0,H);
        node[n].p[1]=point(W,H);
        node[n].p[2]=point(W,H);
        node[n].p[3]=point(W,H);
        n++;
        for(int i=0;i<n;i++)
        {
            dis[i][i]=0.0;
            for(int j=i+1;j<n;j++)
            {
                double ddd=cal(i,j);
                dis[i][j]=ddd;
                dis[j][i]=ddd;
            }
        }
        floyd();
        printf("%.6f\n",dis[n-2][n-1]);
    }
    return 0;
}
