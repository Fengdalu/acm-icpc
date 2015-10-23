#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 10000 + 5;

LL qpow(LL x, LL y, LL MOD)
{
    LL ret = 1;
    while(y)
    {
        if(y & 1LL) ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1LL;
    }
    return ret;
}
LL a[200005];
LL b[200005];
LL adda[200005];
LL addb[200005];
int main()
{
    LL C,k1,k2,b1;
    int CAS = 0;
    while(scanf("%I64d%I64d%I64d%I64d",&C,&k1,&b1,&k2)!= EOF)
    {
        CAS++;
        for(LL i = 1; i < C; i++)
        {
            a[i] = qpow(i, k1 + b1, C);
            adda[i] = qpow(i, k1, C);
            b[i] = i;
            addb[i] = qpow(i, k2, C);
        }
//        for(int i = 1; i < C; i++)
//            printf("%2I64d ", a[i]);puts("");
//        for(int i = 1; i < C; i++)
//            printf("%2I64d ", adda[i]);puts("");
//        for(int i = 1; i < C; i++)
//            printf("%2I64d ", b[i]);puts("");
//        for(int i = 1; i < C; i++)
//            printf("%2I64d ", addb[i]);puts("");
        int b = 1;
        printf("Case #%d:\n", CAS);
        LL j;
        for(LL i = 1; i < C; i++)
        {
            //a[i] + j == C
            j = C - a[i];
            if(adda[i] == addb[j])
            {
                b = 0;
                printf("%I64d %I64d\n",i,j);
            }
        }
        if(b) puts("-1");
    }
    return 0;
}