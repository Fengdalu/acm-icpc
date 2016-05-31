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
    point() {}
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
point ptoseg(point p,point l1,point l2)
{
    //对称点
    point t=symmetric_point(p,l1,l2);
    if(((t-p)^(l1-p))*((t-p)^(l2-p))>eps)
        return dist(p,l1)>dist(p,l2)?l2:l1;
    return getnode(getline(p,t),getline(l1,l2));
}
int dots_inline(point p1,point p2,point p3)
{
    return zero((p2-p1)^(p3-p1));
}
int dot_online_in(point p,point l1,point l2)
{
    return ((l1-p)*(l2-p))<=eps;
}
//点p0到线段p1p2的距离
double pointtoseg(point p0,point p1,point p2)
{
    if(sign(((p2-p1)*(p0-p1))*((p1-p2)*(p0-p2)))<0)
        return min(dist(p0,p1),dist(p0,p2));
    else
    {
        return fabs((p2-p1)^(p0-p1))/dist(p1,p2);
    }
}
double r[505][505];
int vis[505][505];
int dx[5]= {1,0,0,0,-1};
int dy[5]= {0,1,0,-1,0};
int pos;
bool intable(point p)
{
    if(sign(p.x)>=0&&sign(p.y)>=0)
        return true;
    return false;
}
int cal(point p1,point p2)
{
    int ans=0;
    xishu l=getline(p1,p2);
//    printf("%f x + %f y + %f \n",l.a,l.b,l.c);
    point det=p1-p2;
    if(sign(fabs(det.x)-fabs(det.y))>=0)
    {
        for(int i=(int)p1.x; i<=(int)p2.x; i++)
        {
            point tmp(i,floor(-(l.c+l.a*i)/l.b));
            point p[4];
            p[0]=tmp;
            p[1]=tmp+point(0,-1);
            p[2]=point(i,ceil(-(l.c+l.a*i)/l.b));
            p[3]=p[2]+point(0,1);
            for(int j=0; j<4; j++)
            {
                if(intable(p[j])==0)
                    continue;
                if(vis[(int)p[j].x][(int)p[j].y]==pos)
                    continue;
                vis[(int)p[j].x][(int)p[j].y]=pos;
                if(!zero(r[(int)p[j].x][(int)p[j].y]))
                    if(sign(r[(int)p[j].x][(int)p[j].y]-pointtoseg(p[j],p1,p2))>=0)
                    {
                        ans++;
                    }
            }
        }
    }
    else
    {
        if(p1.y>p2.y)
            swap(p1,p2);
        for(int i=(int)p1.y; i<=(int)p2.y; i++)
        {
//            printf("\t%d\n",i);
            point tmp(floor(-(l.c+l.b*i)/l.a),i);
            point p[4];
            p[0]=tmp;
            p[1]=tmp+point(-1,0);
            p[2]=point(ceil(-(l.c+l.b*i)/l.a),i);
            p[3]=p[2]+point(1,0);
            for(int j=0; j<4; j++)
            {
                if(intable(p[j])==0)
                    continue;
                if(vis[(int)p[j].x][(int)p[j].y]==pos)
                    continue;
                vis[(int)p[j].x][(int)p[j].y]=pos;
                if(!zero(r[(int)p[j].x][(int)p[j].y]))
                    if(sign(r[(int)p[j].x][(int)p[j].y]-pointtoseg(p[j],p1,p2))>=0)
                    {
                        ans++;
                    }
            }
//            tmp.output();
//            tmp2.output();
//            for(int j=2; j<=2; j++)
//            {
//                point p=tmp+point(dx[j],dy[j]);
//                if(vis[(int)p.x][(int)p.y]==pos)
//                    continue;
//                else
//                {
//                    vis[(int)p.x][(int)p.y]=pos;
//                    if(!zero(r[(int)p.x][(int)p.y]))
//                        if(sign(r[(int)p.x][(int)p.y]-pointtoseg(p,p1,p2))>=0)
//                            ans++;
//                }
//            }
//            for(int j=2; j<=2; j++)
//            {
//                point p=tmp2+point(dx[j],dy[j]);
//                if(vis[(int)p.x][(int)p.y]==pos)
//                    continue;
//                else
//                {
//                    vis[(int)p.x][(int)p.y]=pos;
//                    if(!zero(r[(int)p.x][(int)p.y]))
//                        if(sign(r[(int)p.x][(int)p.y]-pointtoseg(p,p1,p2))>=0)
//                            ans++;
//                }
//            }
//            for(int j=2; j<=2; j++)
//            {
//                point p=tmp3+point(dx[j],dy[j]);
//                if(vis[(int)p.x][(int)p.y]==pos)
//                    continue;
//                else
//                {
//                    vis[(int)p.x][(int)p.y]=pos;
//                    if(!zero(r[(int)p.x][(int)p.y]))
//                        if(sign(r[(int)p.x][(int)p.y]-pointtoseg(p,p1,p2))>=0)
//                            ans++;
//                }
//            }
        }
    }
//    printf("%d\n",ans);
    return ans;
}
int main()
{
    memset(vis,-1,sizeof(vis));
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        scanf("%lf",&r[x][y]);
    }
    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        pos=i;
        point p1,p2;
        p1.input();
        p2.input();
        if(p1.x>p2.x)
            swap(p1,p2);
        else if(p1.x==p2.x&&p1.y>p2.y)
            swap(p1,p2);
        printf("%d\n",cal(p1,p2));
    }
    return 0;
}
