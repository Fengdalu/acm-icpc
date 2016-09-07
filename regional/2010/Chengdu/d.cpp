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
#include <cassert>
#define eps 1e-8
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
using std::make_pair;
using std::vector;

const double pi = acos(-1.0);
inline double trans(double x) {
    return x / 2 / pi * 360;
}
namespace GEO {
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

    struct point;
    double dist(point ,point );
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
        int operator < (const point &t) const {
            return MP(x, y) < MP(t.x, t.y);
        }
        int operator == (const point &t) const {
            return dist(t, *this) <= eps;
        }
    };

    struct line
    {
        point a,b;
        line(){}
        line(point a, point b): a(a), b(b) {}
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

    int dot_online_in(point p,point l1,point l2)
    {
        return ((l1-p)*(l2-p))<=eps;
    }

    int dots_inline(point p1,point p2,point p3)
    {
        return zero((p2-p1)^(p3-p1));
    }

    //判点是否在线段上,不包括端点
    int dot_online_ex(point p,point l1,point l2)
    {
        return ((l1-p)*(l2-p))<-eps;
    }
    point getnode(xishu f,xishu g)//两直线交点
    {
        point CrossP;
        CrossP.x=(f.c*g.b-f.b*g.c)/(f.a*g.b-f.b*g.a)*(-1.0);
        CrossP.y=(f.c*g.a-f.a*g.c)/(f.b*g.a-f.a*g.b)*(-1.0);
        return CrossP;
    }
    double dist(point p1,point p2)
    {
        return sqrt((p1-p2)*(p1-p2));
    }
    double gettht(point p0,point p1,point p2)
    {
        return acos((p1-p0)*(p2-p0)/(dist(p0,p1)*dist(p0,p2)));
    }
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
        xishu line1=getline(l1,l2);

        point vec=point((l1.y-l2.y),(l2.x-l1.x));
        point p2=p1+vec;
        xishu line2=getline(p1,p2);
        point cross=getnode(line1,line2);
        ret.x=cross.x*2-p1.x;
        ret.y=cross.y*2-p1.y;
        return ret;
    }

    struct point3{double x,y,z;point3(){}point3(int x, int y, int z): x(x), y(y), z(x){}}; struct line3{point3 a,b;}; struct plane3{point3 a,b,c;};

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

    int parallel(line3 u,line3 v)
    {
        return vlen(xmult(subt(u.a,u.b),subt(v.a,v.b)))<eps;
    }
    int parallel(point3 u1,point3 u2,point3 v1,point3 v2)
    {
        return vlen(xmult(subt(u1,u2),subt(v1,v2)))<eps;
    }
    int same_side(point p1,point p2,point l1,point l2)
    {
        return (((p1-l1)^(l2-l1))*((p2-l1)^(l2-l1)))>eps;
    }
};

using namespace GEO;

// u -> v, A----B
std::vector<point> cross(point u, point v, point A, point B) {
    std::vector<point> r;
    if(((u - v) ^ (A - B)) == 0) return r;
    point p = getnode(getline(u, v), getline(A, B));
    if(dots_inline(p, A, B) && !dot_online_in(p, A, B))  return r;
    if(((v - u) * (p - u)) < 0) return r;
    r.PB(p);
    return r;
}

