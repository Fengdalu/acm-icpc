#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define PII pair<LL, LL>
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define PI acos(-1.0)
#define OP begin()
#define ED end()
#define SZ size()
typedef pair< PII, int > obj;
vector<obj>Q;
int n;

long double sqr(LL x) { return x * x; }

long double angle(PII x)
{
    long double t =  atan2(x.BB, x.AA);
    if(t < 0) t += 2 * PI;
    return t;
}

int cmp(obj a, obj b)
{
    return angle(a.AA) < angle(b.AA);
}

int main()
{
    scanf("%d", &n);
    Q.clear();
    for(int i = 0; i < n; i++) { LL x, y; scanf("%I64d%I64d", &x, &y); Q.PB(MP(PII(x, y), i)); }
    sort(Q.OP, Q.ED, cmp);
    int j = 1;
    Q.PB(Q[0]);
    for(int i = 1; i < Q.SZ; i++)
    {
        long double t1 = angle(Q[j].AA) - angle(Q[j - 1].AA); if(t1 < 0) t1 += 2 * PI;
        long double t2 = angle(Q[i].AA) - angle(Q[i - 1].AA); if(t2 < 0) t2 += 2 * PI;
        if( t1 > t2 ) j = i;
    }
    printf("%d %d\n", Q[j].BB + 1, Q[j - 1].BB + 1);
}
