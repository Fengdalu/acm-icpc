#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define u32  unsigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define N 1001

double x[N], y[N];
int f[N];
int a, b;
vector< pair<double, PII> >E;
int n;

int find(int x)
{
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

int m(int x, int y)
{
    f[find(x)] = find(y);
}

double SQR(double x) { return x * x; }

double dis(double x1, double y1, double x2, double y2)
{
    return sqrt(SQR(x1 - x2) + SQR(y1 - y2));
}

int main()
{
    while(~scanf("%d", &n))
    {
        if(!n) break;
        E.CLR;
        scanf("%d%d", &a, &b); a--; b--;
        FOR(i, n) scanf("%lf%lf", &x[i], &y[i]);
        FOR(i, n) FOR(j, n) if(i != j) E.PB(MP(dis(x[i], y[i], x[j], y[j]), MP(i, j)));
        sort(E.OP, E.ED);

        FOR(i, n) f[i] = i;
        double ans = 0.0;
        ans += dis(x[a], y[a], x[b], y[b]);
        m(a, b);

        int cnt = 1;
        ECH(E)
        if(find(it->BB.AA) != find(it->BB.BB))
        {
            ans += it->AA;
            m(it->BB.AA, it->BB.BB);
            cnt++; if(cnt == n) break;
        }
        printf("%.2f\n", ans);
    }
    return 0;
}