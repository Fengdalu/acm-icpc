#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define LL long long
#define PLL pair<LL, LL>
#define PL pair< PLL, PLL >
#define MP(a, b) make_pair(a, b)
#define X first
#define Y second
#define AA first
#define BB second
#define PB(x) push_back(x)

LL operator * (const PLL &a, const PLL &b)
{
    return b.Y * a.X - b.X * a.Y;
}

PLL operator + (const PLL &a, const PLL &b)
{
    return PLL(a.X + b.X, a.Y + b.Y);
}

PLL operator - (const PLL &a, const PLL &b)
{
    return PLL(-a.X, -a.Y) + b;
}

bool in(const PLL &x, const PLL &a, const PLL &b)
{
    if(x.X < min(a.X, b.X) || x.X > max(a.X, b.X)) return false;
    if(x.Y < min(a.Y, b.Y) || x.Y > max(a.Y, b.Y)) return false;
    return true;
}

bool valid(const PLL &a, const PLL &b)
{
    if(a.X <= b.X && a.Y <= b.Y) return true;
    return false;
}

bool pq(const PL &a, const PL &b)
{
    if(valid(
             PLL( max(min(a.AA.X, a.BB.X), min(b.AA.X, b.BB.X)),
                    max(min(a.AA.Y, a.BB.Y), min(b.AA.Y, b.BB.Y))
                 ),
             PLL( min(max(a.AA.X, a.BB.X), max(b.AA.X, b.BB.X)), min(max(a.AA.Y, a.BB.Y), max(b.AA.Y, b.BB.Y)))
             )) return true;
    return false;
}

bool cross(const PL &a, const PL &b)
{
    if(!pq(a, b)) return false;
    PLL l = (a.BB - a.AA);
    if( (l * (b.AA - a.AA) ) * ( l * (b.BB - a.AA) ) > 0) return false;
    l = (b.AA - b.BB);
    if( (l * (a.AA - b.BB) ) * ( l * (a.BB - b.BB) ) > 0) return false;
    return true;
}

PL l;
PLL x, y;
PLL a, b, c, d;
vector<PL>s;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while(T--)
    {
        cin >> l.AA.X >> l.AA.Y >> l.BB.X >> l.BB.Y >> x.X >> x.Y >> y.X >> y.Y;
        a = MP(min(x.X, y.X), min(x.Y, y.Y));
        b = MP(max(x.X, y.X), min(x.Y, y.Y));
        c = MP(max(x.X, y.X), max(x.Y, y.Y));
        d = MP(min(x.X, y.X), max(x.Y, y.Y));

        s.clear();
        s.PB(MP(a, b));
        s.PB(MP(b, c));
        s.PB(MP(c, d));
        s.PB(MP(a, d));
        int cnt = 0;
        for(int i = 0; i < 4; i++)
        if(cross(l, s[i]))
        {
            cnt++;
        }
       //cout << cnt << endl;
//        cout << cross(MP(PLL(0, 0), PLL(10, 10)), MP(PLL(0, 10), PLL(10, 0))) << endl;
        if( cnt >= 1 || ( in(l.AA, a, c) && in(l.BB, a, c) ) ) printf("T\n"); else printf("F\n");
        //cout << endl;
    }
    return 0;
}
