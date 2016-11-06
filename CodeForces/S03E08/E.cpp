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
const int MAX_ST = 6 * 5 * 5 * 4 * 4 * 3 * 3 * 2 * 2 * 6;
struct node
{
    int flag;
    double w;
    double l,r;
}a[MAX_ST];
double r;
int n;
int totq;
int tota;
double ans;
int q[10];
int dbg_t = 0;
int uni(int i, int j)
{
    a[tota].flag = 1;
    a[tota].w = a[i].w + a[j].w;
    double ll = a[j].w / a[tota].w;
    double rr = a[i].w / a[tota].w;
    a[tota].l = max(ll + a[i].l, a[j].l - rr);
    a[tota].r = max(rr + a[j].r, a[i].r - ll);
    //if(dbg_t < 20)
    //    printf("uni %lf %lf %lf , %lf %lf %lf = %lf %lf %lf\n", a[i].w, a[i].l, a[i].r, a[j].w, a[j].l, a[j].r, a[tota].w, a[tota].l, a[tota].r);
    tota++;
    return tota - 1;
    /*
    if(!a[i].flag && !a[j].flag)
    {
        tota++;
        return tota - 1;
    }
    if(a[i].flag && a[j].flag)
    {
        a[tota].l = max(a[tota].l, a[tota])
    }
    */
}
inline void del(int x)
{
    int ii = -1;
    FOR(i,totq) if(x == q[i]) ii = i;
    if(~ii)
    {
        REP(i,ii,totq - 1) q[i] = q[i + 1];
        totq--;
    }
    else exit(-1);
}
double dinf;
void dfs()
{
    if(totq == 1)
    {
        double now = a[q[0]].l + a[q[0]].r;
        //if(now < r)
            //printf("now = %.10lf\n", now);
        if(now < r)
        {
            if(ans == dinf) ans = now;
            else if(now > ans) ans = now;
        }
        return;
    }
        sort(q,q + totq);
    FOR(i,totq) FOR(j,totq) if(i != j)
    {
        sort(q,q + totq);
        int z = uni(q[i], q[j]);
        int x = q[i];
        int y = q[j];
        q[totq++] = z;
        del(x);
        del(y);
        sort(q,q + totq);
        dfs();
        del(z);
        q[totq++] = x;
        q[totq++] = y;
        sort(q,q + totq);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        dbg_t = 0;
        scanf("%lf",&r);
        scanf("%d",&n);
        double x;
        tota = totq = 0;
        FOR(i,n)
        {
            scanf("%lf",&x);
            a[tota].w = x;
            a[tota].flag = 0;
            a[tota].l = 0;
            a[tota].r = 0;
            q[totq] = tota;
            tota++;
            totq++;
        }
        dinf = r + 1;
        ans = dinf;
        dfs();
        if(n == 0) ans = 0;
        if(ans == dinf) puts("-1");
        else printf("%.10lf\n", ans);
    }
    return 0;
}
