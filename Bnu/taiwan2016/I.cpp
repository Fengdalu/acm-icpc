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

LL dpd[10][20];
LL dpu[10][20];
void init()
{
    clr(dpd, 0);
    for(int i = 0; i < 10; i++)
    {
        dpd[i][0] = 1;
    }
    for(int i = 1; i <= 17; i++)
    {
        dpd[0][i] = 1;
        for(int j = 1; j < 10; j++)
        {
            dpd[j][i] = dpd[j - 1][i] + dpd[j][i - 1];
        }
    }
    clr(dpu, 0);
    for(int i = 0; i < 10; i++)
    {
        dpu[i][0] = 1;
    }
    for(int i = 1; i <= 17; i++)
    {
        dpu[9][i] = 1;
        for(int j = 8; j >= 0; j--)
        {
            dpu[j][i] = dpu[j + 1][i] + dpu[j][i - 1];
        }
    }
}
vector<LL> v;
void initv()
{
    v.clear();
    LL up = 100000000000000000LL; // 10 ^ 17
    LL now;
    for(int i = 1; i < 10; i++)
    {
        now = i;
        v.push_back(now);
        while(now < up)
        {
            now = now * 10 + i;
            v.push_back(now);
        }
    }
}
int a[20];
int check(int l, int j, int st)
{
    if(st == 0)
    {
        for(int i = 1; i < l; i++)
        {
            if(a[i - 1] > a[i]) return 0;
        }
        if(a[l - 1] > j) return 0;
    }
    if(st == 1)
    {
        for(int i = 1; i < l; i++)
        {
            if(a[i] > a[i - 1]) return 0;
        }
        if(a[l - 1] < j) return 0;
    }
    return 1;
}
LL cal(LL x, int st)
{
    if(x < 10) return x;
    if(st == 2)
    {
        LL ret = 0;
        FOR(i,v.size())
        {
            if(v[i] <= x) ret++;
        }
        return ret;
    }
    int tot = 0;
    LL y = x;
    while(y)
    {
        a[tot++] = y % 10;
        y /= 10;
    }
    reverse(a, a + tot);
    if(st == 0)
    {
        LL ret = 0;
        for(int i = 1; i < tot; i++) for(int j = 1; j < 10; j++) ret += dpu[j][tot - i - 1];
        //printf("ret = %lld\n", ret);
        for(int j = 1; j < a[0]; j++) ret += dpu[j][tot - 1];
        for(int i = 1; i < tot; i++) for(int j = 0; j < a[i]; j++) if(check(i,j,st)) ret += dpu[j][tot - i - 1];
        if(check(tot - 1, a[tot - 1], st)) ret++;
        return ret;
    }
    if(st == 1)
    {
        LL ret = 0;
        for(int i = 1; i < tot; i++) for(int j = 1; j < 10; j++) ret += dpd[j][tot - i - 1];
        for(int j = 1; j < a[0]; j++) ret += dpd[j][tot - 1];
        for(int i = 1; i < tot; i++) for(int j = 0; j < a[i]; j++) if(check(i,j,st)) ret += dpd[j][tot - i - 1];
        if(check(tot - 1, a[tot - 1], st)) ret++;
        return ret;
    }
}
LL calc(LL x)
{
    //printf("cal 0 = %lld\n", cal(x,0));
    //printf("cal 1 = %lld\n", cal(x,1));
    //printf("cal 2 = %lld\n", cal(x,2));
    return cal(x,0) - cal(x,2) + cal(x,1);
}
int main()
{
    initv();
    LL l,r;
    init();
    LL n;
    //printf("%lld\n", dpu[8][1]);
    //while(scanf("%lld",&n) != EOF) printf("%lld\n", calc(n));
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&l,&r);
        LL ans = calc(r) - calc(l - 1);
        printf("%lld\n", ans);
    }
}