inline void solve() {
    point u, v; u.input(); v.input();
    point A, B, C; A.input(); B.input(); C.input();
    double TH; scanf("%lf", &TH);
    vector<point> p;

    vector<point>t;
    t = cross(u, v, A, B); p.insert(p.begin(), t.begin(), t.end());
    t = cross(u, v, C, B); p.insert(p.begin(), t.begin(), t.end());
    t = cross(u, v, C, A); p.insert(p.begin(), t.begin(), t.end());
    std::sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if(p.size() == 0) {

    }
    else if(p.size() == 1) {

    }
    else if(p.size() == 2) {
        point M = p[0], N = p[1];
        if(dist(M, u) > dist(N, u)) std::swap(M, N);
        bool flag = false;
        if(M == A || M == B || M == C) {
            if(N == A || N == B || N == C) flag = true;
        }
        else if(!flag){
            point P, Q;
            if(dots_inline(M, A, B) && dot_online_in(M, A, B)) { P = A; Q = B; }
            if(dots_inline(M, A, C) && dot_online_in(M, A, C)) { P = A; Q = C; }
            if(dots_inline(M, B, C) && dot_online_in(M, C, B)) { P = C; Q = B; }

            double th = gettht(M, u, Q);
            if(th > pi / 2) th -= pi / 2;
            else th = pi / 2 - th;
            double del = asin(sin(th) / TH);
            point a0 = rotate_nod(u, M, pi + th - del), a1 = rotate_nod(u, M, pi + del - th);
            double th1 = gettht(M, a0, Q); if(th1 > pi / 2) th1 -= pi / 2; else th1 = pi / 2 - th1;
            double th2 = gettht(M, a1, Q); if(th2 > pi / 2) th2 -= pi / 2; else th2 = pi / 2 - th2;
            if(zero(th1 - del)) v = a0; else v = a1;
            u = M;
            th1 = gettht(M, v, Q); if(th1 > pi / 2) th1 -= pi / 2; else th1 = pi / 2 - th1;
            /*
            std::cout << trans(th) << std::endl;
            std::cout << trans(th1) << std::endl;
            std::cout << trans(del) << std::endl;
            */
        }
        double limit = asin(1. / TH);
        while(true && !flag) {
            vector<point>t;
            vector<point>p;
            t = cross(u, v, A, B); p.insert(p.begin(), t.begin(), t.end());
            t = cross(u, v, C, B); p.insert(p.begin(), t.begin(), t.end());
            t = cross(u, v, C, A); p.insert(p.begin(), t.begin(), t.end());
            std::sort(p.begin(), p.end());
            p.erase(unique(p.begin(), p.end()), p.end());
            //std::cout << p.size() << std::endl;

            point M = p[0], N = p[1];
            if(p.size() == 2) {
                M = p[0], N = p[1];
                if((M - N) * (v - u) < 0) std::swap(M, N);
            }
            else M = p[0];
            point P, Q;
            if(dots_inline(M, A, B) && dot_online_in(M, A, B)) P = A, Q = B;
            if(dots_inline(M, A, C) && dot_online_in(M, A, C)) P = A, Q = C;
            if(dots_inline(M, C, B) && dot_online_in(M, C, B)) P = C, Q = B;

            double th = gettht(M, u, P);
            if(th > pi / 2) th -= pi / 2;
            else th = pi / 2 - th;

            if(sign(th - limit) >= 0) {
                // all reflect
                point v1 = rotate_nod(u, M, 2 * th);
                point v2 = rotate_nod(u, M, -2 * th);
                double th1 = gettht(M, v1, P), th2 = gettht(M, v2, P);
                if(th1 > pi / 2) th1 -= pi / 2; else th1 = pi / 2 - th1;
                if(th2 > pi / 2) th2 -= pi / 2; else th2 = pi / 2 - th2;
                if(zero(th1 - th)) v = v1; else v = v2;
                /*
                std::cout << trans(th) << std::endl;
                std::cout << trans(th1) << std::endl;
                std::cout << trans(th2) << std::endl;
                u = M;
                */
                puts("Error");
                return;
            }
            else {
                double del = asin(sin(th) * TH);
                // no reflect
                point a0 = rotate_nod(u, M, pi + del - th), a1 = rotate_nod(u, M, pi - del + th);
                double th1 = gettht(M, a0, Q); if(th1 > pi / 2) th1 -= pi / 2; else th1 = pi / 2 - th1;
                double th2 = gettht(M, a1, Q); if(th2 > pi / 2) th2 -= pi / 2; else th2 = pi / 2 - th2;
                if(zero(th1 - del)) v = a0; else v = a1;

                th1 = gettht(M, v, Q); if(th1 > pi / 2) th1 -= pi / 2; else th1 = pi / 2 - th1;
                /*
                std::cout << trans(th1) << std::endl;
                std::cout << trans(del) << std::endl;
                */
                u = M;
                break;
            }
        }
    }
    if(zero(((u - v) ^ (point(1, 0)))))  puts("Error");
    else {
        point x = getnode(getline(u, v), getline(point(1, 0), point(0, 0)));
        if((v - u) * (x - u) < 0) puts("Error");
        else printf("%.3f\n", x.x);
    }
}


int main() {
    int _t; scanf("%d", &_t);
    while(_t--) solve();
    return 0;
}
