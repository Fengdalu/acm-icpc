#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define DD pair<double, double>
#define AA first
#define BB second

DD p[101];
int n, m;
inline double SQR(double x)
{
    return x * x;
}

inline double dis(DD a, DD b)
{
    return SQR(a.AA - b.AA) + SQR(a.BB - b.BB);
}

bool valid(int x, int r)
{
    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        double d = dis(p[i], p[x]);
        if(d == r) return false;
        if(dis(p[i], p[x]) < r * r) cnt++;
    }
    return cnt == n;
}

int main()
{
    int _T; scanf("%d", &_T);
    while(_T--)
    {
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i++)
        {
            scanf("%lf%lf", &p[i].AA, &p[i].BB);
        }
        if(n > m) { printf("-1\n"); continue; }

        bool flg = false;
        for(int r = 1; r <= 2000; r++)
        {
            for(int i = 0; i < m; i++)
            if(valid(i, r))
            {
                printf("%d\n", r);
                flg = true;
                break;
            }
            if(flg) break;
        }
        if(!flg) printf("-1\n");
    }
    return 0;
}
