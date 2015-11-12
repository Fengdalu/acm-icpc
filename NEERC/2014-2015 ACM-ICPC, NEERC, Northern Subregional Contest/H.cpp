//三维几何函数库
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;
#define PB(x) push_back(x)
#define SZ size()
#define PII pair<int, int>
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define cmin(x, y) x = min(x, y)
#define MP(x, y) make_pair(x, y)



const double INF = 1e20;
struct point3{double x,y,z;}; struct line3{point3 a,b;}; struct plane3{point3 a,b,c;};
bool operator < (const point3& a, const point3& b)
{
    pair< pair<double, double>, double > x = MP(MP(a.x, a.y), a.z), y = MP(MP(b.x, b.y), b.z);
    return x < y;
}

bool operator == (const point3& a, const point3& b)
{
    pair< pair<double, double>, double > x = MP(MP(a.x, a.y), a.z), y = MP(MP(b.x, b.y), b.z);
    return x == y;
}
//计算 cross product U x V
point3 xmult(point3 u,point3 v){
point3 ret; ret.x=u.y*v.z-v.y*u.z; ret.y=u.z*v.x-u.x*v.z; ret.z=u.x*v.y-u.y*v.x;
return ret;
}
//计算 dot product U . V
double dmult(point3 u,point3 v){
return u.x*v.x+u.y*v.y+u.z*v.z;
}
//矢量差 U - V
point3 subt(point3 u,point3 v){
point3 ret; ret.x=u.x-v.x; ret.y=u.y-v.y; ret.z=u.z-v.z;
return ret;
}
//取平面法向量
point3 pvec(plane3 s){
return xmult(subt(s.a,s.b),subt(s.b,s.c));
}
point3 pvec(point3 s1,point3 s2,point3 s3){
return xmult(subt(s1,s2),subt(s2,s3));
}
//两点距离,单参数取向量大小
double dist(point3 p1,point3 p2){
return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}
//向量大小
double vlen(point3 p){
return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}

//判点是否在空间三角形上,包括边界,三点共线无意义
int dot_inplane_in(point3 p,plane3 s)
{
    return zero(vlen(xmult(subt(s.a,s.b),subt(s.a,s.c)))-vlen(xmult(subt(p,s.a),subt(p,s.b)))- vlen(xmult(subt(p,s.b),subt(p,s.c)))-vlen(xmult(subt(p,s.c),subt(p,s.a))));
}
int dot_inplane_in(point3 p,point3 s1,point3 s2,point3 s3)
{
    return zero(vlen(xmult(subt(s1,s2),subt(s1,s3)))-vlen(xmult(subt(p,s1),subt(p,s2)))- vlen(xmult(subt(p,s2),subt(p,s3)))-vlen(xmult(subt(p,s3),subt(p,s1))));
}
//判点是否在空间三角形上,不包括边界,三点共线无意义
int dot_inplane_ex(point3 p,plane3 s)
{
    return dot_inplane_in(p,s)&&vlen(xmult(subt(p,s.a),subt(p,s.b)))>eps&&
           vlen(xmult(subt(p,s.b),subt(p,s.c)))>eps&&vlen(xmult(subt(p,s.c),subt(p,s.a)))>eps;
}
int dot_inplane_ex(point3 p,point3 s1,point3 s2,point3 s3)
{
    return dot_inplane_in(p,s1,s2,s3)&&vlen(xmult(subt(p,s1),subt(p,s2)))>eps&&
           vlen(xmult(subt(p,s2),subt(p,s3)))>eps&&vlen(xmult(subt(p,s3),subt(p,s1)))>eps;
}

#define eps 1e-8
#define zero(x) (fabs(x)<eps)
#define sign(x) ((x)<-eps?-1:((x)>eps))

