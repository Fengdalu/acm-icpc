/*给出三维空间中的n个顶点,求解由这n个顶点构成的凸包表面的多边形个数.
增量法求解:首先任选4个点形成的一个四面体,然后每次新加一个点,分两种情况:
1> 在凸包内,则可以跳过
2> 在凸包外,找到从这个点可以"看见"的面,删除这些面,
然后对于一边没有面的线段,和新加的这个点新建一个面,至于这个点可以看见的面,
就是求出这个面的方程(可以直接求法向量).
下面是三维凸包的模板。。有了这个模板应该对付三维凸包的题就没问题了吧。。*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=505;
const double EPS=1e-8;
struct Point
{
    double x,y,z;
    Point() {}
    Point(double xx,double yy,double zz):x(xx),y(yy),z(zz) {}
    Point operator -(const Point p1) //两向量之差
    {
        return Point(x-p1.x,y-p1.y,z-p1.z);
    }
    Point operator *(Point p) //叉乘
    {
        return Point(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
    }
    double operator ^(Point p) //点乘
    {
        return (x*p.x+y*p.y+z*p.z);
    }
};
struct CH3D
{
    struct face
    {
        int a,b,c; //表示凸包一个面上三个点的编号
        bool ok; //表示该面是否属于最终凸包中的面
    };
    int n; //初始顶点数
    Point P[MAXN]; //初始顶点
    int num; //凸包表面的三角形数
    face F[8*MAXN];
    int g[MAXN][MAXN]; //凸包表面的三角形
    double vlen(Point a) //向量长度
    {
        return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
    }
    Point cross(const Point &a, const Point &b, const Point &c) //叉乘
    {
        return Point((b.y-a.y)*(c.z-a.z)-(b.z-a.z)*(c.y-a.y),-((b.x-a.x)*(c.z-a.z)
                     -(b.z-a.z)*(c.x-a.x)),(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
    }
    double area(Point a,Point b,Point c) //三角形面积*2
    {
        return vlen((b-a)*(c-a));
    }
    double volume(Point a,Point b,Point c,Point d) //四面体有向体积*6
    {
        return (b-a)*(c-a)^(d-a);
    }
    double dblcmp(Point &p,face &f) //正:点在面同向
    {
        Point m=P[f.b]-P[f.a];
        Point n=P[f.c]-P[f.a];
        Point t=p-P[f.a];
        return (m*n)^t;
    }
    void deal(int p,int a,int b)
    {
        int f=g[a][b];
        face add;
        if(F[f].ok)
        {
            if(dblcmp(P[p],F[f])>EPS)
                dfs(p,f);
            else
            {
                add.a=b;
                add.b=a;
                add.c=p;
                add.ok=1;
                g[p][b]=g[a][p]=g[b][a]=num;
                F[num++]=add;
            }
        }
    }
    void dfs(int p,int now)
    {
        F[now].ok=0;
        deal(p,F[now].b,F[now].a);
        deal(p,F[now].c,F[now].b);
        deal(p,F[now].a,F[now].c);
    }
    bool same(int s,int t)
    {
        Point &a=P[F[s].a];
        Point &b=P[F[s].b];
        Point &c=P[F[s].c];
        return fabs(volume(a,b,c,P[F[t].a]))<EPS && fabs(volume(a,b,c,P[F[t].b]))<EPS
               && fabs(volume(a,b,c,P[F[t].c]))<EPS;
    }
    void solve() //构建三维凸包
    {
        int i,j,tmp;
        face add;
        bool flag=true;
        num=0;
        if(n<4)
            return;
        for(i=1; i<n; i++) //此段是为了保证前四个点不共面,若以保证,则可去掉
        {
            if(vlen(P[0]-P[i])>EPS)
            {
                swap(P[1],P[i]);
                flag=false;
                break;
            }
        }
        if(flag)
            return;
        flag=true;
        for(i=2; i<n; i++) //使前三点不共线
        {
            if(vlen((P[0]-P[1])*(P[1]-P[i]))>EPS)
            {
                swap(P[2],P[i]);
                flag=false;
                break;
            }
        }
        if(flag)
            return;
        flag=true;
        for(i=3; i<n; i++) //使前四点不共面
        {
            if(fabs((P[0]-P[1])*(P[1]-P[2])^(P[0]-P[i]))>EPS)
            {
                swap(P[3],P[i]);
                flag=false;
                break;
            }
        }
        if(flag)
            return;
        for(i=0; i<4; i++)
        {
            add.a=(i+1)%4;
            add.b=(i+2)%4;
            add.c=(i+3)%4;
            add.ok=true;
            if(dblcmp(P[i],add)>0)
                swap(add.b,add.c);
            g[add.a][add.b]=g[add.b][add.c]=g[add.c][add.a]=num;
            F[num++]=add;
        }
        for(i=4; i<n; i++)
        {
            for(j=0; j<num; j++)
            {
                if(F[j].ok && dblcmp(P[i],F[j])>EPS)
                {
                    dfs(i,j);
                    break;
                }
            }
        }
        tmp=num;
        for(i=num=0; i<tmp; i++)
            if(F[i].ok)
            {
                F[num++]=F[i];
            }
    }
    double area() //表面积
    {
        double res=0.0;
        if(n==3)
        {
            Point p=cross(P[0],P[1],P[2]);
            res=vlen(p)/2.0;
            return res;
        }
        for(int i=0; i<num; i++)
            res+=area(P[F[i].a],P[F[i].b],P[F[i].c]);
        return res/2.0;
    }
    double volume() //体积
    {
        double res=0.0;
        Point tmp(0,0,0);
        for(int i=0; i<num; i++)
            res+=volume(tmp,P[F[i].a],P[F[i].b],P[F[i].c]);
        return fabs(res/6.0);
    }
    int triangle() //表面三角形个数
    {
        return num;
    }
    int polygon() //表面多边形个数
    {
        int i,j,res,flag;
        for(i=res=0; i<num; i++)
        {
            flag=1;
            for(j=0; j<i; j++)
                if(same(i,j))
                {
                    flag=0;
                    break;
                }
            res+=flag;
        }
        return res;
    }
    Point getcent()//求凸包质心
    {
        Point ans(0,0,0),temp=P[F[0].a];
        double v = 0.0,t2;
        for(int i=0; i<num; i++)
        {
            if(F[i].ok == true)
            {
                Point p1=P[F[i].a],p2=P[F[i].b],p3=P[F[i].c];
                t2 = volume(temp,p1,p2,p3)/6.0;//体积大于0，也就是说，点 temp 不在这个面上
                if(t2>0)
                {
                    ans.x += (p1.x+p2.x+p3.x+temp.x)*t2;
                    ans.y += (p1.y+p2.y+p3.y+temp.y)*t2;
                    ans.z += (p1.z+p2.z+p3.z+temp.z)*t2;
                    v += t2;
                }
            }
        }
        ans.x /= (4*v);
        ans.y /= (4*v);
        ans.z /= (4*v);
        return ans;
    }
    double function(Point fuck) //点到凸包上的最近距离（枚举每个面到这个点的距离）
    {
        double min=99999999;
        for(int i=0; i<num; i++)
        {
            if(F[i].ok==true)
            {
                Point p1=P[F[i].a] , p2=P[F[i].b] , p3=P[F[i].c];
                double a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );
                double b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );
                double c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );
                double d = ( 0-(a*p1.x+b*p1.y+c*p1.z) );
                double temp = fabs(a*fuck.x+b*fuck.y+c*fuck.z+d)/sqrt(a*a+b*b+c*c);
                if(temp<min)min = temp;
            }
        }
        return min;
    }
};
CH3D hull;
 int main()
 {
     while(scanf("%d",&hull.n)!=EOF)
     {
         for(int i=0;i<hull.n;i++)
         scanf("%lf%lf%lf",&hull.P[i].x,&hull.P[i].y,&hull.P[i].z);
         hull.solve();
         printf("%.3f\n",hull.function(hull.getcent()));
     }
     return 0;
 }