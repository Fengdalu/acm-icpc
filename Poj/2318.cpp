#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <complex>
#define N 5555
#define M 5555
#define LL long long
#define PB(i) push_back(i)
#define eps 0
#define SZ() size()
#define rset(f, i) memset(f, i, sizeof f)
#define rep(i, n) for(int i = 0; i != n; i++)
#define FOR(i, j, k) for(int i = j; i != k; i++)

using namespace std;

template<class T> class Complex
{
    public :
    T x, y;
    Complex (T a = T(0), T b = T(0)) : x(a), y(b) {}
public:
    Complex<T> operator + (Complex<T> b)
    {
        return Complex<T>(this->x + b.x, this->y + b.y);
    }
    Complex<T> operator - (Complex<T> b)
    {
        return Complex<T>(this->x - b.x, this->y - b.y);
    }
    T operator * (Complex<T> b)
    {
        return (this->x * b.x + this->y * b.y);
    }
    T operator ^ (Complex<T> b)
    {
        return this->x * b.y - this->y * b.x;
    }
    bool operator == (Complex<T> b)
    {
        return (abs(this->x - b.x) <= eps && abs(this->y - b.y) <= eps);
    }
};

typedef Complex<LL> Vector;
typedef Complex<LL> Point;

class Line
{
public:
    Point a, b;
    Line(){}
    Line(Point x, Point y) {a = x; b = y;}
public:
    LL operator * (Point x)
    {
        LL t = ((this->a - x) ^ (this->b - x));
        return (t > 0) ? 1 : -1;
    }
}f[N];

int ans[N];
int main()
{
    int n, m;
    LL x1, x2, y1, y2;
    while(true)
    {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d%I64d%I64d%I64d%I64d", &m, &x1, &y1, &x2, &y2);
        FOR(i, 1, n + 1)
        {
            LL u, l;
            scanf("%I64d%I64d", &u, &l);
            f[i] = Line(Point(u, y1), Point(l, y2));
        }
        f[0] = Line(Point(x1, y1), Point(x1, y2));
        f[++n] = Line(Point(x2, y1), Point(x2, y2));
        memset(ans, 0, sizeof ans);
        rep(i, m)
        {
            LL u, l;
            scanf("%I64d%I64d", &u, &l);
            Point chk(u, l);
            int a = 0, b = n;
            while(a < b - 1)
            {
                int mid = (a + b) >> 1;
                if ((f[mid] * chk) * (f[b] * chk) < 0) a = mid;
                else b = mid;
            }
            ans[a]++;
        }
        rep(i, n) printf("%d: %d\n", i, ans[i]);
        putchar('\n');
    }
    //cout << Line(Point(0, 1), Point(0, 0)) * Point(10, 1) << endl;
    return 0;
}