struct point
{
    double x,y;
    double tht;
    point(int xx=0,int yy=0)
    {
        x=xx;
        y=yy;
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
        return point(x - b.x, y - b.y);
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
int dot_online_in(point p,point l1,point l2)
{
    return ((l1-p)*(l2-p))<=eps;
}

int point_inside_polygon(point cp, vector<point>&p,int n)
{
    int i,k,d1,d2,wn=0;
  //  double sum=0;
    p.PB(p[0]);
    for( i=0;i<n;i++)
    {
        if(dot_online_in(cp,p[i],p[i+1])) return 2;//在边上
        k=sign((p[i+1]-p[i])^(cp-p[i+1]));
        d1=sign(p[i+0].y-cp.y);
        d2=sign(p[i+1].y-cp.y);
        if(k>0&&d1<=0&&d2>0)wn++;
        if(k<0&&d2<=0&&d1>0)wn--;
    }
    //1:在内部
    //0:在外部
    return wn!=0;
}


const int N = 2000;
plane3 faces[2010];
vector<point3>points;
point3 S, T;
int n;

inline int Pos(const point3& x)
{
    return lower_bound(points.OP, points.ED, x) - points.OP + 1;
}

point3& Get(int x) { return points[x - 1]; }


int ind[N];
int t[N * N], nt[N * N];
double c[N * N];
double f[N];
int pre[N];
int cnt;

void add(int x, int y, double z)
{
    t[cnt] = y;
    nt[cnt] = ind[x];
    c[cnt] = z;
    ind[x] = cnt++;
}

void add2(int x, int y, double z)
{
    add(x, y, z);
    add(y, x, z);
}

queue<int>Q;
bool vis[N];
void spfa(int from)
{
    memset(vis, 0, sizeof vis);
    memset(pre, -1, sizeof pre);
    for(int i = 0; i <= points.SZ; i++) f[i] = INF;
    f[from] = Get(from).z;

    while(Q.size()) Q.pop();
    while(Q.size())
    {
        int x = Q.front(); Q.pop();
        vis[x] = false;
        for(int k = ind[x]; k != -1; k = nt[k])
        if(f[t[k]] > max(f[x], Get(t[k]).z))
        {
            f[t[k]] = max(f[x], Get(t[k]).z);
            pre[t[k]] = x;
            if(!vis[t[k]])
            {
                Q.push(t[k]);
                vis[t[k]] = true;
            }
        }
    }
}


vector<int>from;
vector<int>to;
vector<point3>path;

int main()
{
    freopen("hiking.in", "r", stdin);
    //freopen("hiking.out", "w", stdout);
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lf%lf%lf", &faces[i].a.x, &faces[i].a.y, &faces[i].a.z);
        scanf("%lf%lf%lf", &faces[i].b.x, &faces[i].b.y, &faces[i].b.z);
        scanf("%lf%lf%lf", &faces[i].c.x, &faces[i].c.y, &faces[i].c.z);
    }


    scanf("%lf%lf%lf", &S.x, &S.y, &S.z);
    scanf("%lf%lf%lf", &T.x, &T.y, &T.z);

    for(int i = 1; i <= n; i++)
    {
        plane3 p = faces[i];
        points.PB(p.a);
        points.PB(p.b);
        points.PB(p.c);
    }
    sort(points.OP, points.ED);
    points.resize(unique(points.OP, points.ED) - points.OP);
    /*
    for(int i = 0; i < points.SZ; i++)
        cout << points[i].x << " " << points[i].y << " " << points[i].z << endl;
    */


    cnt = 0;
    memset(ind, -1, sizeof ind);
    for(int i = 1; i <= n; i++)
    {
        add2( Pos(faces[i].a), Pos(faces[i].b), dist(faces[i].a, faces[i].b) );
        add2( Pos(faces[i].a), Pos(faces[i].c), dist(faces[i].a, faces[i].c) );
        add2( Pos(faces[i].c), Pos(faces[i].b), dist(faces[i].c, faces[i].b) );
    }


    for(int i = 1; i <= n; i++)
    {
        vector<point>t;
        t.PB(point(faces[i].a.x, faces[i].a.y));
        t.PB(point(faces[i].b.x, faces[i].b.y));
        t.PB(point(faces[i].c.x, faces[i].c.y));
        point q(S.x, S.y);
        if( point_inside_polygon(q, t, t.SZ) )
        {
            cout << i << endl;
            from.PB(Pos(faces[i].a));
            from.PB(Pos(faces[i].b));
            from.PB(Pos(faces[i].c));
        }
    }


    for(int i = 1; i <= n; i++)
    {
        vector<point>t;
        t.PB(point(faces[i].a.x, faces[i].a.y));
        t.PB(point(faces[i].b.x, faces[i].b.y));
        t.PB(point(faces[i].c.x, faces[i].c.y));
        point q(T.x, T.y);
        if( point_inside_polygon(q, t, t.SZ) )
        {
            to.PB(Pos(faces[i].a));
            to.PB(Pos(faces[i].b));
            to.PB(Pos(faces[i].c));
        }
    }

    for(int i = 0; i < from.size(); i++) cout << from[i] << " "; cout << endl;
    for(int j = 0; j < to.size(); j++) cout << to[j] << " "; cout << endl;

    cout << Get(4).x << " " <<Get(4).y << " " << Get(4).z << endl;
    double ans = INF;
    for(int i = 0; i < from.size(); i++)
    {
        spfa(from[i]);
        for(int j = 0; j < to.size(); j++)
        {
            cmin( ans, f[to[j]] );
        }
    }
    path.clear();
    for(int i = 0; i < from.size(); i++)
    {
        spfa(from[i]);
        for(int j = 0; j < to.size(); j++)
        if(ans ==  f[to[j]] )
        {
            path.clear();
            path.PB(T);
            int k = to[j];
            while(k != -1)
            {
                if(!(Get(k) == path[path.SZ - 1])) path.PB(Get(k));
                k = pre[k];
            }
            if(!(S == path[path.SZ - 1])) path.PB(S);
            reverse(path.OP, path.ED);
            printf("%d\n", path.SZ);
            for(int k = 0; k < path.SZ; k++)
            {
                printf("%.0f %.0f %.0f\n", path[k].x, path[k].y, path[k].z);
            }
            fclose(stdout);
            return 0;
        }
    }
    return 0;
}
