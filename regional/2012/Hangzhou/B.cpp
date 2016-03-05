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
#define zero(x) (((x)>0?(x):-(x))<eps)
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))

const double pi=acos(-1.0);

struct point
{
    double x,y;
    double tht;
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    void output()
    {
        printf("(%.0f,%.0f)\n",x,y);
    }
};
struct xishu//直线ax+by+c=0的系数
{
    double a,b,c;
};
double xmult(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//计算 dot product (P1-P0).(P2-P0)
double dmult(point p0,point p1,point p2)
{
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
double dist(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
//计算向量p0p1与p0p2的夹角
double gettht(point p0,point p1,point p2)
{
    return acos(dmult(p0,p1,p2)/(dist(p0,p1)*dist(p0,p2)));
}
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
//点a绕点b逆时针旋转tht弧度
point rotate_nod(point a,point b,double tht)
{
    point pp1;
    pp1.x=b.x+cos(tht)*(a.x-b.x)-sin(tht)*(a.y-b.y);
    pp1.y=b.y+sin(tht)*(a.x-b.x)+cos(tht)*(a.y-b.y);
    return pp1;
}
point symmetric_point(point p1, point l1, point l2)
{
    point ret;
    xishu line=getline(l1,l2);
    double term=1.0;
    if(p1.x*line.a+p1.y*line.b+line.c+eps<0)
    {
        term=-1.0;
    }
    double tht=gettht(l1,p1,l2);
    ret=rotate_nod(p1,l1,term*tht*2.0);
    return ret;
}
//线段
point ptoseg(point p,point l1,point l2)
{
    //对称点
    point t=symmetric_point(p,l1,l2);
    if(xmult(p,t,l1)*xmult(p,t,l2)>0)
        return dist(p,l1)>dist(p,l2)?l2:l1;
    return getnode(getline(p,t),getline(l1,l2));
}

int main()
{
//    freopen("ant.txt","r",stdin);
    point fst;
    point cir;
    double r;
    point rec[4];
    while(1)
    {
        fst.input();
        if(zero(fst.x)&&zero(fst.y))
            break;
        cir.input();
        scanf("%lf",&r);
        rec[0].input();
        rec[2].input();
        rec[1].x=rec[2].x;
        rec[1].y=rec[0].y;
        rec[3].x=rec[0].x;
        rec[3].y=rec[2].y;
        double ans=9999999;
        double tht=0.0;
        double d=pi/11562.5;
        while(tht<=2*pi)
        {
            double tmp=0.0;
            point n;
            n.x=cir.x+r*cos(tht);
            n.y=cir.y+r*sin(tht);
            tmp=dist(n,fst);
            double tmp2=9999999;
            for(int i=0;i<4;i++)
            {
                point crs=ptoseg(n,rec[i],rec[(i+1)%4]);
                tmp2=MIN(tmp2,dist(n,crs));
            }
            ans=MIN(ans,tmp+tmp2);
            tht+=d;
        }
        printf("%.2f\n",ans);
    }
    return 0;
}