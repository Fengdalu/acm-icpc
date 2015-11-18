#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define PII pair<double, double>
#define x first
#define y second
#define MP(x, Y) make_pair(x, y)
#define eps 1e-7

PII A, B, C;
double D, V, T, F, W;

double t1, t2, t3;

double sqr(double x) { return x * x; }
double dis(PII a, PII b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
double sign(double x) { return fabs(x) < eps; }

double X(PII a, PII b) { return a.x * b.y - a.y * b.x;  }
PII dec(PII a, PII b) { return PII(a.x - b.x, a.y - b.y); }
bool same(double x, double y) { return x > 0 && y > 0 || x < 0 && y < 0 || x == 0 && y == 0; }

int main()
{
    scanf("%lf%lf", &A.x, &A.y);
    scanf("%lf%lf", &B.x, &B.y);
    scanf("%lf%lf", &C.x, &C.y);
    scanf("%lf%lf", &D, &V);
    t1 = (3600 * (dis(A, C) + dis(C, B)) ) / (V) + D * 60 + 9 * 3600;

    int h1, m1, h2, m2;
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
    scanf("%lf", &W);
    t2 = (double)h2 * 3600 + (double)m2 * 60 + h1 * 3600 + m1 * 60;
    PII v1 = dec(C, A), v2 = dec(B, A);
    if( X(dec(B, A), dec(A, C)) == 0 && dis(A, C) <= dis(A, B) && dis(B, C) <= dis(A, B)  ) t3 = (double)D * 60 + (3600 * dis(A, B)) / (W);
    else t3 = (3600 * dis(A, B)) / (W);
    t3 += 9 * 3600;

    if(t1 < t2 && t1 < t3) puts("Alex");
    else if(t2 < t1 && t2 < t3) puts("Dmitry");
    else puts("Petr");
    return 0;
}

