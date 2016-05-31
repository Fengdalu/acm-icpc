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
point box[4];
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
bool cmp1(point a,point b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}
point ttt;
bool cmp2(point a,point b)
{
    if(zero(a.tht-b.tht))
        return dist2(ttt,a)<dist2(ttt,b);
    return a.tht<b.tht;
}
point tubao[10];
int tbnum;
void gettubao(vector <point> p)
{
    int siz=p.size();
    memset(tubao,0,sizeof(tubao));
    sort(p.begin(),p.end(),cmp1);
    for(int i=1; i<siz; i++)
        p[i].tht=atan2(p[i].y-p[0].y,p[i].x-p[0].x);
    ttt=p[0];
    sort(++p.begin(),p.end(),cmp2);
    if(siz==1)
    {
        tbnum=1;
        tubao[0]=p[0];
        return ;
    }
    else if(siz==2)
    {
        tbnum=2;
        tubao[0]=p[0];
        tubao[1]=p[1];
        return ;
    }
    tbnum=2;
    tubao[0]=p[0];
    tubao[1]=p[1];
    for(int i=2; i<siz; i++)
    {
        while(tbnum>1)
        {
            if(((tubao[tbnum-1]-tubao[tbnum-2])^(p[i]-tubao[tbnum-2]))<=eps)
            {
                tbnum--;
            }
            else
                break;
        }
        tubao[tbnum++]=p[i];
    }
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
int main()
{
    int n=4;
    for(int i=0;i<4;i++)
        box[i].input();

    double ans=0;
    double S=((box[1]-box[0])^(box[2]-box[0]))+((box[2]-box[0])^(box[3]-box[0]));
    S=fabs(S)/2.0;
//    printf("S=%f\n",S);
    ans=ans+S*5*4;
//    printf("%f\n",ans);
    vector<point>vec;
    xishu l;
    double s;
    ///6
//    printf("6\n");
    s=0.0;
    l=getline(point(-0.5,0.5),point(0.5,0.5));
    vec.clear();
    for(int i=0;i<n;i++)
    {
        if(sign(box[i].y-0.5)>=0)
            vec.push_back(box[i]);
        if(sign(box[i].y-0.5)*sign(box[(i+1)%4].y-0.5)<0)
        {
            vec.push_back(getnode(l,getline(box[i],box[(i+1)%4])));
        }
    }
    gettubao(vec);
    for(int i=1;i<tbnum;i++)
        s=s+((tubao[i]-tubao[0])^(tubao[(i+1)%tbnum]-tubao[0]));
    ans=ans+fabs(s)/2.0*5*6;
//    for(int i=0;i<tbnum;i++)
//        tubao[i].output();
//    printf("%f\n",ans);
    ///3
//    printf("3\n");
    s=0.0;
    l=getline(point(0.5,0.5),point(0.5,-0.5));
    vec.clear();
    for(int i=0;i<n;i++)
    {
        if(sign(box[i].x-0.5)>=0)
            vec.push_back(box[i]);
        if(sign(box[i].x-0.5)*sign(box[(i+1)%4].x-0.5)<0)
        {
            vec.push_back(getnode(l,getline(box[i],box[(i+1)%4])));
        }
    }
    gettubao(vec);
    for(int i=1;i<tbnum;i++)
        s=s+((tubao[i]-tubao[0])^(tubao[(i+1)%tbnum]-tubao[0]));
    ans=ans+fabs(s)/2.0*5*3;
//    for(int i=0;i<tbnum;i++)
//        tubao[i].output();
//    printf("%f\n",ans);
    ///1
//    printf("1\n");
    s=0.0;
    l=getline(point(-0.5,-0.5),point(0.5,-0.5));
    vec.clear();
    for(int i=0;i<n;i++)
    {
        if(sign(box[i].y+0.5)<=0)
            vec.push_back(box[i]);
        if(sign(box[i].y+0.5)*sign(box[(i+1)%4].y+0.5)<0)
        {
//            printf("%d %d\n",i,(i+1)%4);
            xishu tmp=getline(box[i],box[(i+1)%4]);
//            printf("%f %f %f\n",tmp.a,tmp.b,tmp.c);
//            getnode(l,getline(box[i],box[(i+1)%4])).output();
            vec.push_back(getnode(l,getline(box[i],box[(i+1)%4])));
        }
    }
    gettubao(vec);
    for(int i=1;i<tbnum;i++)
        s=s+((tubao[i]-tubao[0])^(tubao[(i+1)%tbnum]-tubao[0]));
    ans=ans+fabs(s)/2.0*5*1;
//    for(int i=0;i<tbnum;i++)
//        tubao[i].output();
//    printf("%f\n",ans);
    ///4
//    printf("4\n");
    s=0.0;
    l=getline(point(-0.5,-0.5),point(-0.5,0.5));
    vec.clear();
    for(int i=0;i<n;i++)
    {
        if(sign(box[i].x+0.5)<=0)
            vec.push_back(box[i]);
        if(sign(box[i].x+0.5)*sign(box[(i+1)%4].x+0.5)<0)
        {
            vec.push_back(getnode(l,getline(box[i],box[(i+1)%4])));
        }
    }
    gettubao(vec);
    for(int i=1;i<tbnum;i++)
        s=s+((tubao[i]-tubao[0])^(tubao[(i+1)%tbnum]-tubao[0]));
    ans=ans+fabs(s)/2.0*5*4;
//    for(int i=0;i<tbnum;i++)
//        tubao[i].output();
//    printf("%f\n",ans);

    printf("%.10f\n",ans/(S*5-1));
    return 0;
}
