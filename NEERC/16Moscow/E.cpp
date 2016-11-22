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
const int N = 200000 + 10;
const int d = 3;
const int MID = 1;
const int ED = 1;
const int MC = 1;
const int MO = 2;
const int ME = 4;
const int preMID = 0;
int dp[N][8];
int from[N][8];
void upd(int i, int st, int v, int f)
{
    if(dp[i][st] == 0)
    {
        dp[i][st] = v;
        from[i][st] = f;
    }
    else
    {
        if(dp[i][st] > v)
        {
            dp[i][st] = v;
            from[i][st] = f;
        }
    }
}
int a[N];
int b[N];
int getnum(int x)
{
    int ret = 0;
    while(x)
    {
        x /= 10;
        ret++;
    }
    return ret;
}
int flag;
void putnum(int);void putnum(int,int,int);
inline void dot()
{
    if(flag) printf(",");
    else flag = 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    FOR(i,n)
    {
        scanf("%d",&a[d + i]);
    }
    sort(a + d, a + d + n);
    FOR(i,n)
    {
        b[i + d] = getnum(a[i + d]);
    }
    a[0] = -99; a[1] = -88; a[2] = -77;
    clr(dp, 0);
    int s,v;
    dp[d - 1][0] = 1;
    int pc,pe,po;
    FOR(ii,n)
    {
        int i = ii + d;
        FOR(st, 8) if(dp[i - 1][st])
        {
            ///init;
            v = dp[i - 1][st];
            s = st;
            po = 0;
            pe = 0;
            pc = 0;
            if(s & MC) pc = i - 1;
            if(s & MO) {po = i - 1; if(!(a[i - 1] & 1)) po = i - 2;}
            if(s & ME) {pe = i - 1; if(a[i - 1] & 1) pe = i - 2;}
            //dan
            v = dp[i - 1][st];
            s = st;
            if(s & MC) {v += MID + b[i - 1] + ED; s ^= MC;}
            if(pe == i - 2) {v += MID + b[i - 2] + ED; s ^= ME;}
            if(po == i - 2) {v += MID + b[i - 2] + ED; s ^= MO;}
            if(pe == i - 1 && a[i] - a[i - 1] > 1) {v += MID + b[i - 1] + ED; s ^= ME;}
            if(po == i - 1 && a[i] - a[i - 1] > 1) {v += MID + b[i - 1] + ED; s ^= MO;}
            v += b[i] + ED;
            upd(i,s,v,st);

            //st c
            v = dp[i - 1][st];
            s = st;
            if(s & MC) {v += MID + b[i - 1] + ED; s ^= MC;}
            if(pe == i - 2) {v += MID + b[i - 2] + ED; s ^= ME;}
            if(po == i - 2) {v += MID + b[i - 2] + ED; s ^= MO;}
            if(pe == i - 1) {v += MID + b[i - 1] + ED; s ^= ME;}
            if(po == i - 1) {v += MID + b[i - 1] + ED; s ^= MO;}
            v += b[i] + preMID;
            s ^= MC;
            upd(i,s,v,st);

            //st o
            if(a[i] & 1)
            {
                v = dp[i - 1][st];
                s = st;
                if(s & MC) {v += MID + b[i - 1] + ED; s ^= MC;}
                if(pe == i - 2) {v += MID + b[i - 2] + ED; s ^= ME;}
                if(po == i - 2) {v += MID + b[i - 2] + ED; s ^= MO;}
                if(pe == i - 1 && a[i] - a[i - 1] > 1) {v += MID + b[i - 1] + ED; s ^= ME;}
                if(po == i - 1) {v += MID + b[i - 1] + ED; s ^= MO;}
                v += b[i] + preMID;
                s ^= MO;
                upd(i,s,v,st);
            }
            //st e
            else
            {
                v = dp[i - 1][st];
                s = st;
                if(s & MC) {v += MID + b[i - 1] + ED; s ^= MC;}
                if(pe == i - 2) {v += MID + b[i - 2] + ED; s ^= ME;}
                if(po == i - 2) {v += MID + b[i - 2] + ED; s ^= MO;}
                if(pe == i - 1) {v += MID + b[i - 1] + ED; s ^= ME;}
                if(po == i - 1 && a[i] - a[i - 1] > 1) {v += MID + b[i - 1] + ED; s ^= MO;}
                v += b[i] + preMID;
                s ^= ME;
                upd(i,s,v,st);
            }

            //continue c
            if(st & MC) if(a[i] - a[i - 1] == 1)
            {
                v = dp[i - 1][st];
                s = st;
                if(pe == i - 2) {v += MID + b[i - 2] + ED; s ^= ME;}
                if(po == i - 2) {v += MID + b[i - 2] + ED; s ^= MO;}
                if(pe == i - 1) {v += MID + b[i - 1] + ED; s ^= ME;}
                if(po == i - 1) {v += MID + b[i - 1] + ED; s ^= MO;}
                upd(i,s,v,st);
            }
            if(st & ME) if(a[i] - a[pe] == 2)
            {
                if(pe == i - 2)
                {
                    v = dp[i - 1][st];
                    s = st;
                    if(s & MC) {v += MID + b[i - 1] + ED; s ^= MC;}
                    upd(i,s,v,st);
                }
                else
                {
                    v = dp[i - 1][st];
                    s = st;
                    if(po) {v += MID + b[po] + ED; s ^= MO;}
                    upd(i,s,v,st);
                }
            }
            if(st & MO) if(a[i] - a[po] == 2)
            {
                if(po == i - 2)
                {
                    v = dp[i - 1][st];
                    s = st;
                    upd(i,s,v,st);
                }
                else
                {
                    v = dp[i - 1][st];
                    s = st;
                    if(pe) {v += MID + b[pe] + ED; s ^= ME;}
                    upd(i,s,v,st);
                }
            }
        }
    }
    FOR(st,8)
    {
        int i = n + d;
        if(dp[i - 1][st] == 0) continue;
        v = dp[i - 1][st];
        s = st;
            po = 0;
            pe = 0;
            pc = 0;
            if(s & MC) pc = i - 1;
            if(s & MO) {po = i - 1; if(!(a[i - 1] & 1)) po = i - 2;}
            if(s & ME) {pe = i - 1; if(a[i - 1] & 1) pe = i - 2;}

            if(s & MC) {v += MID + b[i - 1] + ED; s ^= MC;}
            if(pe == i - 2) {v += MID + b[i - 2] + ED; s ^= ME;}
            if(po == i - 2) {v += MID + b[i - 2] + ED; s ^= MO;}
            if(pe == i - 1) {v += MID + b[i - 1] + ED; s ^= ME;}
            if(po == i - 1) {v += MID + b[i - 1] + ED; s ^= MO;}
        upd(i, 0, v, st);
    }
    //printf("l = %d\n", dp[n + d][0]);
    s = 0;
    int i = n + d;
    flag = 0;
    int edo = 0;
    int edc = 0;
    int ede = 0;
    int bgo = 0;
    int bge = 0;
    int bgc = 0;
    s = from[i][s];
    i--;
    while(i != 0 + d - 1)
    {
        if(s == 0) putnum(a[i]);
        if(s & MC)
        {
            if(edc == 0) edc = bgc = a[i];
            else
            {
                if(a[i] - bgc == -1)
                {
                    bgc = a[i];
                }
                else
            {
                    putnum(bgc, edc, MC);
                    edc = bgc = a[i];
                }
            }
        }
        if(s & MO) if(a[i] & 1)
        {
            if(edo == 0) edo = bgo = a[i];
            else
            {
                if(a[i] - bgo == -2)
                {
                    bgo = a[i];
                }
                else
                {
                    putnum(bgo, edo, MO);
                    edo = bgo = a[i];
                }
            }
        }
        if(s & ME) if(!(a[i] & 1))
        {
            if(ede == 0) ede = bge = a[i];
            else
            {
                if(a[i] - bge == -2)
                {
                    bge = a[i];
                }
                else
                {
                    putnum(bge, ede, ME);
                    ede = bge = a[i];
                }
            }
        }
        if((s & MO) && !(s & ME) && !(s & MC) && !(a[i] & 1)) putnum(a[i]);
        if((s & ME) && !(s & MO) && !(s & MC) && (a[i] & 1)) putnum(a[i]);
        s = from[i][s];
        i--;
    }
    if(edo) putnum(bgo,edo,MO);
    if(edc) putnum(bgc,edc,MC);
    if(ede) putnum(bge,ede,ME);
    puts("");
    return 0;
}

void putnum(int x)
{
    dot();
    printf("%d",x);
}

void putnum(int bg, int ed, int st)
{
    dot();
    printf("%d", bg);
    if(st == MC) printf("-");
    if(st == MO) printf("#");
    if(st == ME) printf("%%");
    printf("%d", ed);
}
