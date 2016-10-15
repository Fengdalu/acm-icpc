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
const int N = 100005;
int a[N];
set<int> S[20];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    FORR(i,n) scanf("%d",&a[i]);
    a[0] = a[n + 1] = 0;
    REP(i, 0, n + 1)
    {
        FOR(j,20) if(((a[i] >> j) & 1) == 0)
        {
            S[j].insert(i);
        }
    }
    int l,r;
    long long ans = 0;
    set<int>::iterator it;
    FORR(i,n) FOR(j,20) if((a[i] >> j) & 1)
    {
        it = S[j].lower_bound(i);
        r = *it;
        l = i;
        ans += (1LL << j) * (r - l);
    }
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        long long now = 0;
        long long p;
        long long ll;
        long long rr;
        FOR(j,20) if((a[x] >> j) & 1)
        {
            it = S[j].lower_bound(x);
            r = *it;
            --it;
            l = *it;
            p = r - l - 1;
            ll = x - l - 1;
            rr = r - x - 1;
            now += (1LL<<j)*(r-x)*(x-l);//(1LL << j) * (p * (p - 1) / 2) + (1LL << j) * (1 + rr)- ll * (ll - 1) / 2 - rr * (rr - 1) / 2;
        }
        FOR(j,20) if(((a[x] >> j) & 1) == 0)
        {
            S[j].erase(S[j].find(x));
        }
        ans -= now;
        now = 0;
        a[x] = y;
        FOR(j,20) if((a[x] >> j) & 1)
        {
            it = S[j].lower_bound(x);
            r = *it;
            --it;
            l = *it;
            p = r - l - 1;
            ll = x - l - 1;
            rr = r - x - 1;
            now += (1LL<<j)*(r-x)*(x-l);
        }
        FOR(j,20) if(((a[x] >> j) & 1) == 0)
        {
            S[j].insert(x);
        }
        ans += now;
        printf("%I64d\n", ans);
    }
    return 0;
}
