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
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef pair<LL,LL> pll;
typedef pair<LL,int> pli;
typedef pair<int,LL> pil;

//#pragma comment(linker, "/STACK:102400000,102400000")

#define MP3(x,y,z) make_pair(make_pair(x,y),z)
#define MP make_pair
#define AA first
#define XX first.first
#define YY first.second
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
#define all(x) x.begin(),x.end()
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) {if(~x) x = std::min(x,y);else x = y;}
#define ccmax(x,y) {if(~x) x = std::max(x,y);else x = y;}
#define FOR(i,x) for(int i = 0, __END__ = (int)(x); i < __END__ ; i++)
#define FORR(i,x) for(int i = 1, __END__ = (int)(x); i <= __END__ ; i++)
#define REP(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i <= __END__; i++)
#define REP_D(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i >= __END__; i--)

const int MAXN = 100000 + 5;

LL gcd(LL a, LL b){if(b == 0) return a;return gcd(b,a%b);}
inline LL readLL()
{
    char ch;bool flag = false;LL a = 0;
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
    if(ch != '-'){a *= 10;a += ch - '0';}else{flag = true;}
    while(((ch = getchar()) >= '0') && (ch <= '9')){a *= 10;a += ch - '0';}
    if(flag)a = -a;return a;
}
inline int read()
{
    char ch;bool flag = false;int a = 0;
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
    if(ch != '-'){a *= 10;a += ch - '0';}else{flag = true;}
    while(((ch = getchar()) >= '0') && (ch <= '9')){a *= 10;a += ch - '0';}
    if(flag)a = -a;return a;
}
int a[205];
double tt[10004];
double t[10004];
double dp[205];
int main()
{
    int n;
    double v,e,f;
    int r;
    double b;
    while(scanf("%d",&n),n)
    {
        a[0] = 0;
        FORR(i,n) scanf("%d",&a[i]);
        scanf("%lf",&b);
        scanf("%d",&r);
        scanf("%lf%lf%lf",&v,&e,&f);
        FOR(x,r)
        {
            tt[x + 1] = 1.0/(v - f * (r - x));
            //printf("%d %.10lf\n", x + 1, tt[x + 1]);
        }
        //puts("hi");
        REP(x,r,a[n] - 1)
        {
            //printf("%.10lf\n", v - e * (x - r));
            tt[x + 1] = 1.0/(v - e * (x - r));
            //printf("%d %.10lf\n", x + 1, tt[x + 1]);
        }
        t[0] = 0;
        FORR(i,a[n]) t[i] = t[i - 1] + tt[i];
        clr(dp, 0);
        dp[0] = 0;
        FORR(i,n)
        {
            dp[i] = t[a[i]];
            FOR(j,i)
                dp[i] = min(dp[i], dp[j] + t[a[i] - a[j]] + b);
        }
        printf("%.10lf\n", dp[n]);
    }
    return 0;
}
