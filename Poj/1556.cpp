#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
#define AA first
#define BB second
#define X first
#define Y second
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define TYPE double
#define PDD pair<TYPE, TYPE>
#define PL pair<PDD, PDD>
#define LD(x) PDD(min(x.AA.X, x.BB.X), min(x.AA.Y, x.BB.Y))
#define LU(x) PDD(min(x.AA.X, x.BB.X), max(x.AA.Y, x.BB.Y))
#define RU(x) PDD(max(x.AA.X, x.BB.X), max(x.AA.Y, x.BB.Y))
#define RD(x) PDD(max(x.AA.X, x.BB.X), min(x.AA.Y, x.BB.Y))
#define SQR(x) ((x) * (x))
#define INF 0x3f3f3f


PDD operator - (const PDD &a, const PDD &b)
{
    return PDD(a.X - b.X, a.Y - b.Y);
}

PDD operator + (const PDD &a, const PDD &b)
{
    return PDD(a.X + b.X, a.Y + b.Y);
}

double operator * (const PDD &a, const PDD &b)
{
    return a.X * b.Y - a.Y * b.X;
}

bool cross(const PL &a, const PL &b)
{
    PDD l = a.AA - a.BB;
    if( (l * (b.BB - a.BB)) * (l * (b.AA - a.BB)) >= 0 ) return false;
    l = b.AA - b.BB;
    if( (l * (a.BB - b.BB)) * (l * (a.AA - b.BB)) >= 0 ) return false;
    return true;
}

double dist(const PDD &a, const PDD &b)
{
    return sqrt(SQR(a.X - b.X) + SQR(a.Y - b.Y));
}

vector<PDD>v;
vector<PL>l;
double f[1000][1000];
int n;

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(n == -1) break;

        v.clear(); l.clear();
        v.PB(MP(0.0, 5.0));
        l.PB(PL(MP(0, 0), MP(0, 10)));
        l.PB(PL(MP(0, 10), MP(10, 10)));
        l.PB(PL(MP(10, 10), MP(10, 0)));
        l.PB(PL(MP(0, 0), MP(10, 0)));
        for(int i = 0; i < n; i++)
        {
            double x, a, b, c, d;
            scanf("%lf%lf%lf%lf%lf", &x, &a, &b, &c, &d);
            v.PB(PDD(x, a)); v.PB(PDD(x, b)); v.PB(PDD(x, c)); v.PB(PDD(x, d));
            l.PB(PL(MP(x, 0), MP(x, a)));
            l.PB(PL(MP(x, b), MP(x, c)));
            l.PB(PL(MP(x, d), MP(x, 10)));
        }
        v.PB(MP(10.0, 5.0));
        int n = v.size();
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) f[i][j] = INF;
        for(int i = 0; i < n; i++) f[i][i] = 0.0;
        int st = 0, ed = n - 1;

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                bool flg = true;
                for(int k = 0; k < l.size(); k++)
                if(cross(PL(v[i], v[j]), l[k])) { flg = false; break; }
                if(flg) f[i][j] = f[j][i] = dist(v[i], v[j]);
            }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        printf("%.2f\n", f[st][ed]);
    }
    return 0;
}
