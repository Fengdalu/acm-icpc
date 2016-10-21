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
const int N = 200005;
int vis[N];
int a[N];
int b[N];
int c[N];
int x[N];
int y[N];
int main()
{
    int n;
    scanf("%d",&n);
    FOR(i,n) scanf("%d", &a[i]);
    FOR(i,n) scanf("%d", &b[i]);
    FOR(i,n) c[i] = vis[i] = 0;
    FOR(i,n) x[a[i]] = i;
    FOR(i,n) y[b[i]] = i;
    int left = n;
    int m = n - 1;
    int p;
    for(int now = 2 * m; now >= m; now--)
    {
        for(int i = m,j = now - m; ~i && j < n; i--,j++)
        {
            p = x[i] + y[j];
            if(p > m) p -= n;
            if(c[p] == 0) left--, c[p] = now;
        }
        if(left < 100)
        {
            FOR(i,n) if(c[i] == 0)
            {
                FOR(j,n)
                {
                    int k = i - j;
                    if(k < 0) k += n;
                    if(a[j] + b[k] > c[i]) c[i] = a[j] + b[k];
                }
            }
            FOR(i,n)
            {
                if(i) printf(" ");
                printf("%d",c[i]);
            }
            puts("");
            return 0;
        }
    }
            FOR(i,n)
            {
                if(i) printf(" ");
                printf("%d",c[i]);
            }
            puts("");
    return 0;
}
