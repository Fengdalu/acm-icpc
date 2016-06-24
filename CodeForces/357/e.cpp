#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn =  100010;
struct point { double x, y; point(){} point(double x, double y):x(x), y(y){} };
struct circle {
    point o;
    double r;
}c[maxn];
struct obj {
    point a;
    int add;
    obj(){}
    obj(point x, int pls) {
        a = x;
        add = pls;
    }
}f[maxn * 2];
point o;
double v, T;
double r;
int n;
inline double mul(point a, point b) {
    return a.y * b.x - a.x * b.y;
}

inline double sqr(double x) { return x * x; }
double dis(point a, point b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

inline int cmp(circle a, circle b) {
    return mul(point(a.o.x - o.x, a.o.y - o.y), point(b.o.x - o.x, b.o.y - o.y)) < 0;
}

inline int cmp2(obj a, obj b) {
    return mul(a.a, b.a) < 0;
}

point rotate(point v, double a) {
    return point(v.x * cos(a) + v.y * sin(a), v.x * -sin(a) + v.y * cos(a));
}

double length(point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

int main() {
    scanf("%lf%lf%lf%lf", &o.x, &o.y, &v, &T);
    r = v * T;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &c[i].o.x, &c[i].o.y, &c[i].r);
    }
    sort(c, c + n, cmp);
    int l = -1, r = -1;
    int cnt = 0;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        double d = dis(o, c[i].o);
        if(d > r + c[i].r) continue;
        if(d < abs(r - c[i].r)) {
            if(c[i].r >= r) {
                flag = true;
                break;
            }
            point v = point(c[i].o.x - o.x, c[i].o.y - o.y);
            double a = asin(c[i].r / d);
            f[cnt++] = obj(rotate(v, a), 1);
            f[cnt++] = obj(rotate(v, -a), 1);
        }
        else {
            double a = acos((sqr(d) + sqr(r) - sqr(c[i].r)) / 2 * d * r);
            point v = point(c[i].o.x - o.x, c[i].o.y - o.y);
            f[cnt++] = obj(rotate(v, a), 1);
            f[cnt++] = obj(rotate(v, -a), -1);
        }
    }
    sort(f, f + cnt, cmp2);
    int cover = 0;
    int i = 0;
    while(i < cnt && f[i].add < 0) i++;

        cover += f[i].add;
        if(i != 0 && cover != 0) {

        }
    }
    return 0;
}
