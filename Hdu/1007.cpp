#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
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
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*===========================================================*/
typedef pair<double, double> obj;
const int N = 100010;
#define INF
vector<obj> F, Q;
int n;
double d;


double SQR(double x) { return x * x; }
double dis(obj a, obj b)
{
    return sqrt(SQR(a.AA - b.AA) + SQR(a.BB - b.BB));
}

void solve(int L, int R)
{
    if(L == R) return;
    int mid = (L + R) / 2;

    double ans = -1;
    solve(L, mid); solve(mid + 1, R);

    double l = F[mid].AA - d, r = F[mid].AA + d;

    Q.CLR;
    for(int i = L; i <= R; i++)
    if(l <= F[i].AA && F[i].AA <= r)
    {
        Q.PB(MP(F[i].BB, F[i].AA));
    }
    sort(Q.OP, Q.ED);
    FOR(i, Q.SZ) for(int j = i + 1; j < Q.SZ; j++) if(i != j) { if(fabs(Q[i].AA - Q[j].AA) >= d) break; d = min(d, dis(Q[i], Q[j])); }
}

int main()
{
    while(true)
    {
        scanf("%d", &n);
        if(!n) break;
        double x, y;
        F.CLR;
        FOR(i, n) { scanf("%lf%lf", &x, &y); F.PB(MP(x, y)); }
        sort(F.OP, F.ED);
        d = dis(F[0], F[F.SZ - 1]);
        solve(0, n - 1);
        printf("%.2f\n", d / 2);
    }
    return 0;
}
