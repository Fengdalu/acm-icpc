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

LL a[40];
LL b[40];
LL solve(LL d,int s1,int s2)
{
    LL now;
    int p;
    int l,r;
    for(int i = 0; i <=33; i++)
    {
        now = d;
        now += a[i];
        now &= b[i];
        l = __builtin_popcount(now);
        r = l + i + 1;
//        cout << "now = " << now << endl;
//        cout << "l = " << l << endl;
//        cout << "r = " << r << endl;
        if(max(l,s1) <= min(s2,r))
        {
            p = max(l,s1) - l;
            for(int j = 0; j < p; j++)
                now |= a[j];
            return now;
        }
    }
}
int main()
{

    a[0] = 1;
    for(int i = 1; i <= 35; i++)
        a[i] = a[i - 1] * 2;
    clr(b,0);
    for(int i = 0; i <= 35; i++)
    {
        for(int j = i; j <=35; j++)
            b[i] |= a[j];
    }
    int _T;
    LL d;
    int s1,s2;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        LL ans = 0;
        scanf("%I64d%d%d",&d,&s1,&s2);
        ans = solve(d,s1,s2);
        printf("Case #%d: %I64d\n",CAS,ans);
    }
    return 0;
